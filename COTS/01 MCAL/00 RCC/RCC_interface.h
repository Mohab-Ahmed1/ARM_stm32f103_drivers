#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H


// RCC_cr bits
typedef  enum{
	HSION,
	HSIRDY,
	HSITRIM0 = 3,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL6,
	HSICAL7,
	HSEON,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON = 24,
	PLLRDY
}RCC_cr;


//RCC_cfgr bits
typedef enum{
	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE10,
	PPRE11,
	PPRE12,
	PPRE20,
	PPRE21,
	PPRE22,
	ADCPRE0,
	ADCPRE1,
	PLLSRC,
	PLLXTPRE,
	PLLMUL0,
	PLLMUL1,
	PLLMUL2,
	PLLMUL3,
	USBPRE,
	MCO0 = 24,
	MCO1,
	MCO2
}RCC_cfgr;


#define		RCC_AHB				0
#define		RCC_APB1			1
#define		RCC_APB2			2


void        RCC_IntalizeHSI(void);
void		RCC_intalizeHSE(void);
void        RCC_intalizePLL(void);
void		RCC_voidSysClkInt(void);
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId);

typedef enum{
	divided2,
	divided4,
	divided6,
	divided8
}prescalers;
void 		RCC_ADC_SETprescaler(u8 prescaler);
#endif
