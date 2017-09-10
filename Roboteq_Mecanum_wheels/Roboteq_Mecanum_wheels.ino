#include <Servo.h>
int motor1 = 6;
int motor2 = 7;
int motor3 = 8;
int motor4 = 9;
int ch1 = 2;
int ch2 = 3;
int ch3 = 4;
int ch4 = 5;
int rc1,rc2,rc3,rc4;

Servo servo;
void setup() {
  // put your setup code here, to run once:
 servo.attach(motor1);
pinMode(ch1,INPUT);
pinMode(ch2,INPUT);
pinMode(ch3,INPUT);
pinMode(ch4,INPUT);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
Serial.begin(9600);

}

void loop() {
rc1 = pulseIn(ch1,HIGH);
rc2 = pulseIn(ch1,HIGH);
rc3 = pulseIn(ch1,HIGH);
rc4 = pulseIn(ch1,HIGH);
if (rc1 > 0 && rc2 > 0 && rc3 > 0 && rc4>0){
  Serial.println("Connected");
}
else
Serial.println("Something is not connected");

Serial.println(rc1);
rc1=map(rc1,1000,2000,10,170); // sends a pulse out using the servo library. 0 = 1000 90 = 1500 180 = 2000
Serial.println(rc1);
servo.write(rc1);

delay(50);
}
