#pragma once

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include <avr/io.h>

inline void SetSpeedUSART( unsigned int SpeedIO );

inline void EnableIO_USART();

inline void EnableInterruptReadUSART();

inline void DoubleTransmissionSpeedUSART();

inline void ConfigureIO_USART();

void TransmitData_By_USART( unsigned char data );