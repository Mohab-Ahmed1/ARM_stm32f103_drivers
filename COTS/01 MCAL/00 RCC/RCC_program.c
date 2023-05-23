#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"RCC_private.h"
#include	"RCC_config.h"


void        RCC_IntalizeHSI(void){
			SET_BIT(RCC_CR,HSION); //Enable the HSI
			while(!GET_BIT(RCC_CR,HSIRDY)); //wait for the HSI flag to be ready
			SET_BIT(RCC_CR, HSIRDY); // clear the hsi ready flag
			if(PLL_clocksource== NO_PLL){
			CLR_BIT(RCC_CFGR, SW0); //choose the HSi as the system clock
			CLR_BIT(RCC_CFGR, SW1);//choose the HSi as the system clock
			while (GET_BIT(RCC_CFGR,SWS1)|| GET_BIT(RCC_CFGR,SWS0) !=0); // wait for the hsi to be choosen as the system clock
			}
	
}
void		RCC_intalizeHSE(void){
	       SET_BIT(RCC_CR,HSEON); //enable hse
			SET_BIT(RCC_CR,HSEON); //Enable the HSE
			while(!GET_BIT(RCC_CR,HSERDY)); //wait for the HSE flag to be ready
			SET_BIT(RCC_CR, HSERDY); // clear the HSE ready flag
			#if (PLL_clocksource== NO_PLL)
			SET_BIT(RCC_CFGR, SW0); //choose the HSi as the system clock
			CLR_BIT(RCC_CFGR, SW1);//choose the HSi as the system clock
			while (GET_BIT(RCC_CFGR,SWS1)!=0 && GET_BIT(RCC_CFGR,SWS0) !=1); // wait for the HSE to be choosen as the system clock
			#endif
}
void        RCC_intalizePLL(void){
	//multiplication factorfor pll 
	#if (pll_Multiplication_factor == pll_inputclockX2)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX3)
	SET_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
    #elif (pll_Multiplication_factor==pll_inputclockX4)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX5)
	SET_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX6)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
    #elif (pll_Multiplication_factor==pll_inputclockX7)
	SET_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX8)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX9)
	SET_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	CLR_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX10)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX11)
	SET_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX12)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX13)
	SET_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	CLR_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX14)
	CLR_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor==pll_inputclockX15)
	SET_BIT(RCC_CFGR,PLLMUL0);
	CLR_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#elif (pll_Multiplication_factor == pll_inputclockX16)
	SET_BIT(RCC_CFGR,PLLMUL0);
	SET_BIT(RCC_CFGR,PLLMUL1);
	SET_BIT(RCC_CFGR,PLLMUL2);
	SET_BIT(RCC_CFGR,PLLMUL3);
	#else //multiplication is not specified
	#endif
	
			SET_BIT(RCC_CR,PLLON); //Enable the PLL
			while(!GET_BIT(RCC_CR,PLLRDY)); //wait for the PLL flag to be ready
			SET_BIT(RCC_CR, PLLRDY); // clear the PLL ready flag
			CLR_BIT(RCC_CFGR, SW0); //choose the pll as the system clock
			SET_BIT(RCC_CFGR, SW1);//choose the pll as the system clock
			while (GET_BIT(RCC_CFGR,SWS1)!=1 && GET_BIT(RCC_CFGR,SWS0) !=0); // wait for the pll to be choosen as the system clock
			#if (PLL_clocksource==HALF_HSI)
					RCC_IntalizeHSI();
					CLR_BIT(RCC_CFGR, PLLSRC); //HSI oscillator clock / 2 selected as PLL input clock.
			#elif (PLL_clocksource==Full_HSE)
					RCC_intalizeHSE();
					SET_BIT(RCC_CFGR, PLLSRC); //HSE oscillator clock selected as PLL input clock.
					SET_BIT(RCC_CFGR, PLLXTPRE); //HSE clock divided by 2.
			#elif (PLL_clocksource==Half_HSE)
				   RCC_intalizeHSE();
				   SET_BIT(RCC_CFGR, PLLSRC); //HSE oscillator clock selected as PLL input clock.
				   CLR_BIT(RCC_CFGR, PLLXTPRE); //HSE clock not divided.
				
			#else
			// error the PLL_clocksource is not selected
			#endif
				
}


