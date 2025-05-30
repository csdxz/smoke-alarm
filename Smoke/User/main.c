#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "Smokesensor.h"
#include "OLED.h"
#include "LED.h"

void stir(int flag,int flag2){
	if(flag !=flag2){
		if(flag){
			OLED_Clear();
			OLED_ShowString(2,6, "WARNING");
			Buzzer_on();
			gLED_off();
			rLED_on();
		}
		else{
			OLED_Clear();
			OLED_ShowString(2,2, "NOTHING HAPPEN");
			Buzzer_off();
			gLED_on();
			rLED_off();
		}
		flag2 =flag;
	}
}
	
int main(void)
{
	OLED_Init();
	Buzzer_Init();
	Smokesensor_Init();
	LED_Init();
	
	int flag=0;
	int flag2=0;
	
	OLED_Clear();
	OLED_ShowString(2,2, "NOTHING HAPPEN");
	Buzzer_off();
	gLED_on();
	rLED_off();
	
	while (1)
	{
		if(scan()==0){
			flag = 1;
			stir(flag,flag2);
			flag2 =flag;
		}
		else{
			flag = 0;
			stir(flag,flag2);
			flag2 =flag;
		}
		Delay_ms(200);
	}
}
