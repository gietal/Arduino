
const int sensorPin = A0;
const int speakerPin = 8;

// array of button
int buttons[6];

// middle C, D, E, F
int notes[] = {262, 294, 330, 349};

void setup()
{
    // give the first element of the array value 2
    buttons[0] = 2;
    
    Serial.begin(9600);
    
    Serial.println("setup begin");
    
    Serial.println("--------------------------------");
    
    pinMode(speakerPin, OUTPUT);
}

void loop()
{
    int keyVal = analogRead(sensorPin);
    Serial.print("keyVal: "); Serial.println(keyVal);
    
    if(keyVal == 1023)
    {
        tone(speakerPin, notes[0]);
    }
    else if(keyVal >= 990 && keyVal <= 1010)
    {
        tone(speakerPin, notes[1]);
    }
    else if(keyVal >= 505 && keyVal <= 515)
    {
        tone(speakerPin, notes[2]);
    }
    else if(keyVal >= 5 && keyVal <= 10)
    {
        tone(speakerPin, notes[3]);
    }
    else
    {
        noTone(speakerPin);
    }
    
    // delay to give time for the speaker to play sound
    delay(10);
}