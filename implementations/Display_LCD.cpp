#include "../include/Display_LCD.hpp"

void Send4BitsToLCD( unsigned char data ) {
    PORTD |= (1<<3);

    _delay_us(50);
    PORTD &= 0b00001111;
    PORTD |= (data << 4);

    PORTD &= 0b11110111;
    _delay_us(50);
    PORTD &= 0b00001111;
}

void SendBiteToLCD( unsigned int data, ModesSending ModeSending ) {
    if (ModeSending == COMMAND) {
        PORTD &= 0b11111011;
    } else {
        PORTD |= (1 << 2);
    }
    Send4BitsToLCD(data >> 4);
    Send4BitsToLCD(data);

}

void SetPositionShowingLCD( unsigned int X, unsigned int Y ) {
    char Adress  = (0x40 * Y + X) | 0b10000000;
    SendBiteToLCD(Adress, COMMAND);
}

void ClearDisplayLCD() {
    SendBiteToLCD(0b00000001, COMMAND);
    _delay_us(1500);
}

void SendStringToLCD( const char *ElementString ) {
    while(*ElementString) {
        SendBiteToLCD(*ElementString, DATA);
        ElementString++;
    }
}