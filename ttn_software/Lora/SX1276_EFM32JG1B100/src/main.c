#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_cryotimer.h"
#include "config.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "../lmic-master/src/lmic/lmic.h"
#include "../lmic-master/src/lmic/hal.h"
#include "delay.h"
#include "i2c-MMA8652.h"


extern bool Motion_detect;
bool timeUp = 0;
uint16_t adcRead;
float inputVol;
uint8_t i2cread;
uint8_t interruptStatus;
uint16_t gpsTimeOut = 0;

uint8_t mydata[] = "Hello, khiemtt!";
osjob_t sendjob;
// different commands to set the update rate from once a second (1 Hz) to 10 times a second (10Hz)
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"
#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"

// turn on only the second sentence (GPRMC)
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
// turn on ALL THE DATA
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"
// turn GPS to "warm start"
#define PMTK_CMD_WARM_START "$PMTK102*31\r\n"
// turn GPS to "hot start"
#define PMTK_CMD_HOT_START "$PMTK101*32\r\n"
// GPRMC
#define GPRMC_MID         0
#define GPRMC_UTC         1
#define GPRMC_STS         2
#define GPRMC_LAT         3
#define GPRMC_LAT_NS      4
#define GPRMC_LON         5
#define GPRMC_LON_EW      6
#define GPRMC_SOG         7
#define GPRMC_COG         8
#define GPRMC_DAT         9
#define GPRMC_MAV         10
#define GPRMC_MAV_EW      11
#define GPRMC_MOD         12
// to generate your own sentences, check out the MTK command datasheet and use a checksum calculator
// such as the awesome http://www.hhhh.org/wiml/proj/nmeaxor.html

unsigned char year;
unsigned char month;
unsigned char date;
unsigned char hour;
unsigned char minute;
unsigned char sec;

unsigned long time_update;


int DISPLAY_GPS = 0;
int DISPLAY_RTC = 1;
int DISPLAY_SPEED_ORG = 2;
int DISPLAY_MAX = 3;

bool State_gps;     /*!< trang thai gps 1 = co tin hieu, 0 = mat tin hieu */
float Lat = 0.0;     /*!< vi do */
float Lng = 0.0;     /*!< kinh do */
float SpeedGPS;     /*!< Toc do GPS */
float OrGPS;      /*!< Huong GPS 360 do */

char dataToString[50];
char floatToString[15];
int counter = 0;
unsigned char dataGpsInput[128];
char output[50];
char float_str[10];
//////////////////////////////////////////////////
// CONFIGURATION (FOR APPLICATION CALLBACKS BELOW)
//////////////////////////////////////////////////

// application router ID (LSBF)
//static const u1_t APPEUI[8]  = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x00, 0x85, 0x06 };//0x02, 0x00, 0x00, 0x00, 0x00, 0xEE, 0xFF, 0xC0 };

// unique device ID (LSBF)
//static const u1_t DEVEUI[8]  = { 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34, 0x56 };//0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF };

// device-specific AES key (derived from device EUI)
//static const u1_t DEVKEY[16] = { 0xE7, 0x63, 0x2E, 0x1C, 0xF3, 0x61, 0x7E, 0xAD, 0xF5, 0xC0, 0xBC, 0x7E, 0x38, 0xEA, 0x09, 0xA8  };


static const u1_t nwkKey[16] = { 0xF7, 0xFF, 0x3C, 0xFD, 0x79, 0xCC, 0xEC, 0x65, 0x66, 0x99, 0x2F, 0xC9, 0x7C, 0xF7, 0x3D, 0x61 };

static const u1_t artKey[16] = { 0xB6, 0x0F, 0x39, 0xB3, 0xB3, 0xBA, 0xDF, 0x8C, 0x6A, 0x4B, 0x9B, 0x16, 0xAE, 0x20, 0xA4, 0x3C };

static const u4_t devAdr = 0x26011CA7;

/*
static const u1_t nwkKey[16] = { 0x47, 0x79, 0x4F, 0x71, 0x66, 0x25, 0x1E, 0xFE, 0x18, 0x95, 0xC3, 0xD3, 0x35, 0x66, 0x85, 0xBA };

static const u1_t artKey[16] = { 0xE3, 0x9A, 0x4E, 0x19, 0x4A, 0x2F, 0x3C, 0xC4, 0x7E, 0x34, 0x45, 0x25, 0x86, 0x37, 0xB9, 0xC3 };

static const u4_t devAdr = 0x26011ECD;*/

