#include "../include/Config_Interrupts.h"
#include "../include/Buffer.h"
#include "../include/Display_LCD.h"
#include "../include/IODataUSART.h"
#include "../include/GPS-Data.h"

Stream_Buffer Buffer;
GPSData GPSDataStruct;

ISR(USART_RX_vect) {
    char Data = UDR0;
    char Descriptor = 0x01;
    if (Buffer.LockBuffer(Descriptor)) {
        Buffer.Push(Data);
        Buffer.UnlockBuffer(Descriptor);
    }
}

ISR(USART_UDRE_vect) {
    
}