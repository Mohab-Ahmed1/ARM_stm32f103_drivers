/*
 * LED.c
 *
 * Created: 1/4/2023 10:04:29 AM
 *  Author: mehob
 */ 
#include "LED_interfce.h"

//led intialize
//input:led port and led pins
//output: void
//function:this function intalize the pin to be output
void LED_int (u8 ledport ,u8 ledpin){
	DIO_voidSetPinDirection(ledport,ledpin,GPIO_OUTPUT_2MHZ_PP);
	LED_off ( ledport , ledpin);
}
//led on
//input led port and led pin
//output:void
//function :this function writes high on that pin
void LED_on (u8 ledport ,u8 ledpin){
	DIO_voidSetPinValue(ledport,ledpin,GPIO_HIGH);
}
//led off
//input:led port and led pins
//output: void
//function :this function writes low on that pin
void LED_off (u8 ledport ,u8 ledpin){
	DIO_voidSetPinValue(ledport,ledpin,GPIO_LOW);
}
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void LED_toogle (u8 ledport ,u8 ledpin){
	DIO_voidtogglepin(ledport,ledpin);
}
