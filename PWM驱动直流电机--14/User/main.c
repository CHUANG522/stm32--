#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Motor.h"
uint16_t Num =0;
//uint16_t i=100;
int main(void)
{
    OLED_Init();
  Motor_Init();
	Motor_SetSpeed(0);

    OLED_ShowString(1,1,"Num:");

    while (1)
    {

	}

}

