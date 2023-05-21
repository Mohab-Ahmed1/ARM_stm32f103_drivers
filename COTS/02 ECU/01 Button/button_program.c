/*
 * button.c
 *
 * Created: 1/4/2023 10:29:04 AM
 *  Author: mehob
 */ 
//button intalize

#include "button_Interface.h"
//button intalize
//input:buttonport and button pin
//output:void
//function: this will make the button port to an input
void BUTTON_init(uint8_t buttonport ,uint8_t buttonpin){
	DIO_init(buttonport,buttonpin,IN);
}
//button read
//input:buttonport and button pin
//output:void
//function:this will read the current reading of the required port and pin
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin ,uint8_t *value){
	DIO_read(buttonport,buttonpin,value);
}