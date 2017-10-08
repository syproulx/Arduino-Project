/*
This code is in the public domain.
written by Damian Glinojecki
*/

#include <SoftwareSerial.h>
#define bt_key_power 4 /* Arduino pin 4 to HC-05 KEY pin */

SoftwareSerial mySerial(2, 3);/* Arduino pin 2 to HC-05 TX, pin 3 to HC-05 RX */


void setup()
{
  // set the pins to OUTPUT   
  pinMode(bt_key_power, OUTPUT);  
  // set the pins to LOW 
  digitalWrite(bt_key_power, LOW);  
  /************************************************
  Setting the pins to low is important because in order for us to get into AT mode the key pin
  has to be set to Ground FIRST. Many tutorials out there fail to mention this important fact and 
  therefore many people have problems with getting into the AT mode of the HC-05
  ************************************************/  
  // make sure the key has been LOW for a bit
  delay(100);  
  // set the key pin to High
  digitalWrite(bt_key_power, HIGH);  
  // small delay
  delay(100);    
  // start our serial so we can send and recieve
  // information from the BT module
  Serial.begin(9600);
  // initiate the BT serial at 38400 which is the default 
  // speed at which the BT AT mode operates at
  mySerial.begin(38400);
  
  // self explanatory
  Serial.write("For a list of commands, visit: \n");
  // Send an "AT" command to the AT (without quotes)
  // if response is OK, then we are connected
  // and ready to program the BT module
 }

void loop()
{
  // listen for a response from the HC-05 and write it to the serial monitor
  if (mySerial.available())
    Serial.write(mySerial.read());

  // listen for user input and send it to the HC-05
  if (Serial.available())
    mySerial.write(Serial.read());
   
   
}
