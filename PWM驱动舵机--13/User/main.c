#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
#include "Key.h"
#include "Servo.h"
extern double Angle ;

uint16_t Num =0;

int main(void)
{
    OLED_Init();

    Servo_Init();
    OLED_ShowString(2,2,"Num:");

    //PWM_Setcompare2(50+100);
    while (1)
    {
        OLED_ShowNum(1,1, Angle_Get(),4);
    }

}



