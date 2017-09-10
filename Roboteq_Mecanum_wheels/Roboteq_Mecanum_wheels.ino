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
//Variable for the different buttons on the controller
int hor1, vert2, hor2, rc4, vert2, rc6;
//Variables for the amount the "servos"(Motors) are going to move
int V1, V2, V3;
//Limits on the controller
int minpwm = 1100;
int maxpwm = 1900;
//Thresholds to set the zero easier
int threshold1 = 1450;
int threshold2 = 1550;

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
  hor1 = pulseIn(ch1, HIGH); //hor1 right stick left/right
  vert2 = pulseIn(ch2, HIGH); //vert1 right stick up/down
  hor2 = pulseIn(ch3, HIGH); //hor2 left stick left/right
  switch1 = pulseIn(ch4, HIGH); //switch1 back left Toggle switch
  vert2 = pulseIn(ch5, HIGH); //vert2 left stick left/right
  rc6 = pulseIn(ch6, HIGH); // That weird nob thingy

  if (hor1 > 0 && vert2 > 0 && hor2 > 0) {
    Serial.println("Connected");
  }
  else
    Serial.println("Something is not connected");

  //Programmed limits so the controller works more evenly
  if (hor1 > maxpwm)
    hor1 = maxpwm;
  else if (hor1 < minpwm)
    hor1 = minpwm;
  else if (vert2 > maxpwm)
    vert2 = maxpwm;
  else if (vert2 < minpwm)
    vert2 = minpwm;
  else if (hor2 < minpwm)
    hor2 = minpwm;
  else if (hor2 > maxpwm)
    hor2 = maxpwm;

    //Format the V values in a value from 0 to 180 for "servo" use
   // sends a pulse out using the servo library. 0 = 1000 90 = 1500 180 = 2000
  hor1 = map(V1, 1100, 1900, 10, 170);
  vert2 = map(V2, 1100, 1900, 10, 170);
  hor2 = map(V3, 1100, 1900, 10, 170);
  //vert2 = map(vert2, 1000, 2000, 10, 170); //unused
  
  /* // Print out the data of the RC (for debugging and calibration)
    Serial.println(hor1);
    Serial.println(vert2);
    Serial.println(hor2);
    Serial.println(rc4);*/

    
  // Switch is the toggle for the speed modes
  if (rc4 < minpwm) {
    if (hor1 < threshold1 && abs(V1) > abs(V2)) { //LEFT
      servo1.write(V1 - (V3 / 2) / 2);
      servo2.write(-V1 - (V3 / 2) / 2);
      servo3.write(-V1 - (V3 / 2) / 2);
      servo4.write(V1 - (V3 / 2) / 2);
    }
    else{ //Turn off all motors when no command is given
      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
      servo4.write(90);
    }
  }

  delay(50);
}
