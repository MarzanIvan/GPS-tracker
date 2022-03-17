#ifndef DISPLAY_LCD_HPP
    #define DISPLAY_LCD_HPP

#define F_CPU 8000000UL

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <util/delay.h>
#include <avr/io.h>

void Send4BitsToLCD( unsigned char data );

enum ModesSending{
    COMMAND, DATA
};

void SendBiteToLCD( unsigned int data, ModesSending ModeSending );

void SendStringToLCD( const char *String );

void SetPositionShowingLCD( unsigned int X, unsigned int Y );

inline void ConfigureDisplayLCD() {
    _delay_ms(15);
    Send4BitsToLCD(0b00000011);
    _delay_ms(4);
    Send4BitsToLCD(0b00000011);
    _delay_us(100);
    Send4BitsToLCD(0b00000011);
    _delay_ms(1);
    Send4BitsToLCD(0b00000010);
    _delay_ms(1);
    SendBiteToLCD(0b00101000, COMMAND);
    _delay_ms(1);
    SendBiteToLCD(0b00001100, COMMAND);
    _delay_ms(1);
    SendBiteToLCD(0b00000110, COMMAND);
}

void ClearDisplayLCD();

#endif