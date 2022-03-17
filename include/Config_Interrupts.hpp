#ifndef CONFIG_INTERRUPTS_HPP
#define CONFIG_INTERRUPTS_HPP

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

inline void EnableGlobalInterrupts(){
    SREG |= (1 << 7);
}

ISR(USART_RX_vect);

#endif