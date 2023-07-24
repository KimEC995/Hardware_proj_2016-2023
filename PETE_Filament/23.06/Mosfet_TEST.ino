int outPin = 9;

void setup()
{
pinMode(outPin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
digitalWrite(outPin,HIGH);
delay(1000);
digitalWrite(outPin,LOW);
delay(1000);

Serial.println(outPin);

}
