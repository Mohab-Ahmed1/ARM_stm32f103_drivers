/*
 * LED_interfce.h
 *
 * Created: 5/4/2023 
 *  Author: mehob
 */ 


#ifndef LED_interfce_H_
#define LED_interfce_H_
//include drivers
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include "DIO_interface.h"
#include "RCC_interface.h"


//led intialize
//input:led port and led pins
//output: void
//function:this function intalize the pin to be output 
void LED_int (u8 ledport ,u8 ledpin);
//led on
//input led port and led pin 
//output:void
//function :this function writes high on that pin
void LED_on (u8 ledport ,u8 ledpin);
//led off 
//input:led port and led pins
//output: void
//function :this function writes low on that pin
void LED_off (u8 ledport ,u8 ledpin);
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void LED_toogle (u8 ledport ,u8 ledpin);



#endif /* LED_interfce_H_ */
