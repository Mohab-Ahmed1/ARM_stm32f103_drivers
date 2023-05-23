
#include "I2C_interface.h"


void I2C_voidconfigue_function(void){

if (remap_I2C1 == I2c1_enable){
#ifndef			AFIO_MAPR
	#define		AFIO_baseadress_ADD		(0x40010000)
	#define		AFIO_MAPR			*((u32 *)(AFIO_baseadress_ADD+0x04))
	#endif
SET_BIT(AFIO_MAPR,1);  // Remap (SCL/PB8, SDA/PB9)
	}

I2C_voidRest();

// Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
SET_BIT(I2C1->CR2,3);// PCLK1 FREQUENCY in MHz = 0b00001000
// Configure the clock control registers
I2C1->CCR =(40<<0); // check calculation in PDF

// Configure the rise time register
	I2C1->TRISE = 9;// check PDF

// Program the I2C_CR1 register to enable the peripheral
  // Enable I2C
SET_BIT(I2C1->CR1,0);
}

void I2C_voidRest(void){


	SET_BIT(I2C1->CR1,15);  //reset the I2c
	CLR_BIT(I2C1->CR1,15);  // Normal operation

}

void I2C_SendStartCondition(void){
	/**** STEPS FOLLOWED  ************
	1. Send the START condition
	2. Wait for the SB ( Bit 0 in SR1) to set. This indicates that the start condition is generated
	*/
		//I2C1->CR1 |= (1<<10);  // Enable the ACK
		SET_BIT(I2C1->CR1,10);
		//I2C1->CR1 |= (1<<8);  // Generate START
		SET_BIT(I2C1->CR1,8);
		while (!(I2C1->SR1 & (1<<0)));  // Wait for SB bit to set
}

void I2C_SendSlaveAddress(u8 copy_Slaveaddress){

	/**** STEPS FOLLOWED  ************
	1. Send the Slave Address to the DR Register
	2. Wait for the ADDR (bit 1 in SR1) to set. This indicates the end of address transmission
	3. clear the ADDR by reading the SR1 and SR2
	*/
		I2C1->DR = copy_Slaveaddress;  //  send the address
		while (!(I2C1->SR1 & (1<<1)));  // wait for ADDR bit to set
		u8 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit

}
void I2C_MasterWriteDataByte(u8 copy_DataByte){


	/**** STEPS FOLLOWED  ************
	1. Wait for the TXE (bit 7 in SR1) to set. This indicates that the DR is empty
	2. Send the DATA to the DR Register
	3. Wait for the BTF (bit 2 in SR1) to set. This indicates the end of LAST DATA transmission
	*/
		while (!(I2C1->SR1 & (1<<7)));  // wait for TXE bit to set
		I2C1->DR = copy_DataByte;
		while (!(I2C1->SR1 & (1<<2)));  // wait for BTF bit to set

}
void I2C_SendStopCondition(void){
	//I2C1->CR1 |= (1<<9);  // Stop I2C
		SET_BIT(I2C1->CR1,9);
		CLR_BIT(I2C1->CR1,0);  // Normal operation
			SET_BIT(I2C1->CR1,0);  //reset the I2c
}
u8 I2C_MasterReadDataByte(void){

	return I2C1 -> DR;
}

/*
void TWI_voidInitMaster(uint8 Copy_Address)
{
	




	
	
	
}

void TWI_voidInitSlave(uint8 Copy_address)
{

}


TWI_ErrStatus TWI_SendRepeatedStart()
{
	
}



TWI_ErrStatus TWI_SendSlaveAddressWithRead(uint8 copy_Slaveaddress)
{
	
}

TWI_ErrStatus TWI_MasterWriteDataByte(uint8 copy_DataByte)
{

}

TWI_ErrStatus TWI_MasterReadDataByte(uint8 *copy_DataByte)
{
	
}

void TWI_SendStopCondition(void)
{

}
*/
