#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include 	"EXTI_interface.h"
#include	"NVIC_interface.h"
#include	"STK_interface.h"
#include 	"DMA_interface.h"
#include   "Dio_interface.h"
#include  "LED_interfce.h"
#include "Buzzer_interfce.h"
#include "lCD_interface.h"
#include "ADC_interface.h"
#include "7segment_interface.h"
#include "UART1_interface.h"

void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
int main()
{
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2,14);//uart rcc
	RCC_voidEnablePerClk(RCC_APB2,0);// alternate function rcc
	RCC_voidEnablePerClk(RCC_APB2,2);// gpio port a rcc
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_2MHZ_AFPP);
	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT);
	UART_init();
	seg_Setconnection(PORTA,PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1);

	UART_VoidSenddata('1');


	u8 Rx ;

	while (1){
		UART_voidRseivedata(&Rx);
		if(Rx == '1')
		{
			seg_printNum(1);
			_delay_ms(500);
		}
		else
		{
			seg_printNum(0);
			_delay_ms(500);
		}
	}

	return 0;
}
