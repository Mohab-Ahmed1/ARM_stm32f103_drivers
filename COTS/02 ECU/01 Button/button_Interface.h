/*
 * button.h
 *
 * Created: 1/4/2023 10:28:48 AM
 *  Author: mehob
 */ 


#ifndef BUTTON_Interface_H_
#define BUTTON_Interface_H_
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include "DIO_interface.h"
#include "RCC_interface.h"

//button intalize
//input:buttonport and button pin
//output:void
//function: this will make the button port to an input
void BUTTON_init(uint8_t buttonport ,uint8_t buttonpin);
//button read
//input:buttonport and button pin
//output:void
//function:this will read the current reading of the required port and pin
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin ,uint8_t *value);//button read



#endif /* BUTTON_Interface_H_ */