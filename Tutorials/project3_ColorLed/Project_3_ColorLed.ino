
const int redLedPin = 11;
const int greenLedPin = 9;
const int blueLedPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

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
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    
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
    
    // delay between each analog read for stability
    delay(5);
    
    // send info from arduino to the computer
    //Serial.print("sensor val: ");
    //Serial.print(sensorVal);
    
    return (float)sensorVal / 1024.0f;
}

void DebugLightBlink()
{
    TurnOn(13);
    delay(100);
    TurnOff(13);
    delay(100);
}

// t = [0, 1]
float Lerp(float a, float b, float t)
{
    return (b - a) * t + a;
}

void SetRGB(int r, int g, int b, int delayTime)
{
    analogWrite(redLedPin, r);
    analogWrite(greenLedPin, g);
    analogWrite(blueLedPin, b);
    delay(delayTime);
}

void DoRainbow()
{
    int delayTime = 500;
    
    SetRGB(255, 0, 0, delayTime);
    SetRGB(0, 255, 0, delayTime);
    SetRGB(0, 0, 255, delayTime);
    SetRGB(255, 255, 0, delayTime);
    SetRGB(255, 0, 255, delayTime);
    SetRGB(0, 255, 255, delayTime);
    
    for(int i = 0; i < 3; ++i)
    {
        SetRGB(0, 0, 0, delayTime);
        SetRGB(255, 255, 255, delayTime);
    }
    
}

void loop() 
{
    DebugLightBlink();
    
    DoRainbow(); // for fun :D
    return;
    
    // read from the heat sensor 
    float redValue = ReadAnalogNormalized(redSensorPin);
    float greenValue = ReadAnalogNormalized(greenSensorPin);
    float blueValue = ReadAnalogNormalized(blueSensorPin);
    
    Serial.print("RGB : "); 
    Serial.print(redValue); 
    Serial.print("\t"); 
    Serial.print(greenValue); 
    Serial.print("\t"); 
    Serial.print(blueValue); 
    Serial.print("\t");
    
    // convert to analog output
    // analogWrite accepts [0, 255]
    int redOutput = (int)Lerp(0.0f, 255.0f, redValue);
    int greenOutput = (int)Lerp(0.0f, 255.0f, greenValue);
    int blueOutput = (int)Lerp(0.0f, 255.0f, blueValue);
    
    Serial.print("output : "); 
    Serial.print(redOutput); 
    Serial.print("\t"); 
    Serial.print(greenOutput); 
    Serial.print("\t"); 
    Serial.print(blueOutput); 
    Serial.println();
    
    // send it to the pin
    analogWrite(redLedPin, redOutput);
    analogWrite(greenLedPin, greenOutput);
    analogWrite(blueLedPin, blueOutput);
}




