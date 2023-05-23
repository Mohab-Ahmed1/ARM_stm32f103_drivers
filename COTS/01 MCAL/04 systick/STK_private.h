#ifndef		EXTI_private_h
#define		EXTI_private_h

#define		STK_AHB_DIV_8			0
#define		STK_AHB					1

#define		STK_SINGLE_INTERVAL		0
#define		STK_PERIOD_INTERVAL		1

typedef struct
{
	u32		CTRL;
	u32		LOAD;
	u32		VAL;
	u32		CALIB;
	
}STK_Type;

#define			STK		((STK_Type *)(0xE000E010))


#endif
