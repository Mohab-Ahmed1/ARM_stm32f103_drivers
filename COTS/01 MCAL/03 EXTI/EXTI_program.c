
#ifndef		NULL
#define		NULL			((void *)0)
#endif


#include	"EXTI_interface.h"



static	void	(*EXTI0_CallBack)	(void)	= NULL;
static	void	(*EXTI_CallBack[16])	(void)	= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
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

void		EXTI_voidInit(u8 EXTI_NUM,u8 Pin_number){ //configured till EXTI7

    #ifndef			AFIO_EXTICR
		#define		AFIO_EXTICR_ADD		(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_EXTICR_ADD+0x08))
	#endif

	/*		How many Groups and Sub Group used in the system	*/
		#ifndef			AFIO_EXTICR
			#define		AFIO_EXTICR_ADD		(0x40010000)
			#define		AFIO_EXTICR2			*((u32 *)(AFIO_EXTICR_ADD+0x0C))
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

	case EXTI1 :
		switch(Pin_number){
								case PORTA:  CLR_BIT(AFIO_EXTICR1,4);
											 CLR_BIT(AFIO_EXTICR1,5);
											 CLR_BIT(AFIO_EXTICR1,6);
											 CLR_BIT(AFIO_EXTICR1,7);

											 EXTI_voidDisableInt(1);
											 SET_BIT(EXTI->PR,1);   break;

								case PORTB:	SET_BIT(AFIO_EXTICR1,4);
											CLR_BIT(AFIO_EXTICR1,5);
											CLR_BIT(AFIO_EXTICR1,6);
											CLR_BIT(AFIO_EXTICR1,7);

											EXTI_voidDisableInt(1);
										 SET_BIT(EXTI->PR,1);   break;

								case PORTC: CLR_BIT(AFIO_EXTICR1,4);
											SET_BIT(AFIO_EXTICR1,5);
											CLR_BIT(AFIO_EXTICR1,6);
											CLR_BIT(AFIO_EXTICR1,7);

											EXTI_voidDisableInt(1);
											SET_BIT(EXTI->PR,1);  break;
								}break;

		case EXTI2 :
				switch(Pin_number){
								case PORTA:  CLR_BIT(AFIO_EXTICR1,8);
											 CLR_BIT(AFIO_EXTICR1,9);
											 CLR_BIT(AFIO_EXTICR1,10);
											 CLR_BIT(AFIO_EXTICR1,11);

											 EXTI_voidDisableInt(2);
											 SET_BIT(EXTI->PR,2);   break;

								case PORTB:	SET_BIT(AFIO_EXTICR1,8);
											CLR_BIT(AFIO_EXTICR1,9);
											CLR_BIT(AFIO_EXTICR1,10);
											CLR_BIT(AFIO_EXTICR1,11);

											EXTI_voidDisableInt(2);
											SET_BIT(EXTI->PR,2); 	  break;

								case PORTC: CLR_BIT(AFIO_EXTICR1,8);
											SET_BIT(AFIO_EXTICR1,9);
											CLR_BIT(AFIO_EXTICR1,10);
											CLR_BIT(AFIO_EXTICR1,11);

											EXTI_voidDisableInt(2);
											SET_BIT(EXTI->PR,0);  break;
								}break;
				case EXTI3 :
						switch(Pin_number){
						case PORTA:  CLR_BIT(AFIO_EXTICR1,12);
									 CLR_BIT(AFIO_EXTICR1,13);
									 CLR_BIT(AFIO_EXTICR1,14);
									 CLR_BIT(AFIO_EXTICR1,15);

									 EXTI_voidDisableInt(3);
									 SET_BIT(EXTI->PR,3);   break;

						case PORTB:	SET_BIT(AFIO_EXTICR1,12);
									CLR_BIT(AFIO_EXTICR1,13);
									CLR_BIT(AFIO_EXTICR1,14);
									CLR_BIT(AFIO_EXTICR1,15);

									EXTI_voidDisableInt(3);
									SET_BIT(EXTI->PR,3); 	  break;

						case PORTC: CLR_BIT(AFIO_EXTICR1,12);
									SET_BIT(AFIO_EXTICR1,13);
									CLR_BIT(AFIO_EXTICR1,14);
									CLR_BIT(AFIO_EXTICR1,15);

									EXTI_voidDisableInt(3);
									SET_BIT(EXTI->PR,3);  break;
						}break;
			case EXTI4 :
							switch(Pin_number){
							case PORTA:  CLR_BIT(AFIO_EXTICR2,0);
										 CLR_BIT(AFIO_EXTICR2,1);
										 CLR_BIT(AFIO_EXTICR2,2);
										 CLR_BIT(AFIO_EXTICR2,3);

										 EXTI_voidDisableInt(4);
										 SET_BIT(EXTI->PR,4);   break;

							case PORTB:	SET_BIT(AFIO_EXTICR2,0);
										CLR_BIT(AFIO_EXTICR2,1);
										CLR_BIT(AFIO_EXTICR2,2);
										CLR_BIT(AFIO_EXTICR2,3);

										EXTI_voidDisableInt(4);
										SET_BIT(EXTI->PR,4); 	  break;

							case PORTC: CLR_BIT(AFIO_EXTICR2,0);
										SET_BIT(AFIO_EXTICR2,1);
										CLR_BIT(AFIO_EXTICR2,2);
										CLR_BIT(AFIO_EXTICR2,3);

										EXTI_voidDisableInt(4);
										SET_BIT(EXTI->PR,4);  break;
							}break;
							case EXTI5 :
								switch(Pin_number){
									case PORTA:  CLR_BIT(AFIO_EXTICR2,4);
												 CLR_BIT(AFIO_EXTICR2,5);
												 CLR_BIT(AFIO_EXTICR2,6);
												 CLR_BIT(AFIO_EXTICR2,7);
												 EXTI_voidDisableInt(5);
												 SET_BIT(EXTI->PR,5);   break;

									case PORTB:	SET_BIT(AFIO_EXTICR2,4);
												CLR_BIT(AFIO_EXTICR2,5);
												CLR_BIT(AFIO_EXTICR2,6);
												CLR_BIT(AFIO_EXTICR2,7);
												EXTI_voidDisableInt(5);
												SET_BIT(EXTI->PR,5); 	  break;

									case PORTC: CLR_BIT(AFIO_EXTICR2,4);
												SET_BIT(AFIO_EXTICR2,5);
												CLR_BIT(AFIO_EXTICR2,6);
												CLR_BIT(AFIO_EXTICR2,7);
												EXTI_voidDisableInt(5);
												SET_BIT(EXTI->PR,5);  break;
												}break;
						case EXTI6 :
							switch(Pin_number){
								case PORTA:  CLR_BIT(AFIO_EXTICR2,8);
											 CLR_BIT(AFIO_EXTICR2,9);
											 CLR_BIT(AFIO_EXTICR2,10);
											 CLR_BIT(AFIO_EXTICR2,11);
											 EXTI_voidDisableInt(6);
											 SET_BIT(EXTI->PR,6);   break;
								case PORTB:	SET_BIT(AFIO_EXTICR2,8);
											CLR_BIT(AFIO_EXTICR2,9);
											CLR_BIT(AFIO_EXTICR2,10);
											CLR_BIT(AFIO_EXTICR2,11);
											EXTI_voidDisableInt(6);
											SET_BIT(EXTI->PR,6); 	  break;
								case PORTC: CLR_BIT(AFIO_EXTICR2,8);
											SET_BIT(AFIO_EXTICR2,9);
											CLR_BIT(AFIO_EXTICR2,10);
											CLR_BIT(AFIO_EXTICR2,11);
											EXTI_voidDisableInt(6);
											SET_BIT(EXTI->PR,6);  break;
											}break;
					case EXTI7 :
						switch(Pin_number){
								case PORTA:  CLR_BIT(AFIO_EXTICR2,12);
											 CLR_BIT(AFIO_EXTICR2,13);
											 CLR_BIT(AFIO_EXTICR2,14);
											 CLR_BIT(AFIO_EXTICR2,15);
											 EXTI_voidDisableInt(7);
											 SET_BIT(EXTI->PR,7);   break;
								case PORTB:	SET_BIT(AFIO_EXTICR2,12);
											CLR_BIT(AFIO_EXTICR2,13);
											CLR_BIT(AFIO_EXTICR2,14);
											CLR_BIT(AFIO_EXTICR2,15);
											EXTI_voidDisableInt(7);
											SET_BIT(EXTI->PR,7); 	  break;
								case PORTC: CLR_BIT(AFIO_EXTICR2,12);
											SET_BIT(AFIO_EXTICR2,13);
											CLR_BIT(AFIO_EXTICR2,14);
											CLR_BIT(AFIO_EXTICR2,15);
											EXTI_voidDisableInt(7);
											SET_BIT(EXTI->PR,7);  break;
										}break;

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

/*void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{

	if(Fptr != NULL)
	{
		 EXTI0_CallBack = Fptr ;
	}
}
void	EXTI0_IRQHandler(void)
{

	EXTI0_CallBack();

	//Clear the Flag
	SET_BIT(EXTI->PR,0);

}*/



void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 ID_EXTI)
{
	if(Fptr != NULL)
	{
		EXTI_CallBack[ID_EXTI] = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{

//	EXTI0_CallBack();  //works if just using the single EXtio

	if(EXTI_CallBack[0] !=NULL){
	EXTI_CallBack[0]();
	SET_BIT(EXTI-> PR ,0 );
	}
		//Clear the Flag
}

void	EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[1]!=NULL){
	EXTI_CallBack[1]();
	SET_BIT(EXTI-> PR ,1 );
	}
		//Clear the Flag
}
void	EXTI2_IRQHandler(void)
{
	if(EXTI_CallBack[2]!=NULL){
	EXTI_CallBack[2]();
	SET_BIT(EXTI-> PR ,2 );
	}
		//Clear the Flag
}void	EXTI3_IRQHandler(void)
{
	if(EXTI_CallBack[3]!=NULL){
	EXTI_CallBack[3]();
	SET_BIT(EXTI-> PR ,3 );
	}
		//Clear the Flag
}void	EXTI4_IRQHandler(void)
{
	if(EXTI_CallBack[4]!=NULL){
	EXTI_CallBack[4]();
	SET_BIT(EXTI-> PR ,4 );
	}
		//Clear the Flag
}void	EXTI5_IRQHandler(void)
{
	if(EXTI_CallBack[5]!=NULL){
	EXTI_CallBack[5]();
	SET_BIT(EXTI-> PR ,5 );
	}
		//Clear the Flag
}void	EXTI6_IRQHandler(void)
{
	if(EXTI_CallBack[6]!=NULL){
	EXTI_CallBack[6]();
	SET_BIT(EXTI-> PR ,6 );
	}
		//Clear the Flag
}void	EXTI7_IRQHandler(void)
{
	if(EXTI_CallBack[7]!=NULL){
	EXTI_CallBack[7]();
	SET_BIT(EXTI-> PR ,7 );
	}
		//Clear the Flag
}void	EXTI8_IRQHandler(void)
{
	if(EXTI_CallBack[8]!=NULL){
	EXTI_CallBack[8]();
	SET_BIT(EXTI-> PR ,8 );
	}
		//Clear the Flag
}void	EXTI9_IRQHandler(void)
{
	if(EXTI_CallBack[9]!=NULL){
	EXTI_CallBack[9]();
	SET_BIT(EXTI-> PR ,9 );
	}
		//Clear the Flag
}void	EXTI10_IRQHandler(void)
{
	if(EXTI_CallBack[10]!=NULL){
	EXTI_CallBack[10]();
	SET_BIT(EXTI-> PR ,10 );
	}
		//Clear the Flag
}void	EXTI11_IRQHandler(void)
{
	if(EXTI_CallBack[11]!=NULL){
	EXTI_CallBack[11]();
	SET_BIT(EXTI-> PR ,11 );
	}
		//Clear the Flag
}void	EXTI12_IRQHandler(void)
{
	if(EXTI_CallBack[12]!=NULL){
	EXTI_CallBack[12]();
	SET_BIT(EXTI-> PR ,12 );
	}
		//Clear the Flag
}void	EXTI13_IRQHandler(void)
{
	if(EXTI_CallBack[13]!=NULL){
	EXTI_CallBack[13]();
	SET_BIT(EXTI-> PR ,13 );
	}
		//Clear the Flag
}void	EXTI14_IRQHandler(void)
{
	if(EXTI_CallBack[14]!=NULL){
	EXTI_CallBack[14]();
	SET_BIT(EXTI-> PR ,14 );
	}
		//Clear the Flag
}void	EXTI15_IRQHandler(void)
{
	if(EXTI_CallBack[15]!=NULL){
	EXTI_CallBack[15]();
	SET_BIT(EXTI-> PR ,15 );
	}
		//Clear the Flag
}void	EXTI16_IRQHandler(void)
{
	if(EXTI_CallBack[16]!=NULL){
	EXTI_CallBack[16]();
	SET_BIT(EXTI-> PR ,16 );
	}
		//Clear the Flag
}
