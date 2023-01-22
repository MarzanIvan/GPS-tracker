#define F_CPU 1000000UL

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include "../include/main.h"
#include "../include/Buffer.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    ConfigurePorts();
    ConfigureDisplayLCD();
    SetSpeedUSART(12);//9600 bps 0.2% error with double speed
    ConfigureUSART();
    EnableGlobalInterrupts();
    extern Stream_Buffer Buffer;
    char Descriptor = 0x02;
    char *Data = 0;
    while(true) {
        _delay_ms(100);
        if (Buffer.LockBuffer(Descriptor)) {
            if (Data = Buffer.PullAll()) {
                ClearLCD();
                SendStringToLCD(Data);
                *Buffer.Stack = '\0';
                Buffer.IndexOfNextElement = 0;
                Buffer.UnlockBuffer(Descriptor);
            }
        }
        _delay_ms(100);
    }
    return 0;
}