#ifndef UART1_interface_h_
#define UART1_interface_h_
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"UART1_private.h"
#include  "UART1_config.h"
/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/
void UART_init(void);

//enable transmitter
void UART_enableTX(void);
//enable receiver
void UART_enableRX(void);
//transmit data
void UART_VoidSenddata(u8 data);
//receive data
void UART_voidRseivedata (u8 *data );

void UART1_voidSendString(u8 *str);
void UART1_StrReceiveString(u8 *str);


void UART1_setBaudRate();


#endif
