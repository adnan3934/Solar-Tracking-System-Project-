//AUTOMATIC SOLAR TRACTKING SYSTEM PROJECT DONE BY ADNAN
//..
//Include the servo motor library
#include <Servo.h>
//Define the LDR sensor pins
#define LDR1 A0
#define LDR2 A1
//Define the error value. You can change it as you like
#define error 10
//Starting point of the servo motor
int Spoint =  90;
//Create an object for the servo motor
Servo servo;

void setup() {
//Include servo motor PWM pin
  servo.attach(11);
//Set the starting point of the servo
  servo.write(Spoint);
  delay(1000);
}

void loop() {
//Get the LDR sensor value
  int ldr1 = analogRead(LDR1);
//Get the LDR sensor value
  int ldr2 = analogRead(LDR2);

//Get the difference of these values
  int value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);

//Check these values using a IF condition
  if ((value1 <= error) || (value2 <= error)) {

  } else {
    if (ldr1 > ldr2) {
      Spoint = --Spoint;
    }
    if (ldr1 < ldr2) {
      Spoint = ++Spoint;
    }
  }
//Write values on the servo motor
  servo.write(Spoint);
  delay(80);
}
