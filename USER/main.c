#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "sys.h"
#include "tim.h"
#include "bee.h"
	
int main(void)
{
	delay_init(168);
  LED_Init();
	Bee_Init();
	int stage[48]={1,1,5,5,6,6,5,5,4,4,3,3,2,2,1,1,5,5,4,4,3,3,2,2,5,5,4,4,3,3,2,2,1,1,5,5,6,6,5,5,4,4,3,3,2,2,1,1};
	u16 fre[7]={0,38,34,30,26,22,18};
	int beat[7]={0,196,220,247,262,294,330};
	int flag =0;
  extern int i;
	TIM3_Init(8400,fre[stage[flag]]);
	
	while(1)
	{
			
		if(i==beat[stage[flag]]){
			i=0;
			flag++;
			TIM3_Init(8400,fre[stage[flag]]);
			led_red_turn();
		}
		
	}
}


