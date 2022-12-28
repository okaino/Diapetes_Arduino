#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial bt_com(2,3); // RX, TX

const int AOUTpin=A0; //Analog Oput 
const int DOUTpin=13; //Digital Oput

void setup() {
Serial.begin(9600);//sets the baud rate
bt_com.begin(9600);
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
}

void loop()
{
  
  int value;
  int value1;
  int value2;
  int valueFin;
  int data; 
  
  
    value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  delay(10);
  value1 = analogRead(AOUTpin);
  delay(10);
  value2 = analogRead(AOUTpin);
  delay(10);
  valueFin = ( value + value1 + value2 )/3;

  
    bt_com.println(valueFin);
    bt_com.print(",");
    
   
  
//limit= digitalRead(DOUTpin);//reads the digital value from the alcohol sensor's DOUT pin
//  Serial.print("Alcohol value: ");
//  Serial.println(valueFin);//prints the alcohol value
}

