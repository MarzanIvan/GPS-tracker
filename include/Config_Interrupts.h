#ifndef CONFIG_INTERRUPTS_H
#define CONFIG_INTERRUPTS_H

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

inline void DisableGlobalInterrupts() {
    SREG &= ~(1 << 7);
}

inline void EnableGlobalInterrupts() {
    SREG |= (1 << 7);
}

ISR(USART_RX_vect);

#endif