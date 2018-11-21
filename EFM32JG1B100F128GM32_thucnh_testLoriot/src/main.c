// Standard C libraries

#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Comissioning_mydev.h"
#include "board.h"
#include "LoRaMac.h"
#include "region/Region.h"
#include "region/RegionEU868.h"
#include "MCUInit.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_cryotimer.h"
#include "em_leuart.h"
#include "sx1276.h"
#include "LoRaMacTest.h"
#include "delay.h"
#include "Gps.h"
#include "EepromData.h"

#define GPS_EN_PIN          (10)
#define GPS_EN_PORT         (gpioPortD)
#define LORA_EN_PIN         (11)
#define LORA_EN_PORT        (gpioPortD)

bool a = false;
bool gpsStatus;     /*!< trang thai gps 1 = co tin hieu, 0 = mat tin hieu */
float Lat = 0.0;     /*!< vi do */
float Lng = 0.0;     /*!< kinh do */
float Att = 0.0;	/*!< do cao */
float SpeedGPS;     /*!< Toc do GPS GPRMC*/
float OrGPS;      /*!< Huong GPS 360 do GPRMC*/
int timeoutGps = 0;
unsigned char year;
unsigned char month;
unsigned char date;
unsigned char hour;
unsigned char minute;
unsigned char sec;

int numberOfJoin = 0;
int counter = 0;
unsigned char dataGpsInput[128];
//unsigned char dataGpsTest[128] = "GPGGA,170834,4124.8963,N,08151.6838,W,1,05,1.5,-280.2,M,-34.0,M,,,*59";
uint16_t adcRead;
float inputVol;
uint8_t i2cread;
uint8_t interruptStatus;
int sendSuccess = 0;
uint8_t currentChannel = 0;
int multiSend = 0;

extern ChannelParams_t Channels[EU868_MAX_NB_CHANNELS];
extern uint8_t LoRaMacNwkSKey[];
extern uint8_t LoRaMacAppSKey[];
extern uint16_t LoRaMacDevNonce;
extern uint32_t LoRaMacNetID;
extern uint32_t LoRaMacDevAddr;
extern uint32_t UpLinkCounter;
extern uint32_t DownLinkCounter;
extern uint8_t Channel; // current channel after join success

/*!
 * Defines the application data transmission duty cycle. 5s, value in [ms].
 */
//#define APP_TX_DUTYCYCLE                            15000

/*!
 * Defines a random delay for application data transmission duty cycle. 1s,
 * value in [ms].
 */
#define APP_TX_DUTYCYCLE_RND                        1000

/*!
 * Default datarate
 */
#define LORAWAN_DEFAULT_DATARATE                    DR_0

/*!
 * LoRaWAN confirmed messages
 */
#define LORAWAN_CONFIRMED_MSG_ON                    false

/*!
 * LoRaWAN Adaptive Data Rate
 *
 * \remark Please note that when ADR is enabled the end-device should be static
 */
#define LORAWAN_ADR_ON 0

/*!
 * LoRaWAN ETSI duty cycle control enable/disable
 *
 * \remark Please note that ETSI mandates duty cycled transmissions. Use only for test purposes
 */
#define LORAWAN_DUTYCYCLE_ON                        false

#define USE_SEMTECH_DEFAULT_CHANNEL_LINEUP          1

#if( USE_SEMTECH_DEFAULT_CHANNEL_LINEUP == 1 )
#define LC0                { 868100000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }
#define LC1                { 868300000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }
#define LC2                { 868500000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }
#define LC3                { 866100000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }
#define LC4                { 866300000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }
#define LC5                { 866500000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }
#define LC6                { 866700000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }
#define LC7                { 866900000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }

#endif

/*!
 * LoRaWAN application port
 */
#define LORAWAN_APP_PORT                            1

/*!
 * User application data buffer size
 */
#define LORAWAN_APP_DATA_SIZE                       20

