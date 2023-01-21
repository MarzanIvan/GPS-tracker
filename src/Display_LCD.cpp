#include "../include/Display_LCD.h"

void Send4BitsToLCD( unsigned char data ) {
    PORTD |= (1 << PORTD3);
    _delay_us(50);
    PORTD &= 0b00001111;
    PORTD |= (data << 4);
    PORTD &= 0b11110111;
    _delay_us(50);
    PORTD &= 0b00001111;
}

short unsigned int X_PositionOfCursorOfLCD = 0, Y_PositionOfCursorOfLCD = 0;

void SendBiteToLCD( unsigned int data, ModesSending ModeSending ) {
    if (ModeSending == COMMAND) {
        PORTD &= ~(1 << PORTD2);
    } else {
        SetCharacterDisplayPositionOnLCD(X_PositionOfCursorOfLCD, Y_PositionOfCursorOfLCD);
        PORTD |= (1 << PORTD2);
        if ( X_PositionOfCursorOfLCD < MaxSizeOfStringOfLCD) {
            X_PositionOfCursorOfLCD++;
        }
        else if (Y_PositionOfCursorOfLCD < MaxIndexOfStringOfLCD) {
            Y_PositionOfCursorOfLCD++;
            X_PositionOfCursorOfLCD = 0;
        }
        else {
            Y_PositionOfCursorOfLCD = 0;
            X_PositionOfCursorOfLCD = 0;
        }
    }
    Send4BitsToLCD(data >> 4);
    Send4BitsToLCD(data);
}

void SetCharacterDisplayPositionOnLCD( short unsigned int X, short unsigned int Y ) {
    char Adress  = (0x40 * Y + X) | 0b10000000;
    SendBiteToLCD(Adress, COMMAND);
}

void ClearLCD(void) {
    SendBiteToLCD(0b00000001, COMMAND);
    _delay_us(1500);
}

void SendStringToLCD( const char *ElementString ) {
    while(*ElementString) {
        SendBiteToLCD(*ElementString, DATA);
        ElementString++;
    }
}