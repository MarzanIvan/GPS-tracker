
#include "include/IODataUSART.hpp"

inline void SetSpeedUSART( unsigned int SpeedIO ) {
    UBRR0H = (unsigned char) (SpeedIO >> 8);
    UBRR0L = (unsigned char) SpeedIO;
}

inline void EnableIO_USART() {
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

inline void EnableInterruptReadUSART() {
    UCSR0B |= (1 << RXCIE0);
}

inline void DoubleTransmissionSpeedUSART() {
    UCSR0A |= (1 << U2X0);
}

inline void ConfigureIO_USART() {
    UCSR0C = (0 << UMSEL00) | (0 << UMSEL01) | (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02);
} 

void TransmitData_By_USART( unsigned char data ) {
    while( !( UCSR0A & (1 << UDRE0)) );
    UDR0 = data;
}
