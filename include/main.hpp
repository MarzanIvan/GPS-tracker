#ifndef MAIN_HPP
#define MAIN_HPP

#include "IODataUSART.hpp"
#include "Config_Interrupts.hpp"
#include "Display_LCD.hpp"

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

inline void EnableGlobalEnterrupt() {
    SREG |= (1<<7);
}

#endif