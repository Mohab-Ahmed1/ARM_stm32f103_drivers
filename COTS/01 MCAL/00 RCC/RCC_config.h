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
#define		RCC_SYS_CLK						Rcc_HSI
#define     PLL_clocksource					NO_PLL
#define     pll_Multiplication_factor      pll_inputclockX2

#endif