static uint8_t DevEui[] = LORAWAN_DEVICE_EUI;
static uint8_t AppEui[] = LORAWAN_APPLICATION_EUI;
static uint8_t AppKey[] = LORAWAN_APPLICATION_KEY;

#if( OVER_THE_AIR_ACTIVATION == 0 )

static uint8_t NwkSKey[] = LORAWAN_NWKSKEY;
static uint8_t AppSKey[] = LORAWAN_APPSKEY;

/*!
 * Device address
 */
static uint32_t DevAddr = LORAWAN_DEVICE_ADDRESS;

#endif

/*!
 * Application port
 */
static uint8_t AppPort = LORAWAN_APP_PORT;

/*!
 * User application data size
 */
static uint8_t AppDataSize = LORAWAN_APP_DATA_SIZE;

/*!
 * User application data buffer size
 */
#define LORAWAN_APP_DATA_MAX_SIZE                           242

/*!
 * User application data
 */
static uint8_t AppData[] = "hello world!";

/*!
 * Indicates if the node is sending confirmed or unconfirmed messages
 */
static uint8_t IsTxConfirmed = LORAWAN_CONFIRMED_MSG_ON;

/*!
 * Defines the application data transmission duty cycle
 */
static uint32_t TxDutyCycleTime;

/*!
 * Timer to handle the application data transmission duty cycle
 */
static TimerEvent_t TxNextPacketTimer;

/*!
 * Specifies the state of the application LED
 */
static bool AppLedStateOn = false;

/*!
 * Indicates if a new packet can be sent
 */
static bool NextTx = true;

/*!
 * Device states
 */
static enum eDeviceState
{
    DEVICE_STATE_INIT,
    DEVICE_STATE_JOIN,
    DEVICE_STATE_SEND,
    DEVICE_STATE_CYCLE,
    DEVICE_STATE_SLEEP
}DeviceState;

/*!
 * LoRaWAN compliance tests support data
 */
struct ComplianceTest_s
{
    bool Running;
    uint8_t State;
    bool IsTxConfirmed;
    uint8_t AppPort;
    uint8_t AppDataSize;
    uint8_t *AppDataBuffer;
    uint16_t DownLinkCounter;
    bool LinkCheck;
    uint8_t DemodMargin;
    uint8_t NbGateways;
}ComplianceTest;

/*!
 * \brief   Prepares the payload of the frame
 */
static void PrepareTxFrame( uint8_t port )
{
    switch( port )
    {
    case 1:
        {
        	if(Lat != 0) {
				char strLat[10];
				char strLng[10];
				char strAtt[10];
				char strBattery[10];
				ftoa(strLat, Lat);
				ftoa(strLng, Lng);
				ftoa(strAtt, Att);
				ftoa(strBattery, inputVol);
				sprintf(AppData, "%s; %s; %s; %s;;;", strLat, strLng, strAtt, strBattery);
				AppDataSize = strlen(AppData);
			} else {
				char strBattery[10];
				ftoa(strBattery, inputVol);
				sprintf(AppData,";;;%s;;;", strBattery);
				AppDataSize = strlen(AppData);
			}
        }
        break;
    case 224:
        if( ComplianceTest.LinkCheck == true )
        {
            ComplianceTest.LinkCheck = false;
            AppDataSize = 3;
            AppData[0] = 5;
            AppData[1] = ComplianceTest.DemodMargin;
            AppData[2] = ComplianceTest.NbGateways;
            ComplianceTest.State = 1;
        }
        else
        {
            switch( ComplianceTest.State )
            {
            case 4:
                ComplianceTest.State = 1;
                break;
            case 1:
                AppDataSize = 2;
                AppData[0] = ComplianceTest.DownLinkCounter >> 8;
                AppData[1] = ComplianceTest.DownLinkCounter;
                break;
            }
        }
        break;
    default:
        break;
    }
}

/*!
 * \brief   Prepares the payload of the frame
 *
 * \retval  [0: frame could be send, 1: error]
 */
