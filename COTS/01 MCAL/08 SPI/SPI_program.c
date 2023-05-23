
#include "SPI_interface.h"


void SPI_VoidInit(void){
	CLR_BIT( SPI->CR1,6);  //disable the spi
	SPI_SETCPOL_CPHA();
	SPI_VoidFrameformate();
	SPI_voidSetReceiveDir();
	SPI_VoidSlaveMangment();
	SET_BIT(SPI->CR1,8)	; //value of this bit forced on the NSS pin
	SPI_VoidsetBaudRate();
	SPI_VoidSetdirection();
	SPI_VoidSetFrameformate();
	SPI_Void_MASTERSelect();
	SET_BIT( SPI->CR1,6); //enable the spi
}

void SPI_SETCPOL_CPHA(void){
	switch(SPI_CPOL){
		case SPI_fallingedge:   CLR_BIT(SPI->CR1,1);  break;
		case SPI_Risingedge:   SET_BIT(SPI->CR1,1);  break;
		}
		switch(SPI_CPHA){
		case SPI_FirstDataCapture:  CLR_BIT(SPI->CR1,0);    break;
		case SPI_SecandDataCapture:   SET_BIT(SPI->CR1,0);  break;
		}
}
void SPI_VoidFrameformate(void){

switch(SPI_DataFormate){

case SPI_data_8bit : CLR_BIT(SPI->CR1,11);		break;
case SPI_data_16bit: SET_BIT(SPI->CR1,11); 		break;
}
}

void SPI_VoidSlaveMangment (void){

	switch (SPI_SlaveMangment){
	case SPI_DISABLE :	CLR_BIT(SPI->CR1,9)	;		break;
	case SPI_ENABLE :	SET_BIT(SPI->CR1,9)	;		break;
	}

}

void SPI_VoidsetBaudRate(void){
	switch (SPI_BaudRate){
	case FPclk_2:   CLR_BIT(SPI->CR1,3);
					CLR_BIT(SPI->CR1,4);
					CLR_BIT(SPI->CR1,5);	break;

	case FPclk_4:   SET_BIT(SPI->CR1,3);
					CLR_BIT(SPI->CR1,4);
					CLR_BIT(SPI->CR1,5);	break;

	case FPclk_8:   CLR_BIT(SPI->CR1,3);
					SET_BIT(SPI->CR1,4);
					CLR_BIT(SPI->CR1,5);	break;

	case FPclk_16:  SET_BIT(SPI->CR1,3);
					SET_BIT(SPI->CR1,4);
					CLR_BIT(SPI->CR1,5);	break;

	case FPclk_32:  CLR_BIT(SPI->CR1,3);
					CLR_BIT(SPI->CR1,4);
					SET_BIT(SPI->CR1,5);	break;

	case FPclk_64:  SET_BIT(SPI->CR1,3);
					CLR_BIT(SPI->CR1,4);
					SET_BIT(SPI->CR1,5);	break;

	case FPclk_128: CLR_BIT(SPI->CR1,3);
					SET_BIT(SPI->CR1,4);
					SET_BIT(SPI->CR1,5);	break;

	case FPclk_256: SET_BIT(SPI->CR1,3);
					SET_BIT(SPI->CR1,4);
					SET_BIT(SPI->CR1,5);	break;
	}

}
void SPI_VoidSetdirection(void){

	switch(SPI_BIdirectionData){
	case unidirec_2line : 		CLR_BIT(SPI->CR1,15);		 break;
	case bidirection_1line :	SET_BIT(SPI->CR1,15);		 break;
	}

	switch(SPI_outputenable){
		case SPI_DISABLE : 		CLR_BIT(SPI->CR1,14);	 break;
		case SPI_ENABLE :		SET_BIT(SPI->CR1,14);	 break;
		}
}
void SPI_voidSetReceiveDir(void){
	switch(SPI_ReceveOnlyDir){
	case SPI_FullDuplex:	CLR_BIT(SPI->CR1,10);	 break;
	case SPI_OutDisable:	SET_BIT(SPI->CR1,10);	 break;
	}

}

void SPI_VoidSetFrameformate(void){
	switch(SPI_frameFormate){
	case MSB:	CLR_BIT(SPI->CR1,7);		break;
	case LSB:	SET_BIT(SPI->CR1,7);		break;
	}

}

void SPI_Void_MASTERSelect(void){

	switch(SPI_MasterSelect){
	case Slave : CLR_BIT(SPI->CR1,2);	break;
	case Master : SET_BIT(SPI->CR1,2);	break;
	}
}
void SPI_VoidSenddata(u8 data){

	SPI->DR = data;
}

void SPI_voidRseivedata (u8 *data ){
	while(GET_BIT(SPI->SR,7));
	*data  = SPI->DR;

}

