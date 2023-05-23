/*
 * LED.c
 *
 * Created: 1/4/2023 10:04:29 AM
 *  Author: mehob
 */ 
#include "Buzzer_interfce.h"

//Buzzer intialize
//input:Buzzer port and Buzzer pins
//output: void
//function:this function intalize the pin to be output
void Buzzer_int (u8 Buzzerport ,u8 Buzzerpin){
	
	DIO_voidSetPinDirection(Buzzerport,Buzzerpin,GPIO_OUTPUT_2MHZ_PP);
	Buzzer_off(Buzzerport,Buzzerpin);
}
//Buzzer on
//input led port and Buzzer pin
//output:void
//function :this function writes high on that pin
void Buzzer_on (u8 Buzzerport ,u8 Buzzerpin){
	DIO_voidSetPinValue(Buzzerport,Buzzerpin,GPIO_HIGH);
}
//Buzzer off
//input:Buzzer port and Buzzer pins
//output: void
//function :this function writes low on that pin
void Buzzer_off (u8 Buzzerport ,u8 Buzzerpin){
	DIO_voidSetPinValue(Buzzerport,Buzzerpin,GPIO_LOW);
}
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void Buzzer_toogle (u8 Buzzerport ,u8 Buzzerpin){
	DIO_voidtogglepin(Buzzerport,Buzzerpin);
}
