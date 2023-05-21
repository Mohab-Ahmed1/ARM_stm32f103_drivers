

#include "DMA_interface.h"

#ifndef		NULL
#define		NULL			((void *)0)
#endif

static	void	(*DMA1_CallBack)	(void)	= NULL;


//	Memory to Memory
void DMAMemory_toMemory (u8 channelID ,u8 MemoToMemo_channel ){
		if (MemoToMemo_channel == MtoM_enable ){
	SET_BIT(DMA1->Channel[channelID].CCR,14);
	}else if (MemoToMemo_channel == MtoM_disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,14);
	}else{
	//#error "wrong memmory configration "
	}
}
//	priority very high
void DMA_setpriority (u8 channelID ,u8 priority_channel ){
if ( priority_channel == low){
	CLR_BIT(DMA1->Channel[channelID].CCR,12);
	CLR_BIT(DMA1->Channel[channelID].CCR,13);
}else if  (priority_channel == medium){
	SET_BIT(DMA1->Channel[channelID].CCR,12);
	CLR_BIT(DMA1->Channel[channelID].CCR,13);
}else if (priority_channel == High){
	CLR_BIT(DMA1->Channel[channelID].CCR,12);
	SET_BIT(DMA1->Channel[channelID].CCR,13);
}else if( priority_channel == veryhigh){
	SET_BIT(DMA1->Channel[channelID].CCR,12);
	SET_BIT(DMA1->Channel[channelID].CCR,13);
}else {
	// #error"wrong channel priority"
}
	}
//	Size (Source & Destination) u32
void DMA_SetMsize_setPsize(u8 channelID ,u8 Msize_channel,u8 Psize_channel ){
if ( Msize_channel == bits_8){
	CLR_BIT(DMA1->Channel[channelID].CCR,10);
	CLR_BIT(DMA1->Channel[channelID].CCR,11);
}else if( Msize_channel ==bits_16){
	SET_BIT(DMA1->Channel[channelID].CCR,10);
	CLR_BIT(DMA1->Channel[channelID].CCR,11);
}else if( Msize_channel ==bits_32){
	CLR_BIT(DMA1->Channel[channelID].CCR,10);
	SET_BIT(DMA1->Channel[channelID].CCR,11);
}else {
	// #error"wrong Msize NUM"
	}
if (Psize_channel == bits_8){
	CLR_BIT(DMA1->Channel[channelID].CCR,8);
	CLR_BIT(DMA1->Channel[channelID].CCR,9);
}else if( Psize_channel ==bits_16){
	SET_BIT(DMA1->Channel[channelID].CCR,8);
	CLR_BIT(DMA1->Channel[channelID].CCR,9);
}else if(Psize_channel ==bits_32){
	CLR_BIT(DMA1->Channel[channelID].CCR,8);
	SET_BIT(DMA1->Channel[channelID].CCR,9);
}else {
	//#error "wrong Psize NUM"
	}
}

//	MINC, PINC enabled
void DMA_SetMINC_setPINC_setCIRC(u8 channelID ,u8 MINC_channel,u8 PINC_channel,u8 CIRC_channel){
if (MINC_channel == enable){
	SET_BIT(DMA1->Channel[channelID].CCR,7);
}else if( MINC_channel == disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,7);
}else{
	//#error "Wrong MINC config"
}
if (PINC_channel == enable){
	SET_BIT(DMA1->Channel[channelID].CCR,6);
}else if( PINC_channel == disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,6);
}else{
//	#error "Wrong PINC config"
	}
if (CIRC_channel == enable){
	SET_BIT(DMA1->Channel[channelID].CCR,5);
}else if (CIRC_channel == disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,5);
}else{
	//#error "Wrong CIRC config"
	}
}

/*#####################################*/

void	DMA1_voidChannelInit(){

//	Memory to Memory
DMAMemory_toMemory(channelID,DMA_MemoToMemo_channel1);
//	priority very high
DMA_setpriority (channelID , DMA_priority_channel1 );
//	Size (Source & Destination) u32
DMA_SetMsize_setPsize(channelID ,DMA_Msize_channel,DMA_Psize_channel);


//	MINC, PINC enabled
DMA_SetMINC_setPINC_setCIRC(channelID,DMA_MINC_channel,DMA_PINC_channel,DMA_CIRC_channel);

//	Transfere Complete Interrupt
if (DMA_TransError_channel == Flag_disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,3);
}else if (DMA_TransError_channel == Flag_enable){
	SET_BIT(DMA1->Channel[channelID].CCR,3);
}else{
	//#error "Wrong TEIE config"
	}

if (DMA_HalfTransfer_channel == Flag_disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,2);
}else if (DMA_HalfTransfer_channel == Flag_enable){
	SET_BIT(DMA1->Channel[channelID].CCR,2);
}else{
//	#error "Wrong HTIE config"
}

if (DMA_TransComplete_channel == Flag_disable){
	CLR_BIT(DMA1->Channel[channelID].CCR,1);
}else if (DMA_TransComplete_channel == Flag_enable){
	SET_BIT(DMA1->Channel[channelID].CCR,1);
}else{
	//#error "Wrong TCIE config"
}
//	Channel Disable
	CLR_BIT(DMA1->Channel[channelID].CCR,0);

	//DMA1 ->	Channel[0].CCR = 0x00007AC2;
}

void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[0].CCR,0);

	DMA1 -> Channel[0].CPAR	=	SrcAdd;
	DMA1 -> Channel[0].CMAR	=	DestAdd;

	/*	Load the Block Length				*/
	DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to strat transfere*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);
}



void		DMA1_voidSetCallBack(void (*Fptr)(void))
{

	if(Fptr != NULL)
	{
		DMA1_CallBack = Fptr ;
	}
}


void	DMA1_Channel1_IRQHandler(void)
{
	DMA1_CallBack();
	//	Clear the Flag


}


