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


//Rcc_AHBENR register
enum{
	RCC_AHB_DMA1,
	RCC_AHB_DMA2,
	RCC_AHB_SRAM,
	RCC_AHB_FLITF=4,
	RCC_AHB_CRC=6,
	RCC_AHB_FSMC=8,
	RCC_AHB_SDIO=10,
};
//Rcc_APB1ENR register
enum{
	RCC_APB1_TIM2,
	RCC_APB1_TIM3,
	RCC_APB1_TIM4,
	RCC_APB1_TIM5,
	RCC_APB1_TIM6,
	RCC_APB1_TIM7,
	RCC_APB1_TIM12,
	RCC_APB1_TIM13,
	RCC_APB1_TIM14,
	RCC_APB1_WWWG=11,
	RCC_APB1_SPI2=14,
	RCC_APB1_SPI3,
	RCC_APB1_USART2=17,
	RCC_APB1_USART3,
	RCC_APB1_USART4,
	RCC_APB1_USART5,
	RCC_APB1_I2C1,
	RCC_APB1_I2C2,
	RCC_APB1_USB,
	RCC_APB1_CAN=25,
	RCC_APB1_BKP=27,
	RCC_APB1_PWR,
	RCC_APB1_DAC,
};

//Rcc_APB2ENR register
enum{
	RCC_APB2_AFIO,
	RCC_APB2_DIOA=2,
	RCC_APB2_DIOB,
	RCC_APB2_DIOC,
	RCC_APB2_DIOD,
	RCC_APB2_DIOE,
	RCC_APB2_DIOF,
	RCC_APB2_DIOG,
	RCC_APB2_ADC1,
	RCC_APB2_ADC2,
	RCC_APB2_TIM1,
	RCC_APB2_SPI1,
	RCC_APB2_TIM8,
	RCC_APB2_USART1,
	RCC_APB2_ADC3,
	RCC_APB2_TIM9=19,
	RCC_APB2_TIM10,
	RCC_APB2_TIM11,
};


#define	RCC_AHB				0
#define	RCC_APB1			1
#define	RCC_APB2			2


void    RCC_IntalizeHSI(void);
void	RCC_intalizeHSE(void);
void    RCC_intalizePLL(void);
void	RCC_voidSysClkInt(void);
void	RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void	RCC_voidDisablePerClk(u8 BusId , u8 PerId);

void	RCC_voidSetAHBprescaler(void);
void	RCC_voidSetAPB1prescaler(void);
void	RCC_voidSetAPB2prescaler(void);
void	RCC_voidSetADCprescaler(void);
typedef enum{
	divided2,
	divided4,
	divided6,
	divided8
}prescalers;
void 		RCC_ADC_SETprescaler(u8 prescaler);
#endif
