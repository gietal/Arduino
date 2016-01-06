const int switchPin = 8;
unsigned long prevTime = 0;
int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 1000; // interval between each led light up in ms
void setup() 
{
  // set all led to be output
  for(int i = 2; i < switchPin; ++i)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);

}

void Blink()
{
  delay(100);
  for(int i = 2; i < switchPin; ++i)
  {
    digitalWrite(i, LOW);
  }
  delay(100);
  for(int i = 2; i < switchPin; ++i)
  {
    digitalWrite(i, HIGH);
  }
  
}

void loop() 
{
  // get the current time
  unsigned long currentTime = millis();
  
  // if it goes over the interval
  if(led == switchPin)
  {
    // we've reached the end do something
    Blink();
  }
  else
  {
    if(currentTime - prevTime > interval)
    {
      // 
      prevTime = currentTime;
      
        // turn on light
        digitalWrite(led, HIGH);
        ++led;
      
    }
  }
  
  
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState)
  {
    // reset
    for(int i = 2; i < switchPin; ++i)
    {
      digitalWrite(i, LOW);
    }
    led = 2;
    prevTime = currentTime;
  }
  
  // save the urrent switch state
  prevSwitchState = switchState;

}
