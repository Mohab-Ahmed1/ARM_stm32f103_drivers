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

//external_interup main.c

void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
			{
				asm("NOP");
			}
}

void EXTI_ISR(void);
int main(void)
{

	EXTI0_voidSetCallBack(EXTI_ISR);
RCC_voidSysClkInt();  //intalize clock
RCC_voidEnablePerClk(RCC_APB2, 0); //intalize clock to perephral
RCC_voidEnablePerClk(RCC_APB2, 4);
RCC_voidEnablePerClk(RCC_APB2, 2);


//configure the pin A0 as input
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH);

	DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);

//intalize EXT port
	EXTI0_voidInit();
	//EXTI_voidInit(0,0);
	EXTI_voidEnableInt(0);
	EXTI_voidChangeSenseMode(0,FALLING_EDGE);

	NVIC_voidEnablePerInt(6);




	while(1)
		{

		}
		return 0;


}


void EXTI_ISR(void){

	//Clear the Flag
		SET_BIT(EXTI->PR,0);
		DIO_voidtogglepin(PORTC, PIN13);

}

*/


/*


void	EXTI0_IRQHandler(void)
{

	//	Clear the Flag
	SET_BIT(EXTI->PR,0);


	DIO_voidtogglepin(PORTC, PIN13);



}
*/

