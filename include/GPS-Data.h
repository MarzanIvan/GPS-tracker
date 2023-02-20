#ifndef GPSDATAH
    #define GPSDATAH

struct GPSData {
    unsigned char UTCTime[11];              //hhmmss.sss + stop string bit
    unsigned char Latitude[10];              //hhmmss.sss + stop string bit
    unsigned char HemisphereNorthSouth[2];  // N or S + stop string bit
    unsigned char Longitude[11];            //dddmm.mmmm + stop string bit
    unsigned char InitialLatitude[10];       //hhmmss.sss + stop string bit
    unsigned char InitialLongitude[11];     //dddmm.mmmm + stop string bit
    unsigned char HemisphereEastWest[2];    // E or W + stop string bit
    unsigned char PositionFixIndicator[2];  // GPS observation quality indicator + stop string bit
    unsigned char AmountOfSatellitesUsed[3];// range is from 0 to 12 satellites + stop string bit
    unsigned char HorizontalDilutionOfPrecision[10]; // https://en.wikipedia.org/wiki/Dilution_of_precision_(navigation)
    unsigned char MSL_Altitude[10];         // Antenna height from sea level + stop string bit
    unsigned char Units[2];                 // can be (M) Meters or something else + stop string bit
    unsigned char GeoidalSeparation[6];     // https://en.wikipedia.org/wiki/Geoid + stop string bit
    unsigned char AgeOfDifferentialGPSDataInSeconds[10];
    unsigned char StationID[5];             // format station id is xxxx + stop string bit
    unsigned char Checksum[10];             // The checksum is the XOR of all the bytes between the $ and the * in the sentence
    unsigned char* ArrayPointersOfGPSFields[14];

    GPSData() {
        ArrayPointersOfGPSFields[0] = UTCTime;
        ArrayPointersOfGPSFields[1] = Latitude;
        ArrayPointersOfGPSFields[2] = HemisphereNorthSouth;
        ArrayPointersOfGPSFields[3] = Longitude;
        ArrayPointersOfGPSFields[4] = HemisphereEastWest;
        ArrayPointersOfGPSFields[5] = PositionFixIndicator;
        ArrayPointersOfGPSFields[6] = AmountOfSatellitesUsed;
        ArrayPointersOfGPSFields[7] = HorizontalDilutionOfPrecision;
        ArrayPointersOfGPSFields[8] = MSL_Altitude;
        ArrayPointersOfGPSFields[9] = Units;
        ArrayPointersOfGPSFields[10] = GeoidalSeparation;
        ArrayPointersOfGPSFields[11] = Units;
        ArrayPointersOfGPSFields[12] = AgeOfDifferentialGPSDataInSeconds;
        ArrayPointersOfGPSFields[13] = StationID;
        ArrayPointersOfGPSFields[13] = Checksum;
    }
    
    void ParseNMEAData(const char *GPS_NMEA_Data, char PositionOfNMEAData, unsigned char SizeOfPostfix, unsigned char AmountOfFields);
};

bool DoesStringContainSubString( const char *String, const char* SubString );

#define AmountOfPackagesIsRequiredFromGPSModule 3

bool IsNMEADataWasTransmitted(const char *USART_Buffer);

char FindPositionOfFirstEntryOfSubString( const char *String, const char* SubString );

#endif