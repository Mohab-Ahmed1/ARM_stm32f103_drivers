#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include 	"EXTI_interface.h"
#include	"NVIC_interface.h"
#include	"STK_interface.h"
#include 	"DMA_interface.h"
#include   "Dio_interface.h"
#include  "LED_interfce.h"
#include "Buzzer_interfce.h"
#include "lCD_interface.h"
#include "ADC_interface.h"
#include "7segment_interface.h"
#include "UART1_interface.h"
#include "SPI_interface.h"
#include "I2C_interface.h"

//i2c main.c

void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}

int main (){

	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 0);
	RCC_voidEnablePerClk(RCC_APB1, 21);
	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_HIGH);

	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);


	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_LOW);

	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_HIGH);

	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_HIGH);

	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_LOW);

	I2C_voidconfigue_function();
	// write A to eeprom
	I2C_SendStartCondition();
	I2C_SendSlaveAddress(0b10100100);
	I2C_MasterWriteDataByte(0b1);
	I2C_MasterWriteDataByte('A');
	I2C_SendStopCondition();
	u8 readI2C = '\0';
	while (1)
	{
		//read from eeprom
		I2C_SendStartCondition();
		I2C_SendSlaveAddress(0b10100100);
		I2C_MasterWriteDataByte(0b1);
		I2C_SendStartCondition();
		I2C_SendSlaveAddress(0b10100100+1);
		readI2C = I2C_MasterReadDataByte();
		I2C_SendStopCondition();
	}
	return 1;
}


