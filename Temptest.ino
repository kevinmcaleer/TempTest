
// Author Kevin McAleer
// 20 June 2016 - inital version
// 26 June 2016 - removed temp calculaation bug

// Only include below if its running off 3.3volts - its supposed to give a more accurate reading of tempature, but I didnt find that
//
#define aref_voltage 3.3
// set above to be 5.0 if 5 volts
// 
// Need to add code to write out lines via UART port Digital Pins 0 and 1 (RX, TX)
//
// Greenhouse robot takes commands from UART serial
// then replies back with results of command.
// Commands:
//    Temp
//    Light
//    Door
//    Window
//    version
//    

// BUG doesn't compile writeln and readln not valid comnands for UART
// Fixed. Now displays version information on bootup.

// include the SPI Library:
#include "SPI.h"


int lightSensorPin = A0;
int tempSensorPin = A1; // select the input pin for the thermometer
int temperature = 0;
float temperatureC = 0.0;
int light = 0;
int ledPin = 13;
int ledState = false;
String command = "";

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600); 
  // If you want to set the aref to something other than 5v
  //analogReference(EXTERNAL);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  delay(1000);
  Serial.println("GreenHouse Robot, Version 0.01");
  SPI.begin();
  pinMode(ledPin,OUTPUT);
}


void toggleLed()
{
  if(ledState == false)
  {
    ledState = true;
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    ledState = false;
    digitalWrite(ledPin, LOW);
  }   
}

void readCommand()
{
  //command = Serial.read();  
  // command = "";
  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      if (c == '\n') 
      {
        Serial.print("Arduino received: ");
        Serial.print(command);
        command = "";
      }
      Serial.write(c);
      toggleLed();
      command += c; //makes the string readString
    } 
  }
}

void temp()
{
  Serial.print("temperature: ");
  Serial.println(temperatureC);  

  //SPI.write(", light level: ");
  //SPI.write(light);
  //Serial.print("temp: ");
  //Serial.print(temperature);
  //Serial.print(", temperature Degrees C: ");
  //Serial.print(temperatureC);
  //Serial.print(", light level: ");
  //Serial.println(light);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the value from the sensor
  
  temperature = analogRead(tempSensorPin);
  light = analogRead(lightSensorPin);
  float voltage = temperature * aref_voltage; // use aref_voltage if 3.3 volts
  voltage /=1024.0;
  temperatureC = (voltage - 0.5) * 100;

  toggleLed();
  // loop read command
  readCommand();
  char cmd  = 'n';
  if (command = "temp") cmd = 't'; 
  if (command = "light") cmd = 'l';
  
  switch (cmd) {
    case 't':
    // do something with temperature
    break;
    case 'l':
    // do something with light
    break;
    default:
    // do something if command not recognised
    Serial.println("command not recognised");
    break;
    }
  
  //SPI.write("temp: ");
  //SPI.write(temperature);
  
}
