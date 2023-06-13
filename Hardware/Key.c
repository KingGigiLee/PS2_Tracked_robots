#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //����ʱ��
		
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //��������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //GPIO����ٶ�
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//PB1 | PB11 �������
//����ֵ��uint8_t ,��ͬ��unsigned char
uint8_t Key_GetNum(void) 
{
	uint8_t KeyNum = 0;
	//��ȡPB1�˿�ֵ
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
	{
		Delay_ms(20); //��������
		while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0);
		Delay_ms(20); //��������
		KeyNum = 1;
	}
	/*
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		Delay_ms(20); //��������
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		Delay_ms(20); //��������
		KeyNum = 2;
	}
	*/
	
	return KeyNum;
}
