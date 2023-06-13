#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void LED_Init(void)
{
	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	//���ö˿�ģʽ
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����
	//�ṹ���Ա
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //������� 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_12; //ѡ��1�ź�2�ſ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOD, GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_12); //�������ݶ˿�λ
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
