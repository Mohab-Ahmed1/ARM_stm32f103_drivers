#ifndef		DMA_interface
#define		DMA_interface

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "DMA_config.h"
#include    "DMA_private.h"


void	DMA1_voidChannelInit(void);
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);

//helping functions
void DMAMemory_toMemory (u8 channelID ,u8 MemoToMemo_channel );
void DMA_setpriority (u8 channelID ,u8 priority_channel );
void DMA_SetMsize_setPsize(u8 channelID ,u8 Msize_channel,u8 Psize_channel );
#endif
