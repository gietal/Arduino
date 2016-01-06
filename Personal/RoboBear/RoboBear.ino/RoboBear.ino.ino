#include <Servo.h>

// max eight servo objects can be created
Servo rightServo;
Servo leftServo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  rightServo.attach(10);
  leftServo.attach(9);
  
  //Test();
  
  //OpenArms();
}

void Test()
{
  //rightServo.write(0);
  leftServo.write(0);
  
  delay(1000);
  //rightServo.write(130);
  leftServo.write(170);
  delay(1000);
}

void OpenArms()
{
  rightServo.write(10);
  leftServo.write(170);
}
void CloseArms()
{
  rightServo.write(170);
  leftServo.write(10);
}

void ArmsForward()
{
  rightServo.write(90);
  leftServo.write(90);
}

void Hug()
{
  OpenArms();
  delay(1000);
  CloseArms();
  delay(1000);
}

void Walk()
{
  rightServo.write(100);
  leftServo.write(100);
  delay(1000);
  rightServo.write(50);
  leftServo.write(50);
  delay(1000);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  //Walk();
  Test();
}
