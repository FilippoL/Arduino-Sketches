
const int analogInPin = A0;// Analog input pin that the potentiometer is attached to
const int BuzzPin = 13;

void setup() {
   // initialize serial communications at 9600 bps:
  Serial.begin(9600);

}

void loop() {
   // read the analog in value:
  int sensorValue = analogRead(analogInPin);
  
   Serial.println(sensorValue);
   

  tone(BuzzPin, sensorValue);

  
  delay(2);

}
