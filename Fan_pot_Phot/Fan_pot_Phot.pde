

import processing.serial.*;
// serial connection
Serial port;
 
 
void setup() {
  // init serial-port
  size(500,255); //create a window
   String portName = Serial.list()[0]; //port scanning
  port = new Serial(this, portName, 9600); //creating pointer to Serial instance 
  
}
 
void draw() {
if (keyPressed) {
    if (key == 'b' || key == 'B') { //if b is pressed
       int number = 5; //send number 5
      // debug
      println("now sending number: "+number); //printing a string + string + new line char
      // send number
      port.write(number); //writing the number to the serial port, so to the arduino
      
    }
    else if (key == 'c' || key == 'C') {//if c is pressed
       int number = 0;//send number 0
      // debug
      println("now sending number: "+number);//printing a string + string + new line char
      // send number
      port.write(number); //writing the number to the serial port, so to the arduino
      
    }
    
}

}
 
 
// this part is executed, when serial-data is received
void serialEvent(Serial p) {

    // get message till line break (ASCII > 13)
    String message = p.readStringUntil(13);
    // just if there is data
    if (message != null) {
      println("message received: "+trim(message)); //print out string + string
    }
}