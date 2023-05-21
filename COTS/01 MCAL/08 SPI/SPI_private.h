#ifndef		SPI_private_h_
#define		SPI_private_h_


typedef		struct
{	u32				CR1;
	u32				CR2;
	u32				SR;
	u32				DR;
	u32				CRCPR;
	u32				RXCRCR;
	u32				TXCRCR;
	u32				I2SCFGR;
	u32				I2SPR;
}SPI_Types;

#define		SPI		((volatile SPI_Types*)(0x40013000))


#endif