void send_string(LEUART_TypeDef *leuart, char * string)
{
      while (*string != 0)
      {
    	  LEUART_Tx(leuart, *string++);
      }
}
void LEUART0_IRQHandler()
{
	if (LEUART0->IF & LEUART_IF_RXDATAV)
	  {
		char receiveData = LEUART_Rx(LEUART0);
		dataGpsInput[counter] = (unsigned char)receiveData;
		counter++;
		if(receiveData == '\n') {
		  for ( int i = 0; i < counter-1; i++) {
			dataGpsInput[i] = dataGpsInput[i+1];
		  }
		  NMEA_GPRMC_Decoder(dataGpsInput);
		  counter = 0;
		}
	  }
}
static float gps_convert_lat_to_float(unsigned char *lat_str, unsigned char *NS)
{
  unsigned char hours[2+1];
  unsigned char minutes[8+1];
  float ret;

  memset(hours,0,sizeof(hours));
  memset(minutes,0,sizeof(minutes));

  strncpy( hours, lat_str, 2 );
  strncpy( minutes, lat_str + 2 , strlen(lat_str) - 2 );

  ret = atof(hours);
  ret += atof(minutes)/60;
  if(strcmp(NS, "S") == 0)
  {
    return -ret;
  }
    return ret;
}
static float gps_convert_lon_to_float(unsigned char *lon_str, unsigned char *WE)
{
  unsigned char hours[3+1];
  unsigned char minutes[8+1];
  float ret;

  memset(hours,0,sizeof(hours));
  memset(minutes,0,sizeof(minutes));

  strncpy( hours, lon_str, 3 );
  strncpy( minutes, lon_str + 3 , strlen(lon_str) - 3 );

  ret = atof(hours);
  ret += atof(minutes)/60;
  if(strcmp(WE, "W") == 0)
  {
    return -ret;
  }
    return ret;
}
static int GetMessageFeilds(unsigned char **message_feildls, unsigned char *msg, unsigned char separate_char, int max_feild_get)
{
  int count_feild = 0;
  *message_feildls = msg;
  message_feildls++;
  count_feild++;
  while(*msg !=NULL)
  {
    if(*msg == separate_char)
    {
      *msg = NULL;
      *message_feildls = msg + 1;
      message_feildls++;
      count_feild++;
      if(count_feild >= max_feild_get)
        return count_feild;
    }
    msg++;
  }
  return count_feild;
}
void NMEA_GPRMC_Decoder(unsigned char *dataInput)
{
  unsigned long time_template;
  unsigned char hour_template, minute_template, second_template, date_template, month_template, year_template;
  char *message_field[13];
  if(GetMessageFeilds(message_field, dataInput, ',', 13) == 13)
  {

      if(strcmp(message_field[GPRMC_MID], "GPRMC") != 0)
      {
        return;
      }
      if( strcmp(message_field[GPRMC_STS],"A") == 0)
      {
        State_gps = true;

        SpeedGPS = atof(message_field[GPRMC_SOG]) * 1.852;
        OrGPS = atof(message_field[GPRMC_COG]);
        Lat = gps_convert_lat_to_float(message_field[GPRMC_LAT], message_field[GPRMC_LAT_NS]);
        Lng = gps_convert_lon_to_float(message_field[GPRMC_LON], message_field[GPRMC_LON_EW]);
      }
      else if( strcmp(message_field[GPRMC_STS],"V") == 0)
      {
        State_gps = false;
        Lat = 0;
        Lng = 0;
        SpeedGPS = 0;

      }
      *(message_field[GPRMC_UTC] + 6) = '\0';

      time_template = atof(message_field[GPRMC_UTC]);

      hour_template = (unsigned char)(time_template / 10000);
      minute_template = (unsigned char)((time_template % 10000) / 100);
      second_template = (unsigned char)(((time_template % 10000) % 100));

      time_template = atof(message_field[GPRMC_DAT]);
      date_template = (unsigned char)(time_template / 10000);
      month_template = (unsigned char)((time_template % 10000) / 100);
      year_template = (unsigned char)(((time_template % 10000) % 100));


      year = year_template ;
      month = month_template;
      date = date_template;
      hour = hour_template;
      minute = minute_template;
      sec = second_template;
  }
}
void ftoa(char *output, float inputNumber)
{
	 int intOfFloat = (int)inputNumber;
	 int remainOfFloat = (inputNumber-intOfFloat)*1000000;
	 sprintf(output,"%d.%d", intOfFloat, remainOfFloat );
}
///////////End Of GPS Library////////////////////




//////////////////////////////////////////////////
// APPLICATION CALLBACKS
//////////////////////////////////////////////////

// provide application router ID (8 bytes, LSBF)
void os_getArtEui (u1_t* buf) {
  //  memcpy(buf, APPEUI, 8);
}

// provide device ID (8 bytes, LSBF)
void os_getDevEui (u1_t* buf) {
 //   memcpy(buf, DEVEUI, 8);
}

// provide device key (16 bytes)
void os_getDevKey (u1_t* buf) {
  //  memcpy(buf, DEVKEY, 16);
}

