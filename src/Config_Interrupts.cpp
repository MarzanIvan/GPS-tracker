#include "../include/Config_Interrupts.h"
#include "../include/Buffer.h"

Stream_Buffer Buffer;

ISR(USART_RX_vect) {
    char Descriptor = 0x01;
    if (Buffer.StateOfBuffer == FREE) {
        Buffer.LockBuffer(Descriptor);
        Buffer.Push(UDR0);
        Buffer.UnlockBuffer(Descriptor);
    }
}