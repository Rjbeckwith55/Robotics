#include <Servo.h>
//Declare the output pins for the 4 motors
int motor1 = 8;
int motor2 = 9;
int motor3 = 10;
int motor4 = 11;
//Declare the input pins for the 6 channel in pins
int ch1 = 2;
int ch2 = 3;
int ch3 = 4;
int ch4 = 5;
int ch5 = 6;
int ch6 = 7;
int rc1, rc2, rc3, rc4, rc5, rc6;
int hor1, vert1, switch1, hor2, vert2;
int minpwm = 1100;
int maxpwm = 1900;

//Delcare 4 "Servos" these will be the outputs for the 4 motors
//We are using the servo library because it is capable of sending a
//1000 to 2000 PPM signal unlike the analogWrite().
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Attach the 4 servos at the coresponding motor pins
  servo1.attach(motor1);
  servo2.attach(motor2);
  servo3.attach(motor3);
  servo4.attach(motor4);

  //Set the 6 Arduino pins to recieve input from the reciever
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  pinMode(ch5, INPUT);
  pinMode(ch6, INPUT);

  //Start serial for debugging messages
  Serial.begin(9600);

}

void loop() {
  //Read all the channels from the rc reciever
  rc1 = pulseIn(ch1, HIGH); //hor1 right stick left/right
  rc2 = pulseIn(ch2, HIGH); //vert1 right stick up/down
  rc3 = pulseIn(ch3, HIGH); //hor2 left stick left/right
  rc4 = pulseIn(ch4, HIGH); //switch1 back left Toggle switch
  rc5 = pulseIn(ch5, HIGH); //vert2 left stick left/right
  rc6 = pulseIn(ch6, HIGH);

  if (rc1 > 0 && rc2 > 0 && rc3 > 0 && rc4 > 0) {
    Serial.println("Connected");
  }
  else
    Serial.println("Something is not connected");

  //Programmed limits so the controller works more evenly
  if (rc1 > maxpwm)
    rc1 = maxpwm;
  else if (rc1 < minpwm)
    rc1 = minpwm;
  else if (rc2 > maxpwm)
    rc2 = maxpwm;
  else if (rc2 < minpwm)
    rc2 = minpwm;
  else if (rc3 < minpwm)
    rc3 = minpwm;
  else if (rc3 > maxpwm)
    rc3 = maxpwm;

  /* // Print out the data of the RC (for debugging and calibration)
    Serial.println(rc1);
    Serial.println(rc2);
    Serial.println(rc3);
    Serial.println(rc4);*/
  if (rc4 < minpwm) {

  }
  rc1 = map(hor1, 1000, 2000, 10, 170); // sends a pulse out using the servo library. 0 = 1000 90 = 1500 180 = 2000
  Serial.println(hor1);
  servo1.write(hor1);

  delay(50);
}
