const int motor = 13;
const int PotPin = A0;
const int PhotPin = A2;
int motorspeed = 0;
int Potvalue = 0;
int Photvalue = 0;
int lightvalue;
int incomingByte;

void setup() {
pinMode(motor, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
   if (Serial.available()) 
   { // If data is available to read,
     incomingByte = Serial.read(); // read it and store it in val
   
    
     if (incomingByte != 0) //USE THE POTENTIOMETER AS CONTROLLER
     {
      Potvalue = analogRead(PotPin); 
      motorspeed = map(Potvalue, 0, 1023, 0, 255);
      analogWrite(motor, motorspeed);
      delay(10);
      Serial.println (motorspeed);
     // Serial.println(motorspeed);
     }

     else if (incomingByte == 0)// USE THE PHOTOCELL
   {
    Photvalue = analogRead(PhotPin);
    motorspeed = map(Photvalue, 0, 400, 122, 255);
    analogWrite(motor, motorspeed);
    Serial.println(Photvalue);
      
  }

  else{ analogWrite(motor, LOW);}

     
 }
}


