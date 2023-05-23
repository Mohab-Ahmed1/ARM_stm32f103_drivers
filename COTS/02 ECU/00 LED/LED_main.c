#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include   "Dio_interface.h"
int main()
{
	//	System Clock Init
	RCC_voidSysClkInt();
	//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);
	RCC_voidEnablePerClk(RCC_APB2,3);
	//	C13 Direction 	"Output @ 2MHz Push Pull"
	LED_int(PORTC,PIN13);

	while(1)
	{
		//		Led On
		LED_toogle(PORTC,PIN13);

		//	Led Off

		_delay_ms(1000);
	}
	return 0;
}