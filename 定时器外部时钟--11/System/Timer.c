#include "stm32f10x.h"   // Device header
#include "Delay.h"
extern  uint16_t Num;



void Timer_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef    GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

    GPIO_Init(GPIOA,&GPIO_InitStruct);


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

    TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);


    TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;
    TIM_TimeBaseInitStructure.TIM_Period=10-1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);

    TIM_ClearFlag(TIM2, TIM_FLAG_Update);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef  NVIC_Init_Struct;
    NVIC_Init_Struct.NVIC_IRQChannel=TIM2_IRQn;
    NVIC_Init_Struct.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init_Struct.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_Init_Struct.NVIC_IRQChannelSubPriority=0;
    NVIC_Init(&NVIC_Init_Struct);
    TIM_Cmd(TIM2,ENABLE);
}
uint16_t Timer_GetCounter(void)
{
    //  Delay_ms(50);   怎么让传感器计数准确！
    return TIM_GetCounter(TIM2);
}
/*
void TIM2_IRQHandler(void)
{

    if (TIM_GetITStatus(TIM2,TIM_IT_Update == SET))
    {

        Num++;
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
}
*/













