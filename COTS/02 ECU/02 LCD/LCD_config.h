#ifndef		LCD_config_H
#define		LCD_config_H

//connection mode
enum{
	four_bitmode,
	Eight_bitmode
	};
	
#define control_port	PORTA
#define Data_port		PORTB

#define  RW		PIN0
#define  EN		PIN2
#define  RS		PIN1






#define connection_mode  four_bitmode
#endif
