
//button intalize

#include "button_Interface.h"


//button intalize
//input:buttonport and button pin
//output:void
//function: this will make the button port to an input
void BUTTON_init(u8 buttonport ,u8 buttonpin,button_state state){
	DIO_voidSetPinDirection(buttonport,buttonpin,GPIO_INPUT_PULL_UP_DOWN);

	switch (state){
	case Button_pullup :  DIO_voidSetPinValue(buttonport, buttonpin, GPIO_HIGH);  break;
	case Button_Pulldown:   DIO_voidSetPinValue(buttonport, buttonpin, GPIO_LOW);  break;
	}
}
//button read
//input:buttonport and button pin
//output:void
//function:this will read the current reading of the required port and pin
void BUTTON_read(u8 buttonport,u8 buttonpin ,u8 *value){
	*value = DIO_u8GetPinValue(buttonport,buttonpin);
}
