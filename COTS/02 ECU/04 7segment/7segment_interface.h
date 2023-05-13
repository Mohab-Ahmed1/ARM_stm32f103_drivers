#ifndef		segment_interface_H
#define		segment_interface_H

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include "LED_interfce.h"
#include "DIO_interface.h"
#include "RCC_interface.h"

void seg_Setconnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD,u8 PE,u8 PF,u8 PG);

void seg_printNum(u8 Num);

#endif
