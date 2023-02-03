#ifndef GPSDATAH
    #define GPSDATAH

struct GPSData {
    double Latitude;
    double Longitude;
    double InitialLatitude;
    double InitialLongitude;
    unsigned char Hours;
    unsigned char Minutes;
    unsigned char Seconds;
    unsigned char HemisphereNorthSouth;
    unsigned char HemisphereEastWest;
    unsigned char PositionFixIndicator; // GPS observation quality indicator
    unsigned char AmountOfSatellitesUsed;
    unsigned char HorizontalDilutionOfPrecision;
    unsigned char MSL_Altitude; // Antenna height from sea level
    unsigned char Units;
    unsigned char GeoidalSeparation;
    unsigned int AgeOfDifferentialGPSDataInSeconds;
    unsigned int StationID;
};

bool DoesStringContainSubString( const char *Array, const char* SubString);

char** ParseNMEAData(const char *GPS_NMEA_Data, char *Output_GPSData[], unsigned char SizeOfPostfix, unsigned char AmountOfFields);

#endif