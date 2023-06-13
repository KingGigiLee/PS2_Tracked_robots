#include "stm32f10x.h"                  // Device header
#include "Motor.h"

void Go(void)
{
	Motor1_SetSpeed(90);
	Motor2_SetSpeed(90);
}
void Back(void)
{
	Motor1_SetSpeed(-90);
	Motor2_SetSpeed(-90);
}
void Left(void)
{
	Motor1_SetSpeed(70);
	Motor2_SetSpeed(-70);
}
void Right(void)
{
	Motor1_SetSpeed(-70);
	Motor2_SetSpeed(70);
}


void Left_90(void)
{
	Motor1_SetSpeed(90);
	Motor2_SetSpeed(0);
}
void Right_90(void)
{
	Motor1_SetSpeed(0);
	Motor2_SetSpeed(90);
}
