#include <AFMotor.h>
#define trigPin A5 
#define echoPin A4 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(3, MOTOR12_1KHZ);
int buzzer = 12;
