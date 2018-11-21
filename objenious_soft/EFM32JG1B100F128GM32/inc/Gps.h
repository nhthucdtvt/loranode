/*
 * Gps.h
 *
 *  Created on: Jan 20, 2018
 *      Author: khiemtt
 */

#ifndef INC_GPS_H_
#define INC_GPS_H_

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

#define GPGGA_MID         		0
#define GPGGA_UTC         		1
#define GPGGA_LAT         		2
#define GPGGA_LAT_NS      		3
#define GPGGA_LON         		4
#define GPGGA_LON_EW      		5
#define GPGGA_STS		  		6
#define GPGGA_NOSV        		7
#define GPGGA_HDOP        		8
#define GPGGA_ATT         		9
#define GPGGA_ATT_M       		10
#define GPGGA_GEOID       		11
#define GPGGA_GEOID_M     		12
#define GPGGA_DGPSA				13
#define GPGGA_DGPS_STATION_ID	14

void sendString(LEUART_TypeDef *leuart, char * string);
float gpsConvertLatToFloat(unsigned char *lat_str, unsigned char *NS);
float gpsConvertLonToFloat(unsigned char *lon_str, unsigned char *WE);
int getMessageFeilds(unsigned char **message_feildls, unsigned char *msg, unsigned char separate_char, int max_feild_get);
void ftoa(char *output, float inputNumber);

#endif /* INC_GPS_H_ */
