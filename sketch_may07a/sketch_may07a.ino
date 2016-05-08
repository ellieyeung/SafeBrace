#include <SerialLCD.h>
#include <SoftwareSerial.h> //this is a must 
#include "CurieTimerOne.h"

int buttonPin1 = 2;
int buttonPin2 = 3;
int touchsensorPin = 4;
int soundPin = 5;
int LEDPin = 6;
SerialLCD slcd(11,12);//this is a must, assign soft serial pins
unsigned int button1PressedTimer = 0;
unsigned int button2PressedTimer = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(touchsensorPin,INPUT);
  pinMode(soundPin,INPUT);
  pinMode(LEDPin,OUTPUT);
  //slcd.begin();// set up
  //slcd.backlight();// Turn on the backlight
}

void loop() {
  if(digitalRead(buttonPin1) && (button1PressedTimer == 0))//check button is pressed or not
  {
    //slcd.setCursor(0,0); // set the cursor to (0,0):
    //slcd.print(" 911 contacted"); // Print a message to the LCD.
    while(digitalRead(buttonPin1))
    {
      if(digitalRead(buttonPin2) && (button2PressedTimer == 0)) //check button is pressed or not
      {
        while(digitalRead(buttonPin2)){}
        Serial.println("Emergency contact contacted");
        button2PressedTimer = 10000000;
      }
    }
    Serial.println("911 contacted");
    button1PressedTimer--;
  }
  if(digitalRead(buttonPin2) && (button2PressedTimer == 0))//check button is pressed or not
  {
    while(digitalRead(buttonPin2))
    {
      if(digitalRead(buttonPin1) && (button1PressedTimer == 0)) //check button is pressed or not
      {
        while(digitalRead(buttonPin1)){}
        Serial.println("911 contacted");
        button1PressedTimer--;
      }
    }
    Serial.println("Emergency contact contacted");
    button2PressedTimer = 10000000;
  }
  if (button1PressedTimer != 0)
    button1PressedTimer--;
  if (button2PressedTimer != 0)
    button2PressedTimer--;
}
