
#ifndef		NULL
#define		NULL			((void *)0)
#endif


#include	"EXTI_interface.h"



static	void	(*EXTI0_CallBack)	(void)	= NULL;
//static	void	(*EXTI_CallBack[16])	(void)	= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void		EXTI0_voidInit(void)
{

	/*		How many Groups and Sub Group used in the system	*/
	#ifndef			AFIO_EXTICR
		#define		AFIO_EXTICR_ADD		(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_EXTICR_ADD+0x08))
	#endif

	CLR_BIT(AFIO_EXTICR1,0);
	CLR_BIT(AFIO_EXTICR1,1);
	CLR_BIT(AFIO_EXTICR1,2);
	CLR_BIT(AFIO_EXTICR1,3);

	EXTI_voidDisableInt(0);
	SET_BIT(EXTI->PR,0);
}

void		EXTI_voidInit(u8 EXTI_NUM,u8 Pin_number){

    #ifndef			AFIO_EXTICR
		#define		AFIO_EXTICR_ADD		(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_EXTICR_ADD+0x08))
	#endif

	switch(EXTI_NUM){
	case EXTI0 :
		switch(Pin_number){
		case PORTA:  CLR_BIT(AFIO_EXTICR1,0);
					 CLR_BIT(AFIO_EXTICR1,1);
					 CLR_BIT(AFIO_EXTICR1,2);
					 CLR_BIT(AFIO_EXTICR1,3);

					 EXTI_voidDisableInt(0);
					 SET_BIT(EXTI->PR,0);   break;

		case PORTB:	SET_BIT(AFIO_EXTICR1,0);
					CLR_BIT(AFIO_EXTICR1,1);
					CLR_BIT(AFIO_EXTICR1,2);
					CLR_BIT(AFIO_EXTICR1,3);

					EXTI_voidDisableInt(0);
					SET_BIT(EXTI->PR,0); 	  break;

		case PORTC: CLR_BIT(AFIO_EXTICR1,0);
					SET_BIT(AFIO_EXTICR1,1);
					CLR_BIT(AFIO_EXTICR1,2);
					CLR_BIT(AFIO_EXTICR1,3);

					EXTI_voidDisableInt(0);
					SET_BIT(EXTI->PR,0);  break;
		}break;
	//	case EXTI1 :



	}


}



void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}
void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{

	if(Fptr != NULL)
	{
		 EXTI0_CallBack = Fptr ;
	}
}


void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	//	Clear the Flag


}


/*
void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 ID_EXTI)
{
	if(Fptr != NULL)
	{
		EXTI_CallBack[ID_EXTI] = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack[0] !=NULL){
	EXTI_CallBack[0]();
	SET_BIT(EXTI-> PR ,0 );
	}
		Clear the Flag
}

void	EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[1]!=NULL){
	EXTI_CallBack[1]();
	SET_BIT(EXTI-> PR ,1 );
	}
		Clear the Flag
}*/

