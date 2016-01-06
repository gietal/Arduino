
const int sensorPin = A0;
const float baseTemp = 20.0; // base temperature = 20 celcius

void setup() 
{
    // open connection between arduino and the computer
    // to see the values from the analog input
    // 9600 bits per second is the speed at which arduino communicates
    // 
    Serial.begin(9600); 
    
    // set all pins to be output
    for(int i = 2; i <= 5; ++i)
    {
        // set the pin as output
        pinMode(i, OUTPUT);
        
        // and turn it off
        digitalWrite(i, LOW);
    }
    
}

void loop() 
{
    
}