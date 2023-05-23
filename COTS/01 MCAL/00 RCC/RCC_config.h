#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

typedef enum{   Rcc_HSI,
                Rcc_HSE,
                Rcc_PLL
		       
}SYS_CLK	;
typedef enum{
        HALF_HSI,
        Full_HSE,
        Half_HSE,
        NO_PLL
}clocksource;

typedef enum {
	pll_inputclockX2,
	pll_inputclockX3,
	pll_inputclockX4,
	pll_inputclockX5,
	pll_inputclockX6,
	pll_inputclockX7,
	pll_inputclockX8,
	pll_inputclockX9,
	pll_inputclockX10,
	pll_inputclockX11,
	pll_inputclockX12,
	pll_inputclockX13,
	pll_inputclockX14,
	pll_inputclockX15,
	pll_inputclockX16
	
	} pll_multiplication;


//AHB PRESCALERS
enum{
	AHB_SysNotDiv,
	AHB_SysDiv2,
	AHB_SysDiv4,
	AHB_SysDiv8,
	AHB_SysDiv16,
	AHB_SysDiv64,
	AHB_SysDiv128,
	AHB_SysDiv256,
	AHB_SysDiv512,

};
//APB1 PRESCALERS
enum{
	APB1_HCLKNotDiv,
	APB1_HCLKDiv2,
	APB1_HCLKDiv4,
	APB1_HCLKDiv8,
	APB1_HCLKDiv16,
};
//APB2 PRESCALERS
enum{
	APB2_HCLKNotDiv,
	APB2_HCLKDiv2,
	APB2_HCLKDiv4,
	APB2_HCLKDiv8,
	APB2_HCLKDiv16,
};
//ADC PRESCALER
enum {
	ADC_APB2clkdiv2,
	ADC_APB2clkdiv4,
	ADC_APB2clkdiv6,
	ADC_APB2clkdiv8

};

//CHOOSE FROM
//1- Rcc_HSI,
//2- Rcc_HSE,
//3- Rcc_PLL
#define		RCC_SYS_CLK						Rcc_HSI
//CHOOSE FROM
//1-HALF_HSI
//2-Full_HSE
//3-Half_HSE
//4-NO_PLL
#define     PLL_clocksource					NO_PLL
//CHOOSE FROM
//pll_inputclockX2,
//pll_inputclockX3,
//pll_inputclockX4,
//pll_inputclockX5,
//pll_inputclockX6,
//pll_inputclockX7,
//pll_inputclockX8,
//pll_inputclockX9,
//pll_inputclockX10,
//pll_inputclockX11,
//pll_inputclockX12,
//pll_inputclockX13,
//pll_inputclockX14,
//pll_inputclockX15,
//pll_inputclockX16
#define     pll_Multiplication_factor      pll_inputclockX2
//CHOOSE FROM
//AHB_SysNotDiv,
//AHB_SysDiv2,
//AHB_SysDiv4,
//AHB_SysDiv8,
//AHB_SysDiv16,
//AHB_SysDiv64,
//AHB_SysDiv128,
//AHB_SysDiv256,
//AHB_SysDiv512,
#define		AHB_prescaler		AHB_SysNotDiv
//CHOOSE FROM
//APB1_HCLKNotDiv,
//APB1_HCLKDiv2,
//APB1_HCLKDiv4,
//APB1_HCLKDiv8,
//APB1_HCLKDiv16,
#define		APB1_prescaler 		APB1_HCLKNotDiv
//CHOOSE FROM
//APB2_HCLKNotDiv,
//APB2_HCLKDiv2,
//APB2_HCLKDiv4,
//APB2_HCLKDiv8,
//APB2_HCLKDiv16,
#define		APB2_prescaler		APB2_HCLKNotDiv
//CHOOSE FROM
//ADC_APB2clkdiv2,
//ADC_APB2clkdiv4,
//ADC_APB2clkdiv6,
//ADC_APB2clkdiv8
#define		ADC_prescaler		ADC_APB2clkdiv2
#endif
