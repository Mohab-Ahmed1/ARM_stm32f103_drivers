#ifndef I2C_interface_H_
#define I2C_interface_H_


#include	"Std_Types.h"
#include	"Bit_Math.h"
#include "I2C_private.h"
#include "I2C_Config.h"


/**** STEPS FOLLOWED  ************
1. Enable the I2C CLOCK and GPIO CLOCK
2. Configure the I2C PINs for ALternate Functions
	a) Select Alternate Function in MODER Register
	b) Select Open Drain Output
	c) Select High SPEED for the PINs
	e) Configure the Alternate Function in AFR Register
3. Reset the I2C
4. Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
5. Configure the clock control registers
6. Configure the rise time register
7. Program the I2C_CR1 register to enable the peripheral
*/




/*set master address to 0 if master will not be addressed*/
void I2C_voidconfigue_function(void);
void I2c_SendStartCondition(void);
void I2C_SendSlaveAddress(u8 copy_Slaveaddress);
u8 I2C_MasterReadDataByte(void);
void I2C_MasterWriteDataByte(u8 copy_DataByte);
void I2C_SendStopCondition(void);

/*
void TWI_voidInitMaster(uint8 Copy_Address);
void TWI_voidInitSlave(uint8 Copy_address);

void TWI_SendRepeatedStart();
void TWI_SendSlaveAddressWithWrite(uint8 copy_Slaveaddress);
void TWI_SendSlaveAddressWithRead(uint8 copy_Slaveaddress);
void TWI_MasterWriteDataByte(uint8 copy_DataByte);
void TWI_MasterReadDataByte(uint8 *copy_DataByte);
void TWI_SendStopCondition(void);
void TWI_SendSlaveAddressWithRead(uint8 copy_Slaveaddress);
*/

/*
typedef enum
{
	NoError,
	StartconditionERR,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddresswithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	}TWI_ErrStatus;

*/

#endif /* I2C_interface_H_ */
