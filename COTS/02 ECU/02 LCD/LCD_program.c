#include "lCD_interface.h"

void _delay_us(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
//intalize the bits
void LCD_4_bit_intalize(void){
DIO_voidSetPinDirection(Data_port, PIN12, GPIO_OUTPUT_2MHZ_PP);
DIO_voidSetPinDirection(Data_port, PIN13, GPIO_OUTPUT_2MHZ_PP);
DIO_voidSetPinDirection(Data_port, PIN14, GPIO_OUTPUT_2MHZ_PP);
DIO_voidSetPinDirection(Data_port, PIN15, GPIO_OUTPUT_2MHZ_PP);

DIO_voidSetPinDirection(control_port, RW, GPIO_OUTPUT_2MHZ_PP);
DIO_voidSetPinDirection(control_port, EN, GPIO_OUTPUT_2MHZ_PP);
DIO_voidSetPinDirection(control_port, RS, GPIO_OUTPUT_2MHZ_PP);
_delay_ms(1000);

LCD_4_bit_sendcommand(0x33); // Ensures display is in 8-bit mode
LCD_4_bit_sendcommand(0x32);  // Puts display in 4-bit mode
LCD_4_bit_sendcommand(TWOline_4bitmode);
_delay_ms(10) ;
LCD_4_bit_sendcommand(cursor_off);
_delay_ms(10) ;
LCD_4_bit_sendcommand(clear_display);
_delay_ms(10) ;
	_delay_ms(10) ;
LCD_4_bit_sendcommand(cursor_leftToright);
_delay_ms(1000) ;
}


void LCD_4_bit_sendcommand(u8 cmnd){
DIO_voidSetPinValue(control_port,RS , GPIO_LOW) ;
DIO_voidSetPinValue(control_port,RW , GPIO_LOW) ;


u16 comnd_16bit=(u16)cmnd<<8;
GPIOB_ODR=(GPIOB_ODR&0x0fff) |((comnd_16bit & 0xf000));

DIO_voidSetPinValue(control_port,EN,GPIO_HIGH);//enable  pulse =1
_delay_us(10);
DIO_voidSetPinValue(control_port,EN,GPIO_LOW); //enable pulse =0
_delay_us(10);


GPIOB_ODR=(GPIOB_ODR&0x0fff) |(comnd_16bit <<4);
DIO_voidSetPinValue(control_port,EN,GPIO_HIGH);//enable  pulse =1
_delay_us(10);
DIO_voidSetPinValue(control_port,EN,GPIO_LOW); //enable pulse =0
_delay_us(10);

}

void LCD_4_bit_sendchar(u8 cmnd){
	DIO_voidSetPinValue(control_port,RS , GPIO_HIGH) ;
	DIO_voidSetPinValue(control_port,RW , GPIO_LOW) ;

	u16 comnd_16bit=(u16)cmnd<<8;
	GPIOB_ODR=(GPIOB_ODR&0x0fff) |((comnd_16bit & 0xf000));

	DIO_voidSetPinValue(control_port,PIN2,GPIO_HIGH);//enable  pulse =1
	_delay_us(10);
	DIO_voidSetPinValue(control_port,PIN2,GPIO_LOW); //enable pulse =0
	_delay_us(10);


	GPIOB_ODR=(GPIOB_ODR&0x0fff) |(comnd_16bit <<4);
	DIO_voidSetPinValue(control_port,PIN2,GPIO_HIGH);//enable  pulse =1
	_delay_us(10);
	DIO_voidSetPinValue(control_port,PIN2,GPIO_LOW); //enable pulse =0
	_delay_us(10);

}

void Lcd_4_bit_sendstring(u8 *str){

	while(*str != '\0')
		{
		LCD_4_bit_sendchar(*str) ;
			str++ ;
		}

}

void Lcd_4_bit_courserposition(u8 Row ,u8 column ){

	if (Row<3 &&column<17)
		{
			switch(Row){
				case 1 : LCD_4_bit_sendcommand(0X80+column) ;
				break;
				case 2: LCD_4_bit_sendcommand(0XC0+column)  ;
				break;
			}
			}else {

		}
}



//fix the create custom
void Lcd_4_bit_createcustomchar(u8 *pattern ,u8 location){
	u8 i=0;
	LCD_4_bit_sendcommand(0x40 |(0<<3));  //send the address of CGram

	for(i=0;i<8 ;i++){
		LCD_4_bit_sendchar(pattern[i]); //pass the pattern to the lcd
	}

}

void Lcd_4_bit_printCustomChar(u8 location){
	LCD_4_bit_sendchar(location);
}
