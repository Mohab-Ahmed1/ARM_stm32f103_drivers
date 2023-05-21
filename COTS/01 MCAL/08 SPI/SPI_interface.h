#ifndef SPI_interface_h_
#define SPI_interface_h_
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"SPI_private.h"
#include  "SPI_config.h"
/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/

void SPI_VoidInit(void);
void SPI_SETCPOL_CPHA(void);
void SPI_VoidFrameformate(void);
void SPI_VoidSlaveMangment (void);
void SPI_VoidsetBaudRate(void);
void SPI_VoidSetdirection(void);
void SPI_voidSetReceiveDir(void);
void SPI_VoidSetFrameformate(void);
void SPI_Void_MASTERSelect(void);
//transmit data
void SPI_VoidSenddata(u8 data);
//receive data
void SPI_voidRseivedata (u8 *data );
/*
//enable transmitter
void SPI_voidenableTX(void);
//enable receiver
void SPI_VoidenableRX(void);
*/

/*
void SPI_voidSendString(u8 *str);
void SPI_StrReceiveString(u8 *str);

*/

#endif
