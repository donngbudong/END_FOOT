#include "vofa_task.h"
#include "CAN_receive.h"
#include "pid.h"

extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart5;

vofa_date vofa_date_t[8];
unsigned char tail[6] = {0x00, 0x00, 0x80, 0x7f, 0x0D, 0x0A}; 
unsigned char huan=0x0D; 
unsigned char huan1=0x0A; 

extern motor_measure_t motor_chassis[5];
extern motor_measure_t motor_gimbal[3];
extern motor_measure_t motor_shoot[4];
extern pid_type_def pid_shoot[5];
extern pid_type_def pid_gimbal[5];
extern float Eular[3];





void vofa_send(void)
{
	uint16_t i=0;

//	vofa_date_t[1].c=Eular[1];
//	vofa_date_t[2].c=Eular[2];
//	vofa_date_t[3].c=pid_gimbal[1].set;
//	vofa_date_t[4].c=pid_gimbal[2].set;
	vofa_date_t[0].c=5000;
	vofa_date_t[1].c=motor_chassis[1].speed_rpm;
	vofa_date_t[2].c=motor_chassis[2].speed_rpm;
	vofa_date_t[3].c=motor_chassis[3].speed_rpm;
	vofa_date_t[4].c=motor_chassis[4].speed_rpm;
	
	
	for(i = 0; i<4; i++)	
	{
		HAL_UART_Transmit(&huart6,&vofa_date_t[0].b[i],1,100);
	}


	for(i = 0; i<4; i++)
	{
		HAL_UART_Transmit(&huart6,&vofa_date_t[1].b[i],1,100);
	}


	for(i = 0; i<4; i++)
	{
		HAL_UART_Transmit(&huart6,&vofa_date_t[2].b[i],1,100);
	}
	
	for(i = 0; i<4; i++)
	{
		HAL_UART_Transmit(&huart6,&vofa_date_t[3].b[i],1,100);
	}
		for(i = 0; i<4; i++)
	{
		HAL_UART_Transmit(&huart6,&vofa_date_t[4].b[i],1,100);
	}
	
	
	
		HAL_UART_Transmit(&huart6,&tail[0],1,100);
		HAL_UART_Transmit(&huart6,&tail[1],1,100);
		HAL_UART_Transmit(&huart6,&tail[2],1,100);
		HAL_UART_Transmit(&huart6,&tail[3],1,100);
//		HAL_UART_Transmit(&huart6,&tail[4],1,100);
//		HAL_UART_Transmit(&huart6,&tail[5],1,100);

}

