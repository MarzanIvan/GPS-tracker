
#include "../include/IODataUSART.hpp"

void TransmitSymbol_By_USART( unsigned char Symbol ) {
    while( !( UCSR0A & (1 << UDRE0)) );
    UDR0 = Symbol;
}

void TransmitString_By_USART(const char *ElementString ) {
    while(*ElementString) {
        while( !( UCSR0A & (1 << UDRE0)) );
        UDR0 = *ElementString;
        ElementString++;
    }
}