void		RCC_voidSysClkInt(void)
{  
	#if (RCC_SYS_CLK == Rcc_HSI)
		RCC_IntalizeHSI();
	
	#elif (RCC_SYS_CLK == Rcc_HSE){
	   RCC_intalizeHSE();
		
	#elif (RCC_SYS_CLK == Rcc_PLL){
		RCC_intalizePLL();
	#else 
		// return error RCC_Sys_clk not spacified
	#endif

RCC_voidSetAHBprescaler();
RCC_voidSetAPB1prescaler();
RCC_voidSetAPB2prescaler();
RCC_voidSetADCprescaler();

}



void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	SET_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}
	
}



void		RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	CLR_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}	
}



void 		RCC_ADC_SETprescaler(u8 prescaler){
	if (prescaler==divided2){
		CLR_BIT(RCC_CFGR,14);
		CLR_BIT(RCC_CFGR,15);
	}else if (prescaler==divided4){
		SET_BIT(RCC_CFGR,14);
		CLR_BIT(RCC_CFGR,15);
	}else if (prescaler==divided6){
		CLR_BIT(RCC_CFGR,14);
		SET_BIT(RCC_CFGR,15);
	}else if (prescaler==divided8){
		SET_BIT(RCC_CFGR,14);
		SET_BIT(RCC_CFGR,15);
	}else{
		//#error"wrong prescaler config "
	}

}
void	RCC_voidSetAHBprescaler(void){
	switch(AHB_prescaler){
	case AHB_SysNotDiv:CLR_BIT(RCC_CFGR,7);	break;
	case AHB_SysDiv2:
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv4:
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv8:
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv16:
			SET_BIT(RCC_CFGR,7);
			CLR_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv64:
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv128:
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			CLR_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv256:
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			CLR_BIT(RCC_CFGR,4);
		break;
	case AHB_SysDiv512:
			SET_BIT(RCC_CFGR,7);
			SET_BIT(RCC_CFGR,6);
			SET_BIT(RCC_CFGR,5);
			SET_BIT(RCC_CFGR,4);
		break;
	}

}
void	RCC_voidSetAPB1prescaler(void){
	switch(APB1_prescaler){
	case APB1_HCLKNotDiv: CLR_BIT(RCC_CFGR,10); break;
	case APB1_HCLKDiv2:
					SET_BIT(RCC_CFGR,10);
					CLR_BIT(RCC_CFGR,9);
					CLR_BIT(RCC_CFGR,8);
					break;
	case APB1_HCLKDiv4:
					SET_BIT(RCC_CFGR,10);
					CLR_BIT(RCC_CFGR,9);
					SET_BIT(RCC_CFGR,8);
					break;
	case APB1_HCLKDiv8:
					SET_BIT(RCC_CFGR,10);
					SET_BIT(RCC_CFGR,9);
					CLR_BIT(RCC_CFGR,8);
					break;
	case APB1_HCLKDiv16:
					SET_BIT(RCC_CFGR,10);
					SET_BIT(RCC_CFGR,9);
					SET_BIT(RCC_CFGR,8);
					break;
	}
}
void	RCC_voidSetAPB2prescaler(void){
	switch(APB2_prescaler){
		case APB1_HCLKNotDiv: CLR_BIT(RCC_CFGR,13); break;
		case APB2_HCLKDiv2:
						SET_BIT(RCC_CFGR,13);
						CLR_BIT(RCC_CFGR,12);
						CLR_BIT(RCC_CFGR,11);
						break;
		case APB2_HCLKDiv4:
						SET_BIT(RCC_CFGR,13);
						CLR_BIT(RCC_CFGR,12);
						SET_BIT(RCC_CFGR,11);
						break;
		case APB2_HCLKDiv8:
						SET_BIT(RCC_CFGR,13);
						SET_BIT(RCC_CFGR,12);
						CLR_BIT(RCC_CFGR,11);
						break;
		case APB2_HCLKDiv16:
						SET_BIT(RCC_CFGR,13);
						SET_BIT(RCC_CFGR,12);
						SET_BIT(RCC_CFGR,11);
						break;
		}
}
void	RCC_voidSetADCprescaler(void){
	switch(ADC_prescaler){

			case ADC_APB2clkdiv2:
							CLR_BIT(RCC_CFGR,15);
							CLR_BIT(RCC_CFGR,14);
							break;
			case ADC_APB2clkdiv4:
							CLR_BIT(RCC_CFGR,15);
							SET_BIT(RCC_CFGR,14);
							break;
			case ADC_APB2clkdiv6:
							SET_BIT(RCC_CFGR,15);
							CLR_BIT(RCC_CFGR,14);
							break;
			case ADC_APB2clkdiv8:
							SET_BIT(RCC_CFGR,15);
							SET_BIT(RCC_CFGR,14);
							break;
			}
}
