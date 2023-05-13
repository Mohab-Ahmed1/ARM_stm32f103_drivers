




u32	Processor_Arr1[1000];
u32	Processor_Arr2[1000];

u32	DMA_Arr3[1000];
u32	DMA_Arr4[1000];


int main()
{
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}
	
	/*	System init			*/
	RCC_voidSysClkInit();
	DMA1_voidChannelInit();
	/*	DMA1 Channel Transfere Round	*/
	DMA1_voidStartChannel(DMA_Arr3,DMA_Arr4,1000);
	
	/*	Processor Transfere Round	*/
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}
	
	

while(1)
{

}

return 0;
}

void	DMA1_Channel1_IRQHandler()
{
	/*		Toggle led		*/
}
