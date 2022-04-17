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

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);
  if (distance < 50) { // detecting obstacle   
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    delay(300);
    
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD); 
    delay(500);
    
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    delay(200);
    
    motor1.run(FORWARD); 
    motor2.run(BACKWARD);
    delay(500);
    
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    delay(200);
  }
  
  else {
    digitalWrite(buzzer, LOW);
    delay(500);
    motor1.run(FORWARD); 
    motor2.run(FORWARD); 
  }
  
}
