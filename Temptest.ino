
// Author Kevin McAleer
// 20 June 2016 - inital version
// 26 June 2016 - removed temp calculaation bug

// Only include below if its running off 3.3volts - its supposed to give a more accurate reading of tempature, but I didnt find that
//
// #define aref_voltage 3.3
// 
//

// include the SPI Library:
#include "SPI.h"

int lightSensorPin = A0;
int tempSensorPin = A1; // select the input pin for the thermometer
int temperature = 0;
float temperatureC = 0.0;
int light = 0;
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  
  //Serial.begin(9600); 
  // If you want to set the aref to something other than 5v
  //analogReference(EXTERNAL);
  //SPI.begin();
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the value from the sensor
  
  //temperature = analogRead(tempSensorPin);
  //light = analogRead(lightSensorPin);
  //float voltage = temperature * 5.0; // use aref_voltage if 3.3 volts
  //voltage /=1024.0;
  //temperatureC = (voltage - 0.5) * 100;
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
 
  //Serial.print("temp: ");
  //Serial.print(temperature);
  //Serial.print(", temperature Degrees C: ");
  //Serial.print(temperatureC);
  //Serial.print(", light level: ");
  //Serial.println(light);
}
