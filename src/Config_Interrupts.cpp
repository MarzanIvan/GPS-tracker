#include "../include/Config_Interrupts.h"
#include "../include/Buffer.h"
#include "../include/Display_LCD.h"
#include "../include/IODataUSART.h"

Stream_Buffer Buffer;

ISR(USART_RX_vect) {
    char Data = UDR0;
    char Descriptor = 0x01;
    if (Buffer.LockBuffer(Descriptor)) {
        Buffer.Push(Data);
        Buffer.UnlockBuffer(Descriptor);
    }
}

ISR(USART_UDRE_vect) {
    char Descriptor = 0x03;
    char* Data = 0;
    if (Buffer.LockBuffer(Descriptor)) {
        Data = Buffer.PullAll();

        *Buffer.Stack = '\0';
        Buffer.IndexOfNextElement = 0;
    }
}