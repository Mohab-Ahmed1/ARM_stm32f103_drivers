#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

// remap from (SCL/PB6, SDA/PB7)to (SCL/PB8, SDA/PB9)
enum {
	I2c1_enable,
	I2c1_disable
};

#define remap_I2C1 I2c1_disable
/*

#define START_ACK				0x08 // start has been sent
#define REP_START_ACK			0x10 // repeated start
#define Slave_ADD_AND_WR_ACK	0x18 // master transmit ( slave address + Write request ) Ack
#define Slave_ADD_AND_RD_ACK	0x40 // master transmit ( slave address + read request ) Ack
#define MSTR_WR_BYTE_ACK		0x28 // master transmit data ACK
#define MSTR_RRD_BYTE_WITH_ACK	0x50 // master receive data with ACK
#define MSTR_RRD_BYTE_WITH_NACK	0x58 // master receive data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ	0xA8 // means that slave address is received with read request
#define SLAVE_ADD_RCVE_RW_REQ	0x60 // means that slave address is received with write request
#define SLAVE_DATA_RECEIVED		0x80 // means that a byte is received
#define SLAVE_BYTE_TRANSIMITTED	0xB8 // ,eans that the written byte is transmitted

*/
#endif /* I2C_CONFIG_H_ */
