#ifndef MAIN_H
#define MAIN_H

#include "IODataUSART.h"
#include "Config_Interrupts.h"
#include "Display_LCD.h"

inline void ConfigureUSART() {
    EnableIO_USART();
    EnableInterruptReadUSART();
    DoubleTransmissionSpeedUSART();
    ConfigureIO_USART();
}

inline void ConfigurePorts() {
    DDRD = 0b11111110;
    PORTD = 0;
}

#endif