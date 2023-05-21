
#ifndef		EXTI_interface_h
#define		EXTI_interface_h


#include	"Bit_Math.h"
#include	"Std_Types.h"
#include	"EXTI_private.h"
#include	"EXTI_config.h"
#include  "DIO_interface.h"

/*

#define RISING_EDGE 0

#define FALLING_EDGE 1

#define IOC 3
*/

enum{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3
};

typedef enum{
	RISING_EDGE ,
	FALLING_EDGE ,
	IOC
}sensMode;

void		EXTI0_voidInit(void);
void		EXTI_voidInit(u8 EXTI_NUM,u8 Pin_number);



void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);

void		EXTI0_voidSetCallBack(void (*Fptr)(void));
//void		EXTI_voidSetCallBack(void (*Fptr)(void), u8  ID_EXTI);
#endif
