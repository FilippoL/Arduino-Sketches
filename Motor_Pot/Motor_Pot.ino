const int motor = 13;
const int PotPin = A0;
int motorspeed = 0;
int Potvalue = 0;

void setup() {
pinMode(motor, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
  Potvalue = analogRead(PotPin);
  motorspeed = map(Potvalue, 0, 1023, 122, 255);
  analogWrite(motor, motorspeed);
  delay(10);
  Serial.println(Potvalue);
  
  Serial.println(motorspeed);
 
}

