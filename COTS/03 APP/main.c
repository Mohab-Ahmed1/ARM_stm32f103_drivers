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





//flex sensor main.c
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
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_ANALOG);
	ADC_channelSetup(ADC_channe0,SEQ1,cycles_1_5);

	ADC_voidInit();
	ADC_voidEnable();
	ADC_Start();
	seg_Setconnection(PORTA,PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1);
	while(1)
	{
	ADC_Value	= ADC1->DR &0x0000FFFF;
	_delay_ms(1000);
if(ADC_Value>600){
	seg_printNum(1);
	}else if(ADC_Value<600 &&ADC_Value>300){
		seg_printNum(2);
	}else if(ADC_Value<300 ){
		seg_printNum(3);
	}else{

	}
	}
	return 0;
	}








/*
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
*/







/*
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
*/






/*

//DMA_main.c
u32	Processor_Arr1[500];
u32	Processor_Arr2[500];

u32	DMA_Arr3[500];
u32	DMA_Arr4[500];
void	IRQ(void);
int main()
{
	DMA1_voidSetCallBack(IRQ);

	for(u16 i = 0 ; i < 500 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}

		System init
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_AHB,0);
	NVIC_voidEnablePerInt(11);
	DMA1_voidChannelInit();
		DMA1 Channel Transfere Round
	DMA1_voidStartChannel(DMA_Arr3,DMA_Arr4,500);

		Processor Transfere Round
	for(u16 i = 0 ; i < 500 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}
while(1)
{}
return 0;
}
void	IRQ(void)
{
	u8 x=100;
	GET_BIT(x,1);
}
*/




/*
//periodicainterval_main.c

void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
				Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
				Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		flag	=	0;
	}
}

	C13 ==> Built in led (Toggle Led)
int main()
{
		System Clock Init
	RCC_voidSysClkInt();
		Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

		C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

		SysTick	Init
	STK_voidInit();

		Call Single Periodic
	STK_voidSetIntervalPeriodic(1000000, ToggleLed);

	while(1)
	{

	}
	return 0;
}

*/




/*


//single interval main.c

void	ToggleLed(void)
{
	static	u8 flag	=	0;
	if(flag	==	0)
	{
				Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		flag	=	1;
	}
	else
	{
				Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		flag	=	0;
	}
}

	C13 ==> Built in led (Toggle Led)
int main()
{
		System Clock Init
	RCC_voidSysClkInt();
		Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

		C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
		SysTick	Init
	STK_voidInit();

		Call Single Interval
		LED ON in the CallBack
	STK_voidSetIntervalSingle(1000000, ToggleLed);


	STK_voidSetBusyWait(2000000);
		LED OFF in the CallBack
	STK_voidSetIntervalSingle(1000000, ToggleLed);

	while(1)
	{

	}
	return 0;
}


*/





/*

//busywait_main.c

	C13 ==> Built in led (Toggle Led)
int main()
{
		System Clock Init
	RCC_voidSysClkInt();
		Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

		C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

		SysTick	Init
	STK_voidInit();
	while(1)
	{
				Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		STK_voidSetBusyWait(1000000);

		STK_voidSetBusyWait(2000000);
				Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		STK_voidSetBusyWait(1000000);
	}
	return 0;
}*/









/*

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























//Nvic_main.c

/*

void	EXTI0_IRQHandler(void);

int main(void)
{
		System Clock Init
	RCC_voidSysClkInt();

		Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,4);

		C13 Direction 	"Output @ 2MHz Push Pull"
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

		Interrupt Initialization
	NVIC_voidInit();

		Set pending Flag EXTI0
	NVIC_voidSetPendingFlag(6);

		Set pending Flag EXTI1
		NVIC_voidSetPendingFlag(7);

		//set priority for EXTI0 to group 0 subgroup0
     NVIC_voidSetSwIntPriority(6, 0b0000);

		//set priority for EXTI1  to group 0 subgroup1
    NVIC_voidSetSwIntPriority(7, 0b0100);


		NVIC EXTI0 Enable
	NVIC_voidEnablePerInt(6);
	_delay_ms(1000);

		NVIC EXTI0 Enable
		NVIC_voidEnablePerInt(7);

	while(1)
	{

	}
	return 0;
}

//void 	__vector_1(void)
void	EXTI0_IRQHandler(void)
{
				Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		_delay_ms(1000);

				Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		_delay_ms(1000);

		while(1){}
		Clear EXTI0 Flag
}
void	EXTI1_IRQHandler(void)
{
				Led On
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		_delay_ms(1000);

				Led Off
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		_delay_ms(1000);
		Clear EXTI0 Flag
}



*/




//lcd_main.c
/*

int main()
{
	//	System Clock Init
	RCC_voidSysClkInt();
	//	Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	//	C13 Direction 	"Output @ 2MHz Push Pull"
	char shape[8]={0x04,0x0E,0x0E,0x0E,0x1F,0x00,0x04,0x00};
	LCD_4_bit_intalize();
Lcd_4_bit_sendstring("mohab");
  Lcd_4_bit_courserposition(2,5);
Lcd_4_bit_sendstring("Ahmed");


	Lcd_4_bit_createcustomchar(shape,0);
	Lcd_4_bit_printCustomChar(0);


	while(1)
	{

	}
	return 0;
}

*/




//led _main.c
/*


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


*/

//gpio_main.c

/*
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
}*/



