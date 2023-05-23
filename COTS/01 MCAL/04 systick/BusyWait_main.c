#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"


/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	/*	System Clock Init			*/
	RCC_voidSysClkInit();
	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	
	/*	SysTick	Init				*/
	STK_voidInit();
	while(1)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		STK_voidSetBusyWait(1000000);
		
		STK_voidSetBusyWait(2000000);
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);		
		STK_voidSetBusyWait(1000000);
	}
	return 0;
}



