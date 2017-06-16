

void setup() {
 // pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
  
}

void loop() {
  int sensorReadingX = analogRead(A0);
  int sensorReadingY = analogRead(A1);

   
  int sensorMappedX = map(sensorReadingX, 0, 1023, 0, 100); 
  int sensorMappedY = map(sensorReadingY, 0, 1023, 0, 100); 
  

  Serial.print(sensorMappedX, DEC);
  Serial.print("-");
  Serial.println(sensorMappedY, DEC);
 


  delay(100);                            // Wait 100 milliseconds
}

