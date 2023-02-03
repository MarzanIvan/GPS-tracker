#include "../include/GPS-Data.h"

bool DoesStringContainSubString( const char *String, const char* SubString) {
	while (*String) {
		if (*String == (*SubString)) {
			const char *TempStr = String;
			while (*TempStr == *SubString) {
				if (*TempStr != *SubString) {
					return false;
				}
				TempStr++;
				SubString++;
			}
			return true;
		}
		String++;
	}
}

char** ParseNMEAData(const char *GPS_NMEA_Data, char *Output_GPSData[], unsigned char SizeOfPostfix, unsigned char AmountOfFields) {
	GPS_NMEA_Data += (4 + SizeOfPostfix);
	char GPS_GGA_NMEA_Data[AmountOfFields][10];
	for (unsigned int i = 0; i < AmountOfFields; i++) {
		char *TempStr = Output_GPSData[i];
		while (*GPS_NMEA_Data > 44) { //(ASCII table): 44 (dec) of ",", 42 (dec) of "*"
			*TempStr = *GPS_NMEA_Data;
			GPS_NMEA_Data++;
			TempStr++;
		}
		*TempStr = '\0';
		GPS_NMEA_Data++;
	}
	return Output_GPSData;
}