#ifndef GPSDATAH
    #define GPSDATAH
    
struct GPSData {
    double Latitude;
    double Longitude;
    double InitialLatitude;
    double InitialLongitude;

};

bool DoesStringContainSubString( const char *Array, const char* SubString);

#endif