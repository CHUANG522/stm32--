#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
uint16_t Num =0;
//uint16_t i=100;
int main(void)
{
    OLED_Init();
    PWM_Init();

    OLED_ShowString(1,1,"Num:");

    while (1)
    {
        for (Num=0; Num<=1000; Num++)
        {
            PWM_Setcompare1(Num);
          Delay_ms(10);

        }

        for (Num =1000; Num>0; Num--)
        {
            PWM_Setcompare1(Num);
           Delay_ms(10);

        }
    }

}

