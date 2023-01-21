#include "../include/Config_Interrupts.h"
#include "../include/Buffer.h"

Stream_Buffer Buffer;

ISR(USART_RX_vect) {
    if (Buffer.StateOfBuffer == FREE) {

    }
}