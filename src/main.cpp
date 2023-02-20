#define F_CPU 1000000UL

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include "../include/main.h"
#include "../include/Buffer.h"
#include "../include/GPS-Data.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    ConfigurePorts();
    ConfigureDisplayLCD();
    SetSpeedUSART(12);//9600 bps 0.2% error with double speed
    ConfigureUSART();
    EnableGlobalInterrupts();
    extern Stream_Buffer Buffer;
    extern GPSData GPSDataStruct;
    char Descriptor = 0x04;
    char *Data = 0;
    while(true) {
        if (IsNMEADataWasTransmitted(Buffer.Stack) && Buffer.LockBuffer(Descriptor)) {
            GPSDataStruct.ParseNMEAData( Buffer.PullAll(), 
                                         FindPositionOfFirstEntryOfSubString(Buffer.Stack, "GGA"),
                                         3, 
                                         14 );
            ClearLCD();
            SendStringToLCD((char*)GPSDataStruct.Latitude);
            *Buffer.Stack = '\0';
            Buffer.IndexOfNextElement = 0;
            Buffer.UnlockBuffer(Descriptor);
        }
    }
    return 0;
}