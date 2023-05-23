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


 //ADC_temperature main.c

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
	 //temp sensor channel config
	 ADC_channelSetup(ADC_channe16,SEQ1,cycles_239_5);
	 ADC_voidInit();
	 ADC_voidEnable();
	 ADC_Start();
	 while(1)
	 {
		 ADC_Value	= ADC1->DR &0x0000FFFF;
		 Temperature = ((1.43 - ((float)(3.3*ADC_Value/(float)4095))) / 0.0043) + 15;
		 _delay_ms(1000);
	 }
	 return 0;
 }
