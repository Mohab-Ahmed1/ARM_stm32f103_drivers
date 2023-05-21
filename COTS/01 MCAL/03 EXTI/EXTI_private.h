#ifndef		EXTI_private_H
#define		EXTI_private_H

#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;

}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))



#endif

