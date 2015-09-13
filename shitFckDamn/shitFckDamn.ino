#include <TM1637.h>


#include <Ultrasonic.h>
#include <Servo.h>
#define CLK 2
#define DIO 3


Servo lWing;
Servo rWing;
Servo head;
Servo winch;
Ultrasonic pingA(6);
TM1637 tm1637(CLK, DIO);
boolean imFuckingWaiting = false;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
  lWing.attach(10);
  rWing.attach(9);
  head.attach(11);
  winch.attach(6);
}
void loop() {
  if(!imFuckingWaiting) { 
    letItGo();
  }
  if(!isShirtless()) {
    foldShit();
  } 
  else { 
    waitForShit();
  }
}
void bringMeEveryone() {
  lWing.write(90);
  rWing.write(90);
  head.write(90);
  winch.write(90);
  delay(15);
}
void flapFlapMakeItFlap(Servo servo, int t_ccw, int t_stop, int t_cw, boolean reverse) {
  if(!reverse) {
    servo.write(90);
    delay(15);
    servo.write(0);
    delay(t_ccw);
    servo.write(90);
    delay(t_stop);
    servo.write(180);
    delay(t_cw);
    servo.write(90);
    delay(t_stop);
  } 
  else {
    servo.write(90);
    delay(15);
    servo.write(180);
    delay(t_ccw);
    servo.write(90);
    delay(400);
    servo.write(0);
    delay(t_cw);
    servo.write(90);
    delay(t_stop);
  }
} 
boolean isShirtless() {
  if (pingA.MeasureInCentimeters() < 10) return false;
  return true;
}
void waitForShit() {
  bringMeEveryone();
  Serial.println(pingA.MeasureInCentimeters());
  delay(15);
}
void foldShit() {
  flapFlapMakeItFlap(lWing, 1000, 300, 400, true);
  flapFlapMakeItFlap(rWing, 430, 1000, 550, false);
  flapFlapMakeItFlap(head, 700, 200, 700, false);
  imFuckingWaiting = true;
}
void letItGo() {
  Serial.println("IM DONE WITH YOUR SHIT");
}
