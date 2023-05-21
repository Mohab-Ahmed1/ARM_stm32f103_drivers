#include "UART1_interface.h"

void UART_init() {

UART1_setBaudRate();
UART_enableRX();
UART_enableTX();
SET_BIT(UART1->CR1,13);//uart enable

while (!GET_BIT(UART1->SR,6));

}

//enable transmitter
void UART_enableTX(void) {

	SET_BIT(UART1->CR1,3);
}
//enable receiver
void UART_enableRX(void) {
	SET_BIT(UART1->CR1,2);
}
//transmit data
void UART_VoidSenddata(u8 data){
	 while (!GET_BIT(UART1->SR, 7));

	    // Send character
	 UART1->DR = data;
}
//receive data
void UART_voidRseivedata (u8 *data ) {
	 while (!GET_BIT(UART1->SR, 5));

	    // Return received character
	 *data= UART1->DR;

}

void UART1_voidSendString(u8 *str)
{  while (*str != '\0'){
	UART_VoidSenddata(*str);
	str++;
}

}
void UART1_StrReceiveString(u8 *str)
{
	while (*str != '\0'){
		UART_voidRseivedata(str);
		str++;
	}

}

void UART1_setBaudRate(){
	switch(UART1_clock){
	case UART1_8MHZ:
		switch(UART1_baudrate){
		case UART1_9600: UART1->BRR = 0x341;  break;
		case UART1_115200: UART1->BRR = 0x45;  break;
		}
		break;
	case UART1_72MZ:
		switch(UART1_baudrate){
		case UART1_9600: UART1->BRR = 0x1D4C;  break;
		case UART1_115200: UART1->BRR = 0x271;  break;
		}
		break;
	}
}

