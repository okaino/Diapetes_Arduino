#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial bt_com(2,3); // RX, TX

const int AOUTpin=A0;
const int DOUTpin=13;

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
///*Bluetooth buzzer
// * Created on 2 febraury,2021
// * by zayed alam
// * Hi guys,
// * I am gonna show you how to control sounds using android app.It is a very simple
// * and fun project.This works like this:Go to the google play store.Search for"
// * Smart Bluetooth" and there will be a bluetooth logo.Install it.Then turn on 
// * your bluetooth,Then click on "Search".After sometime after searching,you will
// * find "HC-05" and that is our bluetooth module.click on it.Then it will ask to 
// * Select a theme by holding on the any of the two options.Then after it has
// * conected,on the top right corner,there will be a settings sign.Click on it.
// * Then a drop down box shows.Then click on terminal.Then if you type 'a',you 
// * will hear a sound by the buzzer.That means it is working.You will figure 
// * something on my code like"if(data=='e'){"That means if you type 'e' key,
// * it will create a sound from the buzzer.You can also edit the keys or create
// * a new condition like if we type this key,it will make this sound.
// * 
// * That's all of that.For more stffs like schematics and what are the materials
// * you have to gather,go to:https://create.arduino.cc/projecthub/zayedalam/control-sound-using-bluetooth-a670ee
// */
//#include <SoftwareSerial.h>
//
//SoftwareSerial bt_com(11,12); // RX, TX
//
////Variable for storing received data  
//const int buzzer=13;//Buzzers pin
//
//void setup() {
//  pinMode(A0,INPUT);
//
//  
//  // put your setup code here, to run once:
//    Serial.begin(9600); //Sets the baud for serial data transmission
//    bt_com.begin(9600);
//    pinMode(buzzer,OUTPUT);//defining the buzzer                    
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  char data;
//  if(bt_com.available()>0)
//  {
//        data=bt_com.read();
//                
//          if(data=='a')     //If you will type 'a'
//          {
//          tone(buzzer,1000, 500);//make a sound
//          delay(20);
//          noTone(buzzer);
//       }
//     
//       
////       if (data=='b'){//If you will type 'b',
////        tone(buzzer,100);//Make a sound
////        delay(20);
////        noTone(buzzer);
////        delay(20);
////       }
////       if(data=='c'){//if you will type c
////        tone(buzzer,90);//Make a sound
////        delay(20);
////        noTone(buzzer);
////        delay(20);
////       }
////       if (data=='d'){
////        tone(buzzer,35);
////        delay(20);
////        noTone(buzzer);
////        delay(20);
////       }
////       if(data=='e'){
////        tone(buzzer,10);
////        delay(20);
////        noTone(buzzer);
////        delay(20);
////       }
//     }
//}
