#include <Servo.h>

Servo servo;

int const knobPin = A0;
int const servoPin = 9;
int angle;
int knobVal;

void setup()
{
    servo.attach(servoPin);
    
    Serial.begin(9600);
    
    Serial.println("setup completed");
    
}

void loop()
{
    knobVal = analogRead(knobPin);
    
    Serial.print("knob val: ");
    Serial.print(knobVal);
    
    // map [0, 1023] to [0, 180]
    // analog pin return [0, 1023]
    // the servo only work with 180 degree angle
    angle = map(knobVal, 0, 1023, 0, 179);
    
  
    Serial.print(", ");
    Serial.println(angle);
    
    // output the angle to servo
    servo.write(angle);
    
    // delay for stability
    delay(15);
}