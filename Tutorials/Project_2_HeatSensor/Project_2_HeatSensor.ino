
const int sensorPin = A0;
const float baseTemp = 24.0; // base temperature = 24 celcius
const float differenceThreshold = 0.5f; // for every 0.5 degree, change the state of the lights
const float maxCelcius = 125.0f;
const float minCelcius = -40.0f;

void setup() 
{
    // open connection between arduino and the computer
    // to see the values from the analog input
    // 9600 bits per second is the speed at which arduino communicates
    // 
    Serial.begin(9600); 
    Serial.println("--- Start Serial Monitor SEND_RCVE ---");
    
    // debug light
    pinMode(13, OUTPUT); 
    
    // set all pins to be output
    for(int i = 2; i <= 5; ++i)
    {
        // set the pin as output
        pinMode(i, OUTPUT);
        
        // and turn it off
        digitalWrite(i, LOW);
    }
    
    for(int i = 0; i < 5; ++i)
    {
        DoRail();
    }
    
    
    Serial.println("--- setup() finished ---");
}

void TurnOn(int pin)
{
    digitalWrite(pin, HIGH);
}

void TurnOff(int pin)
{
    digitalWrite(pin, LOW);
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

void DoRail()
{
    TurnOn(2);
    TurnOff(4);
    TurnOff(5);
    delay(100);

    TurnOff(2);
    TurnOn(4);
    TurnOff(5);
    delay(100);

    TurnOff(2);
    TurnOff(4);
    TurnOn(5);
    delay(100);
}

void DebugLightBlink()
{
    TurnOn(13);
    delay(100);
    TurnOff(13);
    delay(100);
}

void DoLogic(float celcius)
{
    // turn everything off
    TurnOff(2);
    TurnOff(4);
    TurnOff(5);
    
    if(celcius >= baseTemp )
    {
        // 24 - 25, turn 1 one
        TurnOn(2);
    }
    
    if(celcius >= baseTemp + differenceThreshold)
    {
        // 25 - 26
        // turn another 1 on
        TurnOn(4);
    }
    
    if(celcius >= baseTemp + differenceThreshold * 2.0f)
    {
        // 26 - 27
        TurnOn(5);
    }
    
    if(celcius >= baseTemp + differenceThreshold * 3.0f)
    {
        // too hot, so do a rail
        DoRail();
    }
}

void loop() 
{
    DebugLightBlink();
    
    // read from the heat sensor 
    float normalized = ReadAnalogNormalized(sensorPin);
    
    // convert to volt
    float volt = normalized * 5.0f;
    Serial.print(", volt: "); Serial.print(volt);
    
    // from this datasheet: www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf
    // we know that tmp36 sensor outputs minimum -40c, and max 125c
    // map [0, 1] to [-40, 125]
    float celcius = (maxCelcius - minCelcius) * normalized;
    
    Serial.print(", celcius: ");
    Serial.print(celcius);
    Serial.println();
    
    DoLogic(celcius);
}




