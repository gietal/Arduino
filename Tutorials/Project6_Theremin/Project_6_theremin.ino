

int sensorValue;
int sensorPin = A0;
int sensorLow = 1023;
int sensorHigh = 0;
int speakerPin = 8;

const int ledPin = 13;

void setup()
{

    Serial.begin(9600);
    
    Serial.println("setup begin");
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    
    Serial.println("calibrating sensor...");
    // calibrate the sensor for 5s
    // millis() returns milisecond passed since the last reset
    while(millis() < 5000)
    {
        // read sensor value
        sensorValue = analogRead(sensorPin);
        if(sensorValue > sensorHigh)
        {
            sensorHigh = sensorValue;
        }
        if(sensorValue < sensorLow)
        {
            sensorLow = sensorValue;
        }
        
        //delay for stability
        delay(1);
    }
    
    Serial.println("calibration complete!");
    Serial.print("sensor Low : "); Serial.println(sensorLow);
    Serial.print("sensor High: "); Serial.println(sensorHigh);
    Serial.println("--------------------------------");
    
    // turn off led
    digitalWrite(ledPin, LOW);
}

void loop()
{
    // read value
    sensorValue = analogRead(A0);
    
    // map the calibrated sensor value to frequency 50 - 4000
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    
    // debug
    Serial.print("pitch: "); Serial.println(pitch);
    
    // param: (pin, frequency, how long in milisecond);
    tone(speakerPin, pitch, 20);

    // delay to give time for the speaker to play sound
    delay(10);
}