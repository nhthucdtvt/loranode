#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "InitDevice.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// different commands to set the update rate from once a second (1 Hz) to 10 times a second (10Hz)
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"
#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"

// turn on only the second sentence (GPRMC)
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
// turn on ALL THE DATA
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28"

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
float Lat;     /*!< vi do */
float Lng;     /*!< kinh do */
float SpeedGPS;     /*!< Toc do GPS */
float OrGPS;      /*!< Huong GPS 360 do */

char dataToString[50];
char floatToString[15];
int counter = 0;
unsigned char dataGpsInput[128];
char output[50];
char float_str[10];

static volatile uint32_t msTicks; /* counts 1ms timeTicks */

void SysTick_Handler(void)
{
  msTicks++;       /* increment counter necessary in Delay()*/
}

static void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}
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
int main(void)
{
  /* Chip errata */
	CHIP_Init();
	enter_DefaultMode_from_RESET();
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
		while (1) ;
	}

	GPIO_PinOutClear(LORA_EN_PORT,LORA_EN_PIN);
	GPIO_PinOutClear(GPS_EN_PORT,GPS_EN_PIN);
	send_string(LEUART0, PMTK_SET_NMEA_OUTPUT_RMCONLY);
  /* Infinite loop */
  while (1) {
	  if (State_gps == true) {
	    GPIO_PinOutSet(LED1_PORT,LED1_PIN);
	  	Delay(500);
	  	GPIO_PinOutClear(LED1_PORT,LED1_PIN);
	  	Delay(500);
	  }
  }
}
