#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
#include "IC.h"

uint16_t Num =0;

int main(void)
{
    OLED_Init();
    PWM_Init();
    IC_Init();
	 PWM_SetPrescaler(720-1);
    PWM_Setcompare1(50);

    OLED_ShowString(1,1,"Freq:00000Hz");
   
    while (1)
    {
        OLED_ShowNum(1,6,IC_GetFreq(),5);
		OLED_ShowNum(2,6,IC_GetDuty(),5);
    }
}



