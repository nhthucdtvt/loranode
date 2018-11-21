/*
 * Gps.c
 *
 *  Created on: Jan 20, 2018
 *      Author: khiemtt
 */
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "Gps.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

// different commands to set the update rate from once a second (1 Hz) to 10 times a second (10Hz)
#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"
#define PMTK_SET_NMEA_UPDATE_10HZ "$PMTK220,100*2F"

// turn on only the second sentence (GPRMC)
#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
// turn on only the second sentence (GPGGA)
#define PMTK_SET_NMEA_OUTPUT_GGACONLY "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
// turn on ALL THE DATA
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"
// turn GPS to "warm start"
#define PMTK_CMD_WARM_START "$PMTK102*31\r\n"
// turn GPS to "hot start"
#define PMTK_CMD_HOT_START "$PMTK101*32\r\n"
// GPRMC

// to generate your own sentences, check out the MTK command datasheet and use a checksum calculator
// such as the awesome http://www.hhhh.org/wiml/proj/nmeaxor.html


//unsigned long time_update;


int DISPLAY_GPS = 0;
int DISPLAY_RTC = 1;
int DISPLAY_SPEED_ORG = 2;
int DISPLAY_MAX = 3;

//



void sendString(LEUART_TypeDef *leuart, char * string)
{
      while (*string != 0)
      {
    	  LEUART_Tx(leuart, *string++);
      }
}

float gpsConvertLatToFloat(unsigned char *lat_str, unsigned char *NS)
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
float gpsConvertLonToFloat(unsigned char *lon_str, unsigned char *WE)
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

int getMessageFeilds(unsigned char **message_feildls, unsigned char *msg, unsigned char separate_char, int max_feild_get)
{
  int count_feild = 0;
  *message_feildls = msg;
  message_feildls++;
  count_feild++;
  while(*msg !=NULL)
  {
    if(*msg == separate_char)
    {
      *msg = 0;
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

void ftoa(char *output, float inputNumber)
{
	 int32_t intOfFloat = (int32_t)inputNumber;
	 int32_t remainOfFloat = (inputNumber-intOfFloat)*1000000;
	 sprintf(output,"%d.%d", intOfFloat, abs(remainOfFloat) );
}
///////////End Of GPS Library////////////////////