static bool SendFrame( void )
{
    McpsReq_t mcpsReq;
    LoRaMacTxInfo_t txInfo;

    if( LoRaMacQueryTxPossible( AppDataSize, &txInfo ) != LORAMAC_STATUS_OK )
    {
        // Send empty frame in order to flush MAC commands
        mcpsReq.Type = MCPS_UNCONFIRMED;
        mcpsReq.Req.Unconfirmed.fBuffer = NULL;
        mcpsReq.Req.Unconfirmed.fBufferSize = 0;
        mcpsReq.Req.Unconfirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
    }
    else
    {
        if( IsTxConfirmed == false )
        {
            mcpsReq.Type = MCPS_UNCONFIRMED;
            mcpsReq.Req.Unconfirmed.fPort = AppPort;
            mcpsReq.Req.Unconfirmed.fBuffer = AppData;
            mcpsReq.Req.Unconfirmed.fBufferSize = AppDataSize;
            mcpsReq.Req.Unconfirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
        }
        else
        {
            mcpsReq.Type = MCPS_CONFIRMED;
            mcpsReq.Req.Confirmed.fPort = AppPort;
            mcpsReq.Req.Confirmed.fBuffer = AppData;
            mcpsReq.Req.Confirmed.fBufferSize = AppDataSize;
            mcpsReq.Req.Confirmed.NbTrials = 8;
            mcpsReq.Req.Confirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
        }
    }

    if( LoRaMacMcpsRequest( &mcpsReq ) == LORAMAC_STATUS_OK )
    {
        return false;
    }
    return true;
}

/*!
 * \brief Function executed on TxNextPacket Timeout event
 */
static void OnTxNextPacketTimerEvent( void )
{
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    TimerStop( &TxNextPacketTimer );

    mibReq.Type = MIB_NETWORK_JOINED;
    status = LoRaMacMibGetRequestConfirm( &mibReq );

    if( status == LORAMAC_STATUS_OK )
    {
        if( mibReq.Param.IsNetworkJoined == true )
        {
        	DeviceState = DEVICE_STATE_SEND;
            NextTx = true;
        }
        else
        {
            DeviceState = DEVICE_STATE_JOIN;
        }
    }
}


/*!
 * \brief Function executed on Led 2 Timeout event
 */



/*!
 * \brief   MCPS-Confirm event function
 *
 * \param   [IN] mcpsConfirm - Pointer to the confirm structure,
 *               containing confirm attributes.
 */ // Send confirm
static void McpsConfirm( McpsConfirm_t *mcpsConfirm )
{
    if( mcpsConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK )
    {
        switch( mcpsConfirm->McpsRequest )
        {
            case MCPS_UNCONFIRMED: ///send successs
            {
                // Check Datarate
                // Check TxPower
            	sendSuccess = 1;
                break;
            }
            case MCPS_CONFIRMED:
            {
                // Check Datarate
                // Check TxPower
                // Check AckReceived
                // Check NbTrials
                break;
            }
            case MCPS_PROPRIETARY:
            {
                break;
            }
            default:
                break;
        }
    }
    NextTx = true;
}

/*!
 * \brief   MCPS-Indication event function
 *
 * \param   [IN] mcpsIndication - Pointer to the indication structure,
 *               containing indication attributes.
 */
