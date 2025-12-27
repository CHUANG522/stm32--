#include "stm32f10x.h"   // Device header
#include "Delay.h"
uint32_t CountSensor=0;
void CountSensor_Init(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_Struct;
	GPIO_Struct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Struct.GPIO_Pin=GPIO_Pin_14;
	GPIO_Struct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Struct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	EXTI_InitTypeDef   EXTI_Init_Struct;
	EXTI_Init_Struct.EXTI_Line=EXTI_Line14;
	EXTI_Init_Struct.EXTI_LineCmd=ENABLE;
	EXTI_Init_Struct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Init_Struct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_Init_Struct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef   NVIC_Init_Struct;
	NVIC_Init_Struct.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_Init_Struct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init_Struct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_Init_Struct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_Init_Struct);
}
uint32_t  CountSensor_Get(void){
	return CountSensor;}

void EXTI15_10_IRQHandler(void){
	if(  EXTI_GetITStatus(EXTI_Line14)  ==  SET){// 消抖函数
		if( GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) ==0){
			EXTI_ClearITPendingBit(EXTI_Line14);
			CountSensor++;
				Delay_ms(20);
		}
		
	
		
	}
		
}
 
