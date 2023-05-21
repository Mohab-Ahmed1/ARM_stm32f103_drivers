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

	RCC_voidSysClkInt();  //clock intalize
	RCC_voidEnablePerClk(RCC_APB1, 21);  //clock enable for i2c1
	RCC_voidEnablePerClk(RCC_APB2, 3);		//clock enable for gpio b

	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_50MHZ_AFOD);  //set the SCL
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_50MHZ_AFOD);		//set the SDA
	I2C_voidconfigue_function();

	while(1){

		I2C_SendStartCondition();
		I2C_SendSlaveAddress(0b10000000);
		_delay_ms(1);
		I2C_MasterWriteDataByte(0x55);
		_delay_ms(1);
		I2C_SendStopCondition();
		_delay_ms(1000);

	}
	return 0;

}