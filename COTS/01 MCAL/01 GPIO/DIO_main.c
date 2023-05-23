#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include   "Dio_interface.h"

 void _delay_ms(u32 ticks){
	 u32 i;
	 for( i = 0; i < (ticks*500) ; i++)
	 {
		 asm("NOP");
	 }
 }
int main()
{
	//	System Clock Init
	RCC_voidSysClkInt();
	//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

	//	C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

	while(1)
	{
		//		Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		_delay_ms(1000);
		//	Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		_delay_ms(1000);
	}
	return 0;
}