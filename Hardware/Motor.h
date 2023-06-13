#ifndef __MOTOR_H
#define __MOTOR_H
#include "stm32f10x.h"                  // Device header

void Motor_Init(void);
void Motor1_SetSpeed(int8_t Speed);
void Motor2_SetSpeed(int8_t Speed);
void Motor_Stop(void);

#endif
