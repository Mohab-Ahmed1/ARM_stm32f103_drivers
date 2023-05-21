#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"

void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);		
		flag	=	0;
	}
}

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
	
	/*	Call Single Periodic 		*/
	STK_voidSetIntervalPeriodic(1000000, ToggleLed);

	while(1)
	{

	}
	return 0;
}



