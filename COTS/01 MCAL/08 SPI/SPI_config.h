#ifndef SPI_config_h_
#define SPI_config_h_
//clock polarity
enum{
	SPI_fallingedge,
	SPI_Risingedge
};

//clock phase
enum{
	SPI_FirstDataCapture,
	SPI_SecandDataCapture
};

//data frame  formate
enum{
	SPI_data_8bit,
	SPI_data_16bit
};
//SPI Enable & Disable

enum{
	SPI_DISABLE,
	SPI_ENABLE
};
//baudrate devision
enum{
	FPclk_2,
	FPclk_4,
	FPclk_8,
	FPclk_16,
	FPclk_32,
	FPclk_64,
	FPclk_128,
	FPclk_256,
};

//BIdirection data mode BIDIMODE
enum{
unidirec_2line,
bidirection_1line
};

//Rececive only direction
enum{
	SPI_FullDuplex,
	SPI_OutDisable
};
//frame formate sed data first
enum{
	MSB,
	LSB
};
//master select
enum{
	Slave,
	Master
};
//choose from
//	1-SPI_fallingedge,
//	2-SPI_Risingedge
#define SPI_CPOL  		 SPI_Risingedge
//choose from
//	1-SPI_FirstDataCapture,
//	2-SPI_SecandDataCapture
#define SPI_CPHA  		 SPI_SecandDataCapture
//choose from
//	1-SPI_data_8bit,
//	2-SPI_data_16bit
#define SPI_DataFormate	 SPI_data_8bit
//choose from SSM
//	1-SPI_data_8bit,
//	2-SPI_data_16bit
#define SPI_SlaveMangment  SPI_ENABLE
//choose from
//	1-FPclk_2,
//	2-FPclk_4,
//	3-FPclk_8,
//	4-FPclk_16,
//	5-FPclk_32,
//	6-FPclk_64,
//	7-FPclk_128,
//	8-FPclk_256,
#define SPI_BaudRate  FPclk_16
//choose from
//	1-unidirec_2line,
//	2-bidirection_1line
#define SPI_BIdirectionData		unidirec_2line
//choose from
//	1-SPI_DISABLE
//	2-SPI_ENABLE
#define  SPI_outputenable		SPI_DISABLE
//choose from
//	1-SPI_FullDuplex,
//	2-SPI_OutDisable
#define  SPI_ReceveOnlyDir		SPI_FullDuplex
//choose from
//	1-MSB
//	2-LSB
#define  SPI_frameFormate		MSB
//choose master select
//1-Slave
//2-Master
#define  SPI_MasterSelect		Master

#endif
