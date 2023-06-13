#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
    //开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructute;
	GPIO_InitStructute.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructute.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructute.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructute);
    
    //选择时基单元时钟
    TIM_InternalClockConfig(TIM3);
    
    //配置时基单元
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;       //ARR
    TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;     //PSC
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;       //CCR
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    
    TIM_Cmd(TIM3, ENABLE);
}

void PWM_SetCompare3(uint16_t Compare)
{
    TIM_SetCompare3(TIM3, Compare);
}

void PWM_SetCompare4(uint16_t Compare)
{
    TIM_SetCompare4(TIM3, Compare);
}
