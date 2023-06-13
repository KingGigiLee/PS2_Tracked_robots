#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void LED_Init(void)
{
	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	//配置端口模式
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量
	//结构体成员
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_12; //选中1号和2号口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOD, GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_12); //设置数据端口位
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_8);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_8);
}

void LED1_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_8) == 0)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_8);
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_10);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_10);
}

void LED2_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_10) == 0)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_10);
	}
	else
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_10);
	}
}

void LED3_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}

void LED3_OFF(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_12);
}

void LED3_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12) == 0)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	}
}

void Beep(void)
{
	LED1_Turn();
}