static void McpsIndication( McpsIndication_t *mcpsIndication )
{
    if( mcpsIndication->Status != LORAMAC_EVENT_INFO_STATUS_OK )
    {
        return;
    }

    switch( mcpsIndication->McpsIndication )
    {
        case MCPS_UNCONFIRMED:
        {
            break;
        }
        case MCPS_CONFIRMED:
        {
            break;
        }
        case MCPS_PROPRIETARY:
        {
            break;
        }
        case MCPS_MULTICAST:
        {
            break;
        }
        default:
            break;
    }

    // Check Multicast
    // Check Port
    // Check Datarate
    // Check FramePending
    // Check Buffer
    // Check BufferSize
    // Check Rssi
    // Check Snr
    // Check RxSlot

    if( ComplianceTest.Running == true )
    {
        ComplianceTest.DownLinkCounter++;
    }

    if( mcpsIndication->RxData == true )
    {
        switch( mcpsIndication->Port )
        {
        case 1: // The application LED can be controlled on port 1 or 2
        case 2:
            if( mcpsIndication->BufferSize == 1 )
            {
                AppLedStateOn = mcpsIndication->Buffer[0] & 0x01;
//                GpioWrite( &Led3, ( ( AppLedStateOn & 0x01 ) != 0 ) ? 1 : 0 );

            }
            break;
        case 224:
            if( ComplianceTest.Running == false )
            {
                // Check compliance test enable command (i)
                if( ( mcpsIndication->BufferSize == 4 ) &&
                    ( mcpsIndication->Buffer[0] == 0x01 ) &&
                    ( mcpsIndication->Buffer[1] == 0x01 ) &&
                    ( mcpsIndication->Buffer[2] == 0x01 ) &&
                    ( mcpsIndication->Buffer[3] == 0x01 ) )
                {
                    IsTxConfirmed = false;
                    AppPort = 224;
                    AppDataSize = 2;
                    ComplianceTest.DownLinkCounter = 0;
                    ComplianceTest.LinkCheck = false;
                    ComplianceTest.DemodMargin = 0;
                    ComplianceTest.NbGateways = 0;
                    ComplianceTest.Running = true;
                    ComplianceTest.State = 1;

                    MibRequestConfirm_t mibReq;
                    mibReq.Type = MIB_ADR;
                    mibReq.Param.AdrEnable = true;
                    LoRaMacMibSetRequestConfirm( &mibReq );

                    LoRaMacTestSetDutyCycleOn( false );
                }
            }
            else
            {
                ComplianceTest.State = mcpsIndication->Buffer[0];
                switch( ComplianceTest.State )
                {
                case 0: // Check compliance test disable command (ii)
                    IsTxConfirmed = LORAWAN_CONFIRMED_MSG_ON;
                    AppPort = LORAWAN_APP_PORT;
                    AppDataSize = LORAWAN_APP_DATA_SIZE;
                    ComplianceTest.DownLinkCounter = 0;
                    ComplianceTest.Running = false;

                    MibRequestConfirm_t mibReq;
                    mibReq.Type = MIB_ADR;
                    mibReq.Param.AdrEnable = LORAWAN_ADR_ON;
                    LoRaMacMibSetRequestConfirm( &mibReq );
                    LoRaMacTestSetDutyCycleOn( LORAWAN_DUTYCYCLE_ON );
                    break;
                case 1: // (iii, iv)
                    AppDataSize = 2;
                    break;
                case 2: // Enable confirmed messages (v)
                    IsTxConfirmed = true;
                    ComplianceTest.State = 1;
                    break;
                case 3:  // Disable confirmed messages (vi)
                    IsTxConfirmed = false;
                    ComplianceTest.State = 1;
                    break;
                case 4: // (vii)
                    AppDataSize = mcpsIndication->BufferSize;

                    AppData[0] = 4;
                    for( uint8_t i = 1; i < MIN( AppDataSize, LORAWAN_APP_DATA_MAX_SIZE ); i++ )
                    {
                        AppData[i] = mcpsIndication->Buffer[i] + 1;
                    }
                    break;
                case 5: // (viii)
                    {
                        MlmeReq_t mlmeReq;
                        mlmeReq.Type = MLME_LINK_CHECK;
                        LoRaMacMlmeRequest( &mlmeReq );
                    }
                    break;
                case 6: // (ix)
                    {
                        MlmeReq_t mlmeReq;

                        // Disable TestMode and revert back to normal operation
                        IsTxConfirmed = LORAWAN_CONFIRMED_MSG_ON;
                        AppPort = LORAWAN_APP_PORT;
                        AppDataSize = LORAWAN_APP_DATA_SIZE;
                        ComplianceTest.DownLinkCounter = 0;
                        ComplianceTest.Running = false;

                        MibRequestConfirm_t mibReq;
                        mibReq.Type = MIB_ADR;
                        mibReq.Param.AdrEnable = LORAWAN_ADR_ON;
                        LoRaMacMibSetRequestConfirm( &mibReq );
                        LoRaMacTestSetDutyCycleOn( LORAWAN_DUTYCYCLE_ON );

                        mlmeReq.Type = MLME_JOIN;

                        mlmeReq.Req.Join.DevEui = DevEui;
                        mlmeReq.Req.Join.AppEui = AppEui;
                        mlmeReq.Req.Join.AppKey = AppKey;
                        mlmeReq.Req.Join.NbTrials = 3;

                        LoRaMacMlmeRequest( &mlmeReq );
                        DeviceState = DEVICE_STATE_SLEEP;
                    }
                    break;
                case 7: // (x)
                    {
                        if( mcpsIndication->BufferSize == 3 )
                        {
                            MlmeReq_t mlmeReq;
                            mlmeReq.Type = MLME_TXCW;
                            mlmeReq.Req.TxCw.Timeout = ( uint16_t )( ( mcpsIndication->Buffer[1] << 8 ) | mcpsIndication->Buffer[2] );
                            LoRaMacMlmeRequest( &mlmeReq );
                        }
                        else if( mcpsIndication->BufferSize == 7 )
                        {
                            MlmeReq_t mlmeReq;
                            mlmeReq.Type = MLME_TXCW_1;
                            mlmeReq.Req.TxCw.Timeout = ( uint16_t )( ( mcpsIndication->Buffer[1] << 8 ) | mcpsIndication->Buffer[2] );
                            mlmeReq.Req.TxCw.Frequency = ( uint32_t )( ( mcpsIndication->Buffer[3] << 16 ) | ( mcpsIndication->Buffer[4] << 8 ) | mcpsIndication->Buffer[5] ) * 100;
                            mlmeReq.Req.TxCw.Power = mcpsIndication->Buffer[6];
                            LoRaMacMlmeRequest( &mlmeReq );
                        }
                        ComplianceTest.State = 1;
                    }
                    break;
                default:
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
}

/*!
 * \brief   MLME-Confirm event function
 *
 * \param   [IN] mlmeConfirm - Pointer to the confirm structure,
 *               containing confirm attributes.
 */ //receive join data
static void MlmeConfirm( MlmeConfirm_t *mlmeConfirm )
{
    switch( mlmeConfirm->MlmeRequest )
    {
        case MLME_JOIN:
        {
            if( mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK )
            {
                // Status is OK, node has joined the network
            	saveDataToEeprom();
                DeviceState = DEVICE_STATE_SEND;
            }
            else
            {
                // Join was not successful. Try to join again
            	DeviceState = DEVICE_STATE_JOIN;
            }
            break;
        }
        case MLME_LINK_CHECK:
        {
            if( mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK )
            {
                // Check DemodMargin
                // Check NbGateways
                if( ComplianceTest.Running == true )
                {
                    ComplianceTest.LinkCheck = true;
                    ComplianceTest.DemodMargin = mlmeConfirm->DemodMargin;
                    ComplianceTest.NbGateways = mlmeConfirm->NbGateways;
                }
            }
            break;
        }
        default:
            break;
    }
    NextTx = true;
}

void NMEA_GPRMC_Decoder(unsigned char *dataInput)
{
  unsigned long time_template;
  unsigned char hour_template, minute_template, second_template, date_template, month_template, year_template;
  char *message_field[13];
  if(getMessageFeilds(message_field, dataInput, ',', 13) == 13)
  {

      if(strcmp(message_field[GPRMC_MID], "GPRMC") != 0)
      {
        return;
      }
      if( strcmp(message_field[GPRMC_STS],"A") == 0)
      {
        gpsStatus = true;

        SpeedGPS = atof(message_field[GPRMC_SOG]) * 1.852;
        OrGPS = atof(message_field[GPRMC_COG]);
        Lat = gpsConvertLatToFloat(message_field[GPRMC_LAT], message_field[GPRMC_LAT_NS]);
        Lng = gpsConvertLonToFloat(message_field[GPRMC_LON], message_field[GPRMC_LON_EW]);
      }
      else if( strcmp(message_field[GPRMC_STS],"V") == 0)
      {
        gpsStatus = false;
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


void NMEA_GPGGA_Decoder(unsigned char *dataInput)
{
  unsigned long time_template;
  unsigned char hour_template, minute_template, second_template, date_template, month_template, year_template;
  char *message_field[15];
  if(getMessageFeilds(message_field, dataInput, ',', 15) == 15)
  {

      if(strcmp(message_field[GPGGA_MID], "GPGGA") != 0)
      {
        return;
      }
      if( strcmp(message_field[GPGGA_STS],"1") == 0)
      {
        gpsStatus = true;

        Lat = gpsConvertLatToFloat(message_field[GPGGA_LAT], message_field[GPGGA_LAT_NS]);
        Lng = gpsConvertLonToFloat(message_field[GPGGA_LON], message_field[GPGGA_LON_EW]);
        Att = atof(message_field[GPGGA_ATT]);
      }
      else
      {
        gpsStatus = false;
        Lat = 0;
        Lng = 0;
        Att = 0;
      }
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
		  NMEA_GPGGA_Decoder(dataGpsInput);
		  counter = 0;
		}
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

int main(void)
 {
	LoRaMacPrimitives_t LoRaMacPrimitives;
	LoRaMacCallback_t LoRaMacCallbacks;
	MibRequestConfirm_t mibReq;
	LoRaMacStatus_t status;
	int numSend= 0;
	int statusaa;
	int dataEeprom;
	MCU_Init();
	srand(time(NULL)); // should only be called once

	enableFreeFallInt(20);
	clearFlagFreeFallInt();

	DelayMs(3000);
/*
	GpioWrite( &Led0, 1 );
	DelayMs(500);
	GpioWrite( &Led0, 0 );
	DelayMs(1500);*/

	DeviceState = DEVICE_STATE_INIT;

	//statusaa = writeEepromData(addrEeprom, 0, 255);
	statusaa = writeEepromData(addrEeprom, 250, 170);
	dataEeprom = readEepromData(addrEeprom, 250);

	/*while(gpsStatus == false) {
		timeoutGps++;
		if(timeoutGps >= 60) {
			timeoutGps = 0;
			break;
		}
		DelayMs(5000);
	}*/
	while(true)
	{
		i2cread = whoAmI();
		adcRead = AdcReadChannel();
		inputVol = ((float)adcRead / 4096) * 2.5 * 2.0;
		interruptStatus = MMA8652_RegisterGet(MMA8652_INT_SOURCE);

		switch( DeviceState )
		{
			case DEVICE_STATE_INIT:
			{
				LoRaMacPrimitives.MacMcpsConfirm = McpsConfirm;
				LoRaMacPrimitives.MacMcpsIndication = McpsIndication;
				LoRaMacPrimitives.MacMlmeConfirm = MlmeConfirm;
				LoRaMacCallbacks.GetBatteryLevel = BoardGetBatteryLevel;
				status = LoRaMacInitialization( &LoRaMacPrimitives, &LoRaMacCallbacks, LORAMAC_REGION_EU868 );

				TimerInit( &TxNextPacketTimer, OnTxNextPacketTimerEvent );

				mibReq.Type = MIB_ADR;
				mibReq.Param.AdrEnable = LORAWAN_ADR_ON;
				LoRaMacMibSetRequestConfirm( &mibReq );

				mibReq.Type = MIB_PUBLIC_NETWORK;
				mibReq.Param.EnablePublicNetwork = LORAWAN_PUBLIC_NETWORK;
				LoRaMacMibSetRequestConfirm( &mibReq );

				LoRaMacTestSetDutyCycleOn( LORAWAN_DUTYCYCLE_ON );

#if( USE_SEMTECH_DEFAULT_CHANNEL_LINEUP == 1 )
				LoRaMacChannelAdd( 0, ( ChannelParams_t )LC0 );
				LoRaMacChannelAdd( 1, ( ChannelParams_t )LC1 );
				LoRaMacChannelAdd( 2, ( ChannelParams_t )LC2 );
				LoRaMacChannelAdd( 3, ( ChannelParams_t )LC3 );
				LoRaMacChannelAdd( 4, ( ChannelParams_t )LC4 );
				LoRaMacChannelAdd( 5, ( ChannelParams_t )LC5 );
				LoRaMacChannelAdd( 6, ( ChannelParams_t )LC6 );
				LoRaMacChannelAdd( 7, ( ChannelParams_t )LC7 );

				mibReq.Type = MIB_RX2_DEFAULT_CHANNEL;
				mibReq.Param.Rx2DefaultChannel = ( Rx2ChannelParams_t ){ 869525000, DR_0 };
				LoRaMacMibSetRequestConfirm( &mibReq );

				mibReq.Type = MIB_RX2_CHANNEL;
				mibReq.Param.Rx2Channel = ( Rx2ChannelParams_t ){ 869525000, DR_0 };
				LoRaMacMibSetRequestConfirm( &mibReq );
#endif

				dataEeprom = readEepromData(addrEeprom, 0);

				if(joinedChecking() == 255) {
					DeviceState = DEVICE_STATE_JOIN;
				} else if(joinedChecking() == 1) {
					getJoinParamFromEeprom();
					DeviceState = DEVICE_STATE_SEND;
				}
				/// check rejoin button ///
				for(int i =0; i < 700; i++) {
					if (GPIO_PinInGet(gpioPortD, 9) == 0) {
						DeviceState = DEVICE_STATE_JOIN;
						while (GPIO_PinInGet(gpioPortD, 9) == 0);
						break;
					} else {
						DelayMs(10);
					}
				}
				break;
			}
			case DEVICE_STATE_JOIN:
			{
                MlmeReq_t mlmeReq;

                // Initialize LoRaMac device unique ID
//                BoardGetUniqueId( DevEui );

                mlmeReq.Type = MLME_JOIN;
                mlmeReq.Req.Join.DevEui = DevEui;
                mlmeReq.Req.Join.AppEui = AppEui;
                mlmeReq.Req.Join.AppKey = AppKey;
                mlmeReq.Req.Join.NbTrials = 3;
                if( NextTx == true ) {
                	status = LoRaMacMlmeRequest( &mlmeReq );
                }
                multiSend = 1;
                DeviceState = DEVICE_STATE_SLEEP;
                break;
			}
			case DEVICE_STATE_SEND:
			{
				int i;
				uint32_t freq[EU868_MAX_NB_CHANNELS];
				for( i = 0; i < EU868_MAX_NB_CHANNELS; i++) {
					freq[i] = Channels[i].Frequency;
				}


				if( NextTx == true ) {
					PrepareTxFrame( AppPort );

					NextTx = SendFrame( );
				}
				currentChannel = Channel;
				DeviceState = DEVICE_STATE_CYCLE;

				setStoredUplCounter(UpLinkCounter);
				setStoredDownlCounter(DownLinkCounter);

				DelayMs(5000);// wait a while for received send feed back
				break;
			}
			case DEVICE_STATE_CYCLE:
			{
				DeviceState = DEVICE_STATE_SLEEP;

				// Schedule next packet transmission
				/*send success*/
				/*if ( sendSuccess == 1) {
					sendSuccess = 0;
					//gpsStatus = true;
					if (gpsStatus == true) {
						goToSleepMode();
					} else {
						TimerSetValue( &TxNextPacketTimer, 10000 );
						TimerStart( &TxNextPacketTimer );
					}
				} else {
					TimerSetValue( &TxNextPacketTimer, 10000 );
					TimerStart( &TxNextPacketTimer );
				}*/
				/*if ( sendSuccess == 1 ) {
					sendSuccess = 0;
					goToSleepMode();
				}*/
				if (multiSend != 0) {
					multiSend++;
					if(multiSend > 2) {
						multiSend = 0;
					}
					TimerSetValue( &TxNextPacketTimer, 10000 );
					TimerStart( &TxNextPacketTimer );
				} else {
					goToSleepMode();
				}

				break;
			}
			case DEVICE_STATE_SLEEP:
			{
				break;
			}
			default:
			{
				DeviceState = DEVICE_STATE_INIT;
				break;
			}
		}

		clearFlagFreeFallInt();
	}
}

/**/
void MCU_Init()
{
	CHIP_Init();
	EMUInit();
	CMUInit();
	GpsInit();
	AdcInit();
	RtcInit();
	CryotimerInit();
	MMA8652_I2CInit();
	BoardInitPeriph();

	GpioWrite( &LORA_Enable, 0 ); ////ENABLE LORA
	GpioWrite( &GPS_Enable, 0 );  ////ENABLE GPS

}

void goToSleepMode()
{
		/* Pin PD13 is configured to Push-pull */
	GPIO_PinOutClear(gpioPortD, 10);

	GPIO_PinOutClear(gpioPortD, 11);

	GPIO_PinOutClear(gpioPortD, 12);

		/* Pin PD13 is configured to Push-pull */
	GPIO_PinOutClear(gpioPortD, 13);

		/* Pin PD14 is configured to Open-drain with pull-up and filter */
	GPIO_PinOutClear(gpioPortD, 14);

		/* Pin PD15 is configured to Open-drain with pull-up and filter */
	GPIO_PinOutClear(gpioPortD, 15);

	GPIO_PinOutClear(PORT_SPI_TX, PIN_SPI_TX);
	GPIO_PinOutClear(PORT_SPI_RX, PIN_SPI_RX);
	GPIO_PinOutClear(PORT_SPI_CLK,PIN_SPI_CLK);
	GPIO_PinOutClear(PORT_SPI_CS, PIN_SPI_CS);

	GpioWrite(&SX1276.Spi.Nss, 0);
	GpioWrite(&SX1276.DIO0, 0);
	GpioWrite(&SX1276.DIO1, 0);
	GpioWrite(&SX1276.DIO2, 0);
	GpioWrite(&SX1276.DIO3, 0);
	GpioWrite(&SX1276.DIO4, 0);
	GpioWrite(&SX1276.DIO5, 0);

	GpioWrite( &LORA_Enable, 1 );
	GpioWrite( &GPS_Enable, 1 );
	EMU_EnterEM4();
}

void saveDataToEeprom(void)
{
	setJoinedChecking();
	setStoredNwsKey(&LoRaMacNwkSKey);
	setStoredAppsKey(&LoRaMacAppSKey);
	setStoredDevNonce(LoRaMacDevNonce);
	setStoredNetID(LoRaMacNetID);
	setStoredDevAddr(LoRaMacDevAddr);
	setStoredUplCounter(UpLinkCounter);
	setStoredDownlCounter(DownLinkCounter);

}

void getJoinParamFromEeprom(void)
{
	getStoredNwsKey(&LoRaMacNwkSKey);
	getStoredAppsKey(&LoRaMacAppSKey);
	LoRaMacDevNonce = getStoredDevNonce();
	LoRaMacNetID = getStoredNetID();
	LoRaMacDevAddr = getStoredDevAddr();
	UpLinkCounter = getStoredUplCounter() + 1;
	DownLinkCounter = getStoredDownlCounter();
}
