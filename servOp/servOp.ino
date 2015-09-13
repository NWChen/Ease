#include <Servo.h>


  Servo leftWing;
  Servo rightWing;
  Servo mainServo;
  
void setup() {
  // put your setup code here, to run once:

  rightWing.attach(9);
  leftWing.attach(10);
  mainServo.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:


  //Right wing
  rightWing.write(90); //set to neutral pos
  delay(15); //give time for leftWing to update
  rightWing.write(0); //full speed ccw
  delay(430);
  rightWing.write(90); //stop
  delay(1000);
  rightWing.write(180); //full speed cw
  delay(550);
  rightWing.write(90); //stop
  delay(1000);

  //Left Wing

  leftWing.write(90);
  delay(15);
  leftWing.write(0); //full speed ccw
  delay(430);
  leftWing.write(90); //stop
  delay(1000);
  leftWing.write(180); //full speed cw
  delay(550);
  leftWing.write(90); //stop
  delay(1000);

  //Main Servo
  leftWing.write(90);
  delay(15);
  leftWing.write(0); //full speed ccw
  delay(430);
  leftWing.write(90); //stop
  delay(1000);
  leftWing.write(180); //full speed cw
  delay(550);
  leftWing.write(90); //stop
  delay(1000);

  
  
}
