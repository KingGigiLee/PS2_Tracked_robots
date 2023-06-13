#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
    //开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//配置端口模式
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量
	//结构体成员
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    PWM_Init();
}

void Motor1_SetSpeed(int8_t Speed)
{
    if (Speed >= 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_5);
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
        PWM_SetCompare3(Speed);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        GPIO_SetBits(GPIOA, GPIO_Pin_4);
        PWM_SetCompare3(-Speed);
    }
}

void Motor2_SetSpeed(int8_t Speed)
{
    if (Speed >= 0)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_6);
        GPIO_ResetBits(GPIOA, GPIO_Pin_7);
        PWM_SetCompare4(Speed);
    }
    else
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_6);
        GPIO_SetBits(GPIOA, GPIO_Pin_7);
        PWM_SetCompare4(-Speed);
    }
}

void Motor_Stop(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
}
