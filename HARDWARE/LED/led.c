
#include "led.h"  

#include "bee.h"  



void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	RCC_AHB1PeriphClockCmd ( LED1_CLK, ENABLE); 	//初始化GPIOG时钟	
	RCC_AHB1PeriphClockCmd ( LED2_3_CLK, ENABLE); 	//初始化GPIOG时钟	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   //输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //推挽输出
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;	//上拉
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz; //速度选�
	//初始化 LED1 引脚
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	 
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   //输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //推挽输出
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;	//上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //速度选?
	GPIO_InitStructure.GPIO_Pin = LED2_PIN|LED3_PIN;	 
	GPIO_Init(LED2_3_PORT, &GPIO_InitStructure);	
  LED1_OFF;
	LED2_OFF;
	LED3_OFF;
}

void led_red_turn(void){
     if(GPIO_ReadOutputDataBit(GPIOD,GPIO_Pin_14)==0){GPIO_SetBits(GPIOD, GPIO_Pin_14);}
		 else{GPIO_ResetBits(GPIOD, GPIO_Pin_14);}
}