#include "../include/Config_Interrupts.hpp"
#include "../include/Display_LCD.hpp"
#include "../include/IODataUSART.hpp"

ISR(USART_RX_vect) {
    TransmitSymbol_By_USART(UDR0);    
}