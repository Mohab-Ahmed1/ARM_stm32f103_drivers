

//include part 
#include "KEYPAD_interface.h"

//initialize function
void KEYPAD_Voidinit(void){
	//rows
	DIO_voidSetPinDirection(KEY_PORT, PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(KEY_PORT, PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(KEY_PORT, PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(KEY_PORT, PIN3, GPIO_OUTPUT_2MHZ_PP);
	//columes
	DIO_voidSetPinDirection(KEY_PORT, PIN4,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(KEY_PORT, PIN5, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(KEY_PORT, PIN6, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(KEY_PORT, PIN7, GPIO_INPUT_PULL_UP_DOWN);

	//TURN PULL UP RESISTANCE
	DIO_voidSetPinValue(KEY_PORT, PIN4, GPIO_HIGH);
	DIO_voidSetPinValue(KEY_PORT, PIN5, GPIO_HIGH);
	DIO_voidSetPinValue(KEY_PORT, PIN6, GPIO_HIGH);
	DIO_voidSetPinValue(KEY_PORT, PIN7, GPIO_HIGH);

}

const u8 keypad[4][4] ={
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'!','0','=','+'},
	};
//read function
void KEYPAD_Getpressedkey(u8 *ptr){
	volatile u8 row = 4 ;
  volatile	 u8 colm=0  ;
   u8 x  = 1     ;
   *ptr =0xff ;
	for (colm=0 ;colm<4 ; colm++)
	{
		DIO_voidSetPinValue(KEY_PORT, colm , GPIO_LOW) ;
		for (row=4;row<8;row++)
		{
		x=DIO_u8GetPinValue(KEY_PORT, row);
		 if (x==0)
		 {
			 *ptr = keypad[row-4][colm] ;
			 x=1 ;
		 }
		}
		DIO_voidSetPinValue(KEY_PORT, colm , GPIO_HIGH) ;
		
	}
}
