#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //开启时钟
		
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //输入上拉模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //GPIO输出速度
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//PB1 | PB11 按键检测
//返回值：uint8_t ,等同于unsigned char
uint8_t Key_GetNum(void) 
{
	uint8_t KeyNum = 0;
	//读取PB1端口值
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
	{
		Delay_ms(20); //开关消抖
		while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0);
		Delay_ms(20); //开关消抖
		KeyNum = 1;
	}
	/*
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		Delay_ms(20); //开关消抖
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		Delay_ms(20); //开关消抖
		KeyNum = 2;
	}
	*/
	
	return KeyNum;
}
