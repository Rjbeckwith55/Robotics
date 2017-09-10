/*
 Name:		ArduinoRoboteqTest.ino
 Created:	7/5/2017 4:54:47 PM
 Author:	rjbec
*/
#include "RobotEQ.h"
// the setup function runs once when you press reset or power the board
int ledpin = 9;
void setup() {
	pinMode(ledpin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(ledpin, HIGH);
}
