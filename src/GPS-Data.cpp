#include "../include/GPS-Data.h"

bool DoesStringContainSubString( const char *String, const char* SubString) {
	while (*String) {
		if (*String == *SubString) {
			const char* TempStr = String;
			while (*TempStr == *SubString && *TempStr) {
				if (*TempStr != *SubString) {
					return false;
				}
				TempStr++;
				SubString++;
			}
			if (*SubString == '\0') {
				return true;
			}
			else {
				return false;
			}
		}
		String++;
	}
	return false;
}

bool IsNMEADataWasTransmitted(const char *USART_Buffer) {
	int AmountPackage = 0;
	while(*USART_Buffer) {
		if (*USART_Buffer == '$') {
			AmountPackage++;
		}
		USART_Buffer++;
	}
	if (AmountPackage == AmountOfPackagesIsRequiredFromGPSModule) {
		return true;
	} else {
		return false;
	}
}

char FindPositionOfFirstEntryOfSubString( const char *String, const char* SubString ) {
	for ( unsigned char i = 0; *String; i++, String++) {
		const char* TempStr = String;
		const char* TempSubString = SubString;
		while (*TempStr == *TempSubString && *TempStr) {
			if (*TempStr != *TempSubString) {
				return -1;
			}
			TempStr++;
			TempSubString++;
		}
		if (*TempSubString == '\0') {
			return i;
		}
	}
	return -1;
}

void GPSData::ParseNMEAData(const char *GPS_NMEA_Data, char PositionOfNMEAData, unsigned char SizeOfPostfix, unsigned char AmountOfFields) {
	GPS_NMEA_Data += (1 + SizeOfPostfix + PositionOfNMEAData);
	for (unsigned int i = 0; i < AmountOfFields; i++) {
		unsigned char *TempStr = ArrayPointersOfGPSFields[i];
		while (*GPS_NMEA_Data > 44) { // (ASCII table): 44 (dec) of ",", 42 (dec) of "*"
			*TempStr = *GPS_NMEA_Data;
			GPS_NMEA_Data++;
			TempStr++;
		}
		*TempStr = '\0';
		GPS_NMEA_Data++;
	}
}
