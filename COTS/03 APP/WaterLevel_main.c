
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

//water level main.c
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
	RCC_voidEnablePerClk(RCC_APB2,2); //port B
	RCC_voidEnablePerClk(RCC_APB2,3);//port A

	//leds intalize
	LED_int(PORTB,PIN12);
	LED_int(PORTB,PIN13);
	LED_int(PORTB,PIN14);
	Buzzer_int(PORTB,PIN15);
	seg_Setconnection(PORTA,PIN6,PIN7,PIN3,PIN2,PIN1,PIN5,PIN4);

	//level 1 ...//green led
	DIO_voidSetPinDirection(PORTB, PIN11, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTB, PIN11, GPIO_LOW);

	//level 2 ...//red led
	DIO_voidSetPinDirection(PORTB, PIN10, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTB, PIN10, GPIO_LOW);

	//level 3 ...//blue led // buzzer on
	DIO_voidSetPinDirection(PORTB, PIN1, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTB, PIN1, GPIO_LOW);


	while(1)
	{
		//level 1 ...//green led
		if(DIO_u8GetPinValue(PORTB,PIN11)==1){
			LED_on(PORTB, PIN12);

			}else{
			LED_off(PORTB, PIN12);
		}

		//level 2 ...//red led
		if(DIO_u8GetPinValue(PORTB,PIN10)==1){
			LED_on(PORTB, PIN13);

			}else{
			LED_off(PORTB, PIN13);
		}

		//level 3 ...//blue led // buzzer on
		if(DIO_u8GetPinValue(PORTB,PIN1)==1){
			LED_on(PORTB, PIN14);
			Buzzer_on(PORTB,PIN15);


			}else{
			LED_off(PORTB, PIN14);
			Buzzer_off(PORTB,PIN15);
		}
		//sevensegment number

		if(DIO_u8GetPinValue(PORTB,PIN11)+DIO_u8GetPinValue(PORTB,PIN10)+DIO_u8GetPinValue(PORTB,PIN1)==1){
			seg_printNum(1);
			}else if(DIO_u8GetPinValue(PORTB,PIN11)+DIO_u8GetPinValue(PORTB,PIN10)+DIO_u8GetPinValue(PORTB,PIN1)==2){
			seg_printNum(2);
			}else if(DIO_u8GetPinValue(PORTB,PIN11)+DIO_u8GetPinValue(PORTB,PIN10)+DIO_u8GetPinValue(PORTB,PIN1)==3){
			seg_printNum(3);
			}else{
			seg_printNum(0);
		}

	}
}