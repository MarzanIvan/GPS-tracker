#define F_CPU 8000000UL

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include "../include/main.hpp"

int main() {
    ConfigurePorts();
    SetSpeedUSART(12);
    ConfigureUSART();    
    ConfigureDisplayLCD();
    EnableGlobalEnterrupt(); 
    while(true) {
        
    }
}