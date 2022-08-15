#ifndef IODataUSART_HPP
#define IODataUSART_HPP

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>

#define USART_SpeedIOHighRegister UBRR0H
#define USART_SpeedIOLowRegister UBRR0L

inline void SetSpeedUSART( unsigned int SpeedIO ) {
    USART_SpeedIOHighRegister = (unsigned char) (SpeedIO >> 8);
    USART_SpeedIOLowRegister = (unsigned char) SpeedIO;
}

#define USART_ReceiverEnableBit RXEN0
#define USART_TransmitterEnableBit TXEN0
#define USART_ControlAndStatusRegisterB UCSR0B

inline void EnableIO_USART() {
    USART_ControlAndStatusRegisterB = (1 << USART_ReceiverEnableBit) | (1 << USART_TransmitterEnableBit);
}

#define USART_ReceiverInterruptEnableBit RXCIE0

inline void EnableInterruptReadUSART() {
    USART_ControlAndStatusRegisterB |= (1 << USART_ReceiverInterruptEnableBit);
}

#define USART_ControlAndStatusRegisterA UCSR0A
#define USART_DoubleTransmissionSpeedEnableBit U2X0

inline void DoubleTransmissionSpeedUSART() {
    USART_ControlAndStatusRegisterA |= (1 << USART_DoubleTransmissionSpeedEnableBit);
}

#define USART_ControlAndStatusRegisterC UCSR0C
#define USART_ModeSelectBit0 UMSEL00
#define USART_ModeSelectBit1 UMSEL01
#define USART_StopBitsSelectBit USBS0
#define USART_ValueToEnableTwoStopBits 1
#define USART_SizeCharacterOfBaudBit0 UCSZ00
#define USART_SizeCharacterOfBaudBit1 UCSZ01
#define USART_SizeCharacterOfBaudBit2 UCSZ02
#define USART_SynchronousModeEnableBits (0 << USART_ModeSelectBit0) | (0 << USART_ModeSelectBit1)
#define USART_BitsToEnable8BitsSizeOfBaud (1 << USART_SizeCharacterOfBaudBit0) | (1 << USART_SizeCharacterOfBaudBit1) | (1 << USART_SizeCharacterOfBaudBit2)

inline void ConfigureIO_USART() {
    USART_ControlAndStatusRegisterC |= USART_SynchronousModeEnableBits;
    USART_ControlAndStatusRegisterC |= (USART_ValueToEnableTwoStopBits << USART_StopBitsSelectBit);
    USART_ControlAndStatusRegisterC |= USART_BitsToEnable8BitsSizeOfBaud;
} 

void TransmitSymbol_By_USART( unsigned char Symbol );

void TransmitString_By_USART( const char *ElementString );

#endif