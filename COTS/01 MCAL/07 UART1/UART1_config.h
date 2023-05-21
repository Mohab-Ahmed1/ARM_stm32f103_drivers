#ifndef UART1_config_h_
#define UART1_config_h_

//uart clock
enum{
UART1_8MHZ,
UART1_72MZ
};

//uart baudrate
enum{
UART1_9600,
UART1_115200
};

#define  UART1_clock		UART1_8MHZ
#define  UART1_baudrate		UART1_9600

#endif
