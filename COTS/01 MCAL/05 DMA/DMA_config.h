#ifndef		DMA_config
#define		DMA_config

#define Num_channels    1
/*typedef		struct
{
	u8 DMA_use_channel,

	u8 DMA_priority_channel,
	u32 DMA_Sourse_channel,
	u32 DMA_Destination_channel,
	u32 DMA_MincEnable_channel,
	u32 DMA_PincEnable_channel,

}channel_array;*/


/*##############################################*/
/*channel 1 */

typedef enum{
	channeL1,
	channeL2,
	channeL3,
	channeL4,
	channeL5,
	channeL6,
	channeL7,

}channelID;
#define		channelID   channeL1
typedef enum {
	MtoM_enable ,
	MtoM_disable
}MemorytoMemory;

# define   DMA_MemoToMemo_channel1 MtoM_enable

typedef enum {
	low ,
	medium,
	High,
	veryhigh
}priority;
#define		DMA_priority_channel1  veryhigh

typedef enum {
	bits_8 ,
	bits_16 ,
	bits_32
}SIZE;

#define		DMA_Msize_channel   bits_32
#define		DMA_Psize_channel   bits_32

typedef enum {
	enable,
	disable
}MINC_PINC_cIRC_enable;

#define		DMA_MINC_channel   enable
#define		DMA_PINC_channel   enable
#define		DMA_CIRC_channel   disable

typedef enum {
	peripheral,
	memmory
}DIRC_config;

#define DMA_DIRC_channel  peripheral

typedef enum {
	Flag_enable,
	Flag_disable
}Interrupts_enable;

#define DMA_TransError_channel  Flag_disable
#define DMA_HalfTransfer_channel  Flag_disable
#define DMA_TransComplete_channel  Flag_enable



#endif












