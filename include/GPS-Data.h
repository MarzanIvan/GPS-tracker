#ifndef GPSDATAH
    #define GPSDATAH
    
struct GPSData {
    double Latitude;
    double Longitude;
    double InitialLatitude;
    double InitialLongitude;

};

bool DoesStringContainSubString( const char *Array, const char* SubString);

char** ParseNMEAData(const char *GPS_NMEA_Data,char *Output_GPSData[], int SizeOfPostfix, int SizeOfFields);

#endif