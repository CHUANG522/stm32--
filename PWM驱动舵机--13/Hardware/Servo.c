#include "stm32f10x.h"                 // Device header
#include "Key.h"
#include "PWM.h"
double Angle=0;
void Servo_Init(void)
{
    Key_Init();
    PWM_Init();
}
double Angle_Get(void)
{
  //  uint16_t Angle=0;

    if (Key_GetNum() == 1)
    {
        Angle +=45;
        PWM_Setcompare2(Angle *10/9 +50);
    }


    if (Angle == 180)
    {

        PWM_Setcompare2(Angle *10/9 +50);
        Angle=0;
    }
	return Angle ;
}
