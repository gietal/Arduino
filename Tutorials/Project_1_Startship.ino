int switchState = 0;

void Blink(int delayTime)
{
    // turn one of the red on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    // wait
    delay(delayTime);

    // turn the other red on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    // wait again before blinking
    delay(delayTime);
}

void TurnGreen(boolean on)
{
    digitalWrite(7, on ? HIGH : LOW);
}

void TurnRed(boolean on)
{
    digitalWrite(4, on ? HIGH : LOW);
    digitalWrite(5, on ? HIGH : LOW);
}

void setup() 
{
  // put your setup code here, to run once:
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    
    // turn everythin off
    TurnGreen(false);
    TurnRed(false);
    
    // blink 5x
    for(int i = 0; i < 10; ++i)
    {
        Blink(100);
    }
}

void loop() 
{
    // put your main code here, to run repeatedly:
    
    // read state
    switchState = digitalRead(2);
    
    if(switchState == LOW)
    {
        // button is not pressed
        
        // turn on green
        TurnGreen(true);
        // turn off reds
        TurnRed(false);
    }
    else
    {
        // turn off green
        TurnGreen(false);
        
        // blink
        Blink(50);
        
    }
}
