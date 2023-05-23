#ifndef UART1_private_h_
#define UART1_private_h_



typedef		struct
{	u32				SR;
	u32				DR;
	u32				BRR;
	u32				CR1;
	u32				CR2;
	u32				CR3;
	u32				GTPR;
}UART1_Types;

#define		UART1		((volatile UART1_Types*)(0x40013800))

#endif
