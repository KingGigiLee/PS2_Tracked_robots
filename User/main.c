#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "sys.h"
#include "PS2.h"
#include "usart.h"
#include "LED.h"
#include "MOVE.h"

int PS2_KEY = 0;

int main(void)
{
    //OLED_Init();
    //Key_Init();
    uart_init(72, 9600);           	//=====����1��ʼ��
    Delay_ms(1000);                 //=====��ʱ�ȴ���ʼ���ȶ�
    Motor_Init();
    LED_Init();
    PS2_Init();						//=====ps2�����˿ڳ�ʼ��
    PS2_SetInit();		 			//=====ps2���ó�ʼ��,���á����̵�ģʽ������ѡ���Ƿ�����޸�
    Delay_ms(1000);

    while(1)
    {
        PS2_KEY = PS2_DataKey();
		Delay_ms(20);
		switch(PS2_KEY)
		{
			case 5: Go(); break;
			case 7: Back(); break;
			case 8: Left(); break;
			case 6: Right(); break;
			case 9: Left_90(); break;
			case 10: Right_90(); break;
			
			default: Motor_Stop();break;  
		}
    }
}
