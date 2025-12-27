#include "stm32f10x.h"      // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"
uint8_t KeyNum;


int main(void)

{
		
		LED_Init(); 
		Key_Init();
		Buzzer_Init();
		LightSensor_Init();
    while(1)
{	                     
		if(LightSensor_Get() ==0)
{
				Buzzer_ON();
}
	
		else{Buzzer_OFF();
		}
		
}
	
	
	
}

