#ifndef GPSDATAH
    #define GPSDATAH

#include <cstdlib>

#define AmountFieldsOfDoubleType
#define AmountFieldsOfIntegerType

struct GPSData {
    unsigned char Latitude[9];              //hhmmss.sss
    unsigned char Longitude[10];            //dddmm.mmmm
    unsigned char InitialLatitude[9];       //hhmmss.sss
    unsigned char InitialLongitude[10];     //dddmm.mmmm
    unsigned char UTCTime[10];              //hhmmss.sss
    unsigned char HemisphereNorthSouth[1];  // N or S
    unsigned char HemisphereEastWest[1];    // E or W
    unsigned char PositionFixIndicator[1];  // GPS observation quality indicator
    unsigned char AmountOfSatellitesUsed[2];// range is from 0 to 12 satellites
    unsigned char HorizontalDilutionOfPrecision[10]; // https://en.wikipedia.org/wiki/Dilution_of_precision_(navigation)
    unsigned char MSL_Altitude[10];         // Antenna height from sea level
    unsigned char Units[1];                 // can be (M) Meters or something else
    unsigned char GeoidalSeparation[5];     // https://en.wikipedia.org/wiki/Geoid
    unsigned char AgeOfDifferentialGPSDataInSeconds[10];
    unsigned char StationID[4];             // format station id is xxxx
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
};

bool DoesStringContainSubString( const char *Array, const char* SubString);

char** ParseNMEAData(const char *GPS_NMEA_Data, char *Output_GPSData[], unsigned char SizeOfPostfix, unsigned char AmountOfFields);

#endif