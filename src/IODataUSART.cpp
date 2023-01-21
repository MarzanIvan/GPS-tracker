
#include "../include/IODataUSART.h"

void TransmitSymbol_By_USART( unsigned char Symbol ) {
    while( !(USART_ControlAndStatusRegisterA & (1 << USART_DataRegisterEmptyFlag)) );
    USART_DataRegister = Symbol;
}

void TransmitString_By_USART( const char *ElementString ) {
    while(*ElementString) {
        while( !(USART_ControlAndStatusRegisterA & (1 << USART_DataRegisterEmptyFlag)) );
        USART_DataRegister = *ElementString;
        ElementString++;
    }
}
