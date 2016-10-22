/*
SparkFun Tinker Kit 
Example sketch 01

BLINKING AN LED

Turn an LED on for one second, off for one second,
and repeat forever.

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about Arduino.
*/



//The setup function runs once upon your Arduino being powered or once upload is          //complete.

void setup()
{
  //set pin 13 to OUTPUT 
  pinMode(13, OUTPUT);
}

//The loop function runs from the top down and repeats itself until you upload new        //code or power down your Arduino
void loop()
{
  //Turn pin 13 HIGH (ON). 
  digitalWrite(13, HIGH);   

  //wait 1000 milliseconds (1 second)
  delay(1000);              

  //Turn pin 13, LOW (OFF)
  digitalWrite(13, LOW);    

  //wait 1000 milliseconds
  delay(1000);              
}

