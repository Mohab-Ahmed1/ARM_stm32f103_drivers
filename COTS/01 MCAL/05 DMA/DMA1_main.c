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