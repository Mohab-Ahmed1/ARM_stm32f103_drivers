#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"NVIC_interface.h"
#include   "Dio_interface.h"

void	EXTI0_IRQHandler(void);
 void _delay_ms(u32 ticks){
	 u32 i;
	 for( i = 0; i < (ticks*500) ; i++)
	 {
		 asm("NOP");
	 }
 }
int main(void)
{
	//System Clock Init
	RCC_voidSysClkInt();

//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

//	C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

//	Interrupt Initialization
	NVIC_voidInit();

//	Set pending Flag EXTI0
	NVIC_voidSetPendingFlag(6);

//	Set pending Flag EXTI1
	NVIC_voidSetPendingFlag(7);

	//set priority for EXTI0 to group 0 subgroup0
	NVIC_voidSetSwIntPriority(6, 0b0000);

	//set priority for EXTI1  to group 0 subgroup1
	NVIC_voidSetSwIntPriority(7, 0b0100);


//	NVIC EXTI0 Enable
	NVIC_voidEnablePerInt(6);
	_delay_ms(1000);

	//NVIC EXTI0 Enable
	NVIC_voidEnablePerInt(7);

	while(1)
	{

	}
	return 0;
}

//void 	__vector_1(void)
void	EXTI0_IRQHandler(void)
{
	//Led On
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
	_delay_ms(1000);

	//Led Off
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
	_delay_ms(1000);

	while(1){}
	//Clear EXTI0 Flag
}
void	EXTI1_IRQHandler(void)
{
//	Led On
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
	_delay_ms(1000);

//	Led Off
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
	_delay_ms(1000);
	//Clear EXTI0 Flag
}

