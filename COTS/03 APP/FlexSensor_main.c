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


//flex sensor main.c
void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
float Temperature;
u16 ADC_Value;
int main()
{
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 9); // enable ADC1 clock
	RCC_voidEnablePerClk(RCC_APB2, 2);  // enable GPIOA clock
	RCC_ADC_SETprescaler(divided4);
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_ANALOG);
	ADC_channelSetup(ADC_channe0,SEQ1,cycles_1_5);

	ADC_voidInit();
	ADC_voidEnable();
	ADC_Start();
	seg_Setconnection(PORTA,PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1);
	while(1)
	{
		ADC_Value	= ADC1->DR &0x0000FFFF;
		_delay_ms(1000);
		if(ADC_Value>600){
			seg_printNum(1);
			}else if(ADC_Value<600 &&ADC_Value>300){
			seg_printNum(2);
			}else if(ADC_Value<300 ){
			seg_printNum(3);
			}else{

		}
	}
	return 0;
}

