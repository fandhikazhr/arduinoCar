#include <AFMotor.h>
#define trigPin A5 
#define echoPin A4 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(3, MOTOR12_1KHZ);
int buzzer = 12;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motor1.setSpeed(150); //speed motor 1-255
  motor2.setSpeed(150); //speed motor 1-255
}

void loop() {



}
