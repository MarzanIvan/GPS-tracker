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

char** ParseNMEAData(const char *GPS_NMEA_Data,char *Output_GPSData[], int SizeOfPostfix, int SizeOfFields) {
	GPS_NMEA_Data += (4 + SizeOfPostfix);
	char GPS_GGA_NMEA_Data[SizeOfFields][10];
	for (unsigned int i = 0; i < SizeOfFields; i++) {
		char *TempStr = Output_GPSData[i];
		while (*GPS_NMEA_Data != ',' && *GPS_NMEA_Data != 0) {
			*TempStr = *GPS_NMEA_Data;
			GPS_NMEA_Data++;
			TempStr++;
		}
		*TempStr = '\0';
		GPS_NMEA_Data++;
	}
	return Output_GPSData;
}