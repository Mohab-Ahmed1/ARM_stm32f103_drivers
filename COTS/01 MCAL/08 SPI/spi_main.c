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
#include "SPI_interface.h"

void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
int main (){
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 12); //rcc clock for spi1
	RCC_voidEnablePerClk(RCC_APB2, 0);//rcc clock for Alternate function
	RCC_voidEnablePerClk(RCC_APB2, 2);  //rcc clock for gpio A
	RCC_voidEnablePerClk(RCC_APB2, 4);  //rcc clock for gpio C
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_10MHZ_AFPP); //clk
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT);		//MISO
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_10MHZ_AFPP);//MOSI
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_10MHZ_PP); //ss
	SPI_VoidInit();
	SET_BIT(SPI->CR1,8)	; //value of this bit forced on the NSS pin
	//DISABLE ALL INTERRUPT
	SPI->CR2=0;

	LED_int(PORTC, PIN13);
	DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
	int flg=0;
	while(1){
		if (flg==0){
			SPI_VoidSenddata('A');
			flg=1;
			}else{
			SPI_VoidSenddata('B');
			flg=0;
		}
		u8 Read =0;
		SPI_voidRseivedata(&Read);
		if(Read=='A'){
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_LOW);
			_delay_ms(1000);
			}else{
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
			_delay_ms(1000);
		}
	}
	return 0;
}
