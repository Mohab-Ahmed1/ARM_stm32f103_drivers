#include "7segment_interface.h"

u8  segpins[8];
void seg_Setconnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD,u8 PE,u8 PF,u8 PG)
{
	LED_int(segmport,PA);
	LED_int(segmport,PB);
	LED_int(segmport,PC);
	LED_int(segmport,PD);
	LED_int(segmport,PE);
	LED_int(segmport,PF);
	LED_int(segmport,PG);
	segpins[0]=PA;
	segpins[1]=PB;
	segpins[2]=PC;
	segpins[3]=PD;
	segpins[4]=PE;
	segpins[5]=PF;
	segpins[6]=PG;
	segpins[7]=segmport;

}

void seg_printNum(u8 Num){
if (Num == 1){
	LED_on(segpins[7],segpins[0]);	//PA
	LED_on(segpins[7],segpins[1]); 	//PB
	LED_on(segpins[7],segpins[2]);	//PC
	LED_on(segpins[7],segpins[3]);	//PD
	LED_off(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_on(segpins[7],segpins[6]);	//PG

}else if(Num ==2 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_on(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_off(segpins[7],segpins[4]);	//PE
	LED_on(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==3 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); //PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_on(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==4 ){
	LED_on(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_on(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==5 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_on(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==6 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_on(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_off(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==7 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_on(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_on(segpins[7],segpins[5]);	//pF
	LED_on(segpins[7],segpins[6]);	//PG
}else if(Num ==8 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_off(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==9 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_off(segpins[7],segpins[6]);	//PG
}else if(Num ==0 ){
	LED_off(segpins[7],segpins[0]);	//PA
	LED_off(segpins[7],segpins[1]); 	//PB
	LED_off(segpins[7],segpins[2]);	//PC
	LED_off(segpins[7],segpins[3]);	//PD
	LED_off(segpins[7],segpins[4]);	//PE
	LED_off(segpins[7],segpins[5]);	//pF
	LED_on(segpins[7],segpins[6]);	//PG
}else{
	LED_on(segpins[7],segpins[0]);	//PA
	LED_on(segpins[7],segpins[1]); 	//PB
	LED_on(segpins[7],segpins[2]);	//PC
	LED_on(segpins[7],segpins[3]);	//PD
	LED_on(segpins[7],segpins[4]);	//PE
	LED_on(segpins[7],segpins[5]);	//pF
	LED_on(segpins[7],segpins[6]);	//PG
}
}
