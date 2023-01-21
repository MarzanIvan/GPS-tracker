#define F_CPU 8000000UL

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include "../include/main.h"
#include "../include/Buffer.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    ConfigurePorts();
    SetSpeedUSART(12);
    ConfigureUSART();
    ConfigureDisplayLCD();
    EnableGlobalInterrupts();
    extern Stream_Buffer Buffer;
    while(true) {
        
    }
    return 0;
}