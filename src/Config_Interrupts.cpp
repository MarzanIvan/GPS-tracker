#include "../include/Config_Interrupts.h"
#include "../include/Display_LCD.h"
#include "../include/IODataUSART.h"

short unsigned int X,Y = 0;

ISR(USART_RX_vect) {
    SetCharacterDisplayPositionOnLCD(X,Y);
    SendBiteToLCD(USART_DataRegister, DATA);  
    if ( X < MaxSizeOfStringOfLCD) {
        X++;
    } 
    else if (Y < MaxIndexOfStringOfLCD) {
        Y++;
        X = 0;
    }
    else {
        Y = 0;
        X = 0;
    }
}