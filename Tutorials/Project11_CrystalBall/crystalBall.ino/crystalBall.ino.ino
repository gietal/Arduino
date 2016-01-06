#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 2, 8, 4, 5);
const int switchPin = 6;
const int heatSensorPin = A0;
const float maxCelcius = 125.0f;
const float minCelcius = -40.0f;

int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(3, 2); // 16 rows, 2 columns
  pinMode(switchPin, INPUT); 
  
  lcd.setCursor(0,0); // row, column
  lcd.print("ask the");
  lcd.setCursor(0,1);
  lcd.print("crystal ball");
}

void CrystalBallLoop()
{
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState)
  {
    if(switchState == LOW)
    {
      reply = random(8);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("the ball says:");
      lcd.setCursor(0,1);
      
      switch(reply)
      {
        case 0:
          lcd.print("yes");
          break;
        case 1:
          lcd.print("most likely");
          break;
        case 2:
          lcd.print("certainly");
          break;
        case 3:
          lcd.print("good");
          break;
        case 4:
          lcd.print("unsure");
          break;
        case 5:
          lcd.print("ask again");
          break;
        case 6:
          lcd.print("doubtful");
          break;
        case 7:
          lcd.print("no");
          break;
      }
    }
  }
  
  prevSwitchState = switchState;
}

float ReadAnalogNormalized(int pin)
{
    // digitalRead is binary [LOW, HIGH]
    // analogRead is not binary
    
    // the analog to digital converter in arduino
    // converts from analog to [0, 1023]
    int sensorVal = analogRead(pin);
    
    // send info from arduino to the computer
    Serial.print("sensor val: ");
    Serial.print(sensorVal);
    
    return (float)sensorVal / 1024.0f;
}

void ThermometerLoop()
{
  // read from heat sensor
  float n = ReadAnalogNormalized(heatSensorPin);
  float celcius = (maxCelcius - minCelcius) * n;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temperature:");
  lcd.setCursor(0,1);
  lcd.print(celcius);
  lcd.print("C");
  
  delay(500);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //CrystalBallLoop();
  ThermometerLoop();
}
