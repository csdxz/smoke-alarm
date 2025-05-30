#include "stm32f10x.h"                 
void Buzzer_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
														
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;					//����ṹ�����
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIOģʽ����ֵΪ�������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO�ٶȣ���ֵΪ50MHz
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Buzzer_on(){
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
}
void Buzzer_off(){
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
}
