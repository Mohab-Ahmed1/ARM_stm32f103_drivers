#ifndef		ADC_private
#define		ADC_private


typedef		struct
{	u32				SR;
	u32				CR1;
	u32				CR2;
	u32				SMPR1;
	u32				SMPR2;
	u32				JOFR1;
	u32				JOFR2;
	u32				JOFR3;
	u32				JOFR4;
	u32				HTR;
	u32				LTR;
	u32				SQR1;
	u32				SQR2;
	u32				SQR3;
	u32				JSQR;
	u32				JDR1;
	u32				JDR2;
	u32				JDR3;
	u32				JDR4;
	u32				DR;
}ADC1_Types;

#define		ADC1		((volatile ADC1_Types*)(0x40012400))


#endif