//////////////////////////////////////////////////
// LMIC EVENT CALLBACK
//////////////////////////////////////////////////
void do_send(osjob_t* j)
{
	os_init();

	LMIC_reset();

	LMIC_setSession (0x1, devAdr, nwkKey, artKey);

	for (int i = 1; i <= 8; i++) {
		LMIC_disableChannel(i);
	}
	// Disable link check validation
    LMIC_setLinkCheckMode(0);

    // TTN uses SF9 for its RX2 window.
    LMIC.dn2Dr = DR_SF9;

    // Set data rate and transmit power for uplink (note: txpow seems to be ignored by the library)
    LMIC_setDrTxpow(DR_SF9,14);
    // Check if there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND) {
    } else {
        // Prepare upstream data transmission at the next possible time.
        LMIC_setTxData2(1, mydata, sizeof(mydata)-1, 0);
    }
    // Next TX is scheduled after TX_COMPLETE event.
}

void onEvent (ev_t ev)
{

    switch(ev)
    {

    		case EV_SCAN_TIMEOUT:
                break;
            case EV_BEACON_FOUND:
                break;
            case EV_BEACON_MISSED:
                break;
            case EV_BEACON_TRACKED:
                break;
            case EV_JOINING:
                break;
            case EV_JOINED:
                break;
            case EV_RFU1:
                break;
            case EV_JOIN_FAILED:
                break;
            case EV_REJOIN_FAILED:
                break;
            case EV_TXCOMPLETE:
               // if (LMIC.txrxFlags & TXRX_ACK)
                //if (LMIC.dataLen) {
                //}
                // Schedule next transmission
                //os_setTimedCallback(&sendjob, os_getTime()+sec2osticks(20), do_send);
                //LMIC_setTxData2(1, mydata, sizeof(mydata)-1, 0);
                break;
            case EV_LOST_TSYNC:
                break;
            case EV_RESET:
                break;
            case EV_RXCOMPLETE:
                break;
            case EV_LINK_DEAD:
                break;
            case EV_LINK_ALIVE:
                break;
             default:
                break;
    }
}

void CRYOTIMER_IRQHandler(void)
{
	// Clear the CRYOTIMER interrupt
	CRYOTIMER_IntClear(CRYOTIMER_IF_PERIOD);

  /*
   * Flush instructions to make sure the interrupt is not re-triggered.
   * This is generally required when the peripheral clock is slower than
   * the CPU core clock.
   */
  __DSB();
}

//////////////////////////////////////////////////
// MAIN - INITIALIZATION AND STARTUP
//////////////////////////////////////////////////

int main (void)
{
    CHIP_Init();
    initDelay();
    init_function();

	GPIO_PinOutClear(GPS_EN_PORT,GPS_EN_PIN); ///turn on GPS
	send_string(LEUART0, PMTK_SET_NMEA_OUTPUT_RMCONLY);
	send_string(LEUART0, PMTK_CMD_HOT_START);

    enableFreeFallInt(20);
    clearFlagFreeFallInt();

    GPIO_PinOutSet(LED1_PORT,LED1_PIN);
	delayMs(500);
	GPIO_PinOutClear(LED1_PORT,LED1_PIN);
	delayMs(500);

    delayMs(2000);
//    while(1)
//    {
    	i2cread = whoAmI();
    	adcRead = AdcReadChannel();
    	inputVol = ((float)adcRead / 4096) * 2.5 * 2.0;
    	interruptStatus = MMA8652_RegisterGet(MMA8652_INT_SOURCE);

		while(State_gps == false) {
			delayMs(2000);
			gpsTimeOut++;
			if(State_gps == true) {
				GPIO_PinOutClear(LORA_EN_PORT,LORA_EN_PIN);
				memset(mydata,0,sizeof(mydata));
				char str[10];
				char str1[10];
				ftoa(str, Lat);
				ftoa(str1, Lng);
				sprintf(mydata, "%s, %s", str, str1);
				do_send(&sendjob);
				GPIO_PinOutSet(LORA_EN_PORT,LORA_EN_PIN);
				break;
			}
			////////////TIMEOUT GPS - 4s /////////////
			if(gpsTimeOut >= 2) {
				GPIO_PinOutClear(LORA_EN_PORT,LORA_EN_PIN);
				memset(mydata,0,sizeof(mydata));
				char str[10];
				ftoa(str, inputVol);
				sprintf(mydata, "Bat: %s", str);
				do_send(&sendjob);
				GPIO_PinOutSet(LORA_EN_PORT,LORA_EN_PIN);
				break; //set timeout = 15p = 450
			}
		}

		GPIO_PinOutSet(LED1_PORT,LED1_PIN);
		delayMs(1500);
		GPIO_PinOutClear(LED1_PORT,LED1_PIN);
		delayMs(1500);
		clearFlagFreeFallInt();
    	EMU_EnterEM4();
//    }
}

