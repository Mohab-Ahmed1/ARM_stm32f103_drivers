/*
 * LED_interfce.h
 *
 * Created: 5/4/2023 
 *  Author: mehob
 */ 


#ifndef Buzzer_interfce_H_
#define Buzzer_interfce_H_
//include drivers
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "Buzzer_Config.h"

//led intialize
//input:Buzzer port and Buzzer pins
//output: void
//function:this function intalize the pin to be output 
void Buzzer_int (u8 ledport ,u8 ledpin);
//led on
//input Buzzer port and Buzzer pin
//output:void
//function :this function writes high on that pin
void Buzzer_on (u8 ledport ,u8 ledpin);
//led off 
//input:led port and led pins
//output: void
//function :this function writes low on that pin
void Buzzer_off (u8 ledport ,u8 ledpin);
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void Buzzer_toogle (u8 ledport ,u8 ledpin);



#endif /* Buzzer_interfce_H_ */
