#include "stm32f10x.h"               

void LED_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
															
	
	
	GPIO_InitTypeDef GPIO_InitStructure;					//定义结构体变量
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIO模式，赋值为推挽输出模式
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_3 | GPIO_Pin_4;		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO速度，赋值为50MHz
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void rLED_on(){
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}
void gLED_on(){
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}
void gLED_off(){
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}
void rLED_off(){
	GPIO_SetBits(GPIOA,GPIO_Pin_3);
}
