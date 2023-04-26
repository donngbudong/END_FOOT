#ifndef PID_H
#define PID_H

#define ABS(x)		((x>0)? (x): (-x)) 

enum PID_MODE
{
    PID_POSITION = 0,
    PID_DELTA
};

typedef struct
{
//    uint8_t mode;
    //PID ������
    float Kp;
    float Ki;
    float Kd;

    float max_out;  //������
    float max_iout; //���������

    float set;
    float fdb;

    float out;
    float Pout;
    float Iout;
    float Dout;
    float Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
    float error[3]; //����� 0���� 1��һ�� 2���ϴ�

} pid_type_def;

void PID_init(pid_type_def *pid,float KP,float KI,float KD, int max_out, int max_iout);
float PID_calc(pid_type_def *pid, float ref, float set);

#endif