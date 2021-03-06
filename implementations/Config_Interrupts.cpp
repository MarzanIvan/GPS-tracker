#include "../include/Config_Interrupts.hpp"
#include "../include/Display_LCD.hpp"
#include "../include/IODataUSART.hpp"

short unsigned int X,Y = 0;

ISR(USART_RX_vect) {
    SetPositionShowingLCD(X,Y);
    SendBiteToLCD(UDR0, DATA);  
    if (X < 15) {
        X++;
    } else if (Y < 1) {
        Y++;
        X = 0;
    }  else {
        Y = 0;
        X = 0;
    }
}