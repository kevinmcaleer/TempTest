
#define aref_voltage 3.3

// BUG - temperature is reading 279.68 degrees C which is obviously wrong

int lightSensorPin = A0;
int tempSensorPin = A1; // select the input pin for the thermometer
int temperature = 0;
float temperatureC = 0.0;
int light = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
 // If you want to set the aref to something other than 5v
  analogReference(EXTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:

// read the value from the sensor
temperature = analogRead(tempSensorPin);
light = analogRead(lightSensorPin);
float voltage = temperature * aref_voltage;
voltage /=1024.0;
temperatureC = (voltage - 0.5) * 100;
 delay(1000);
 Serial.print("temp: ");
 Serial.print(temperature);
 Serial.print(", temperature Degrees C: ");
 Serial.print(temperatureC);
 Serial.print(", light level: ");
 Serial.println(light);
}
