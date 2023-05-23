
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include   "Dio_interface.h"

int main()
{
	//	System Clock Init
	RCC_voidSysClkInt();
	//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	//	C13 Direction 	"Output @ 2MHz Push Pull"

	LCD_4_bit_intalize();
	Lcd_4_bit_sendstring("mohab");
	Lcd_4_bit_courserposition(2,5);
	Lcd_4_bit_sendstring("Ahmed");


	


	while(1)
	{

	}
	return 0;
}