#include <LiquidCrystal.h>

const int tempSensorPin = A0;
const int lightSensorPin = A1;
const int moistureSensorPin = A2;

float tempSensorValue;
float voltageOut;
int lightValue;
float moistureSensorValue;

float temperatureF;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  pinMode(tempSensorPin, INPUT);
  Serial.println("Water System Start"); 

  Serial.begin(9600);
  lcd.begin(16, 2);      
}
void loop() {
  // Sensor Value
  tempSensorValue = analogRead(tempSensorPin);    //Read the analog pin
  voltageOut = (tempSensorValue * 5000) / 1024;
  temperatureF = voltageOut / 10;

  // Photoresistor Value
  lightValue = analogRead(lightSensorPin);

  // Moisture Sensor Value
   for (int i = 0; i <= 100; i++) 
   { 
     moistureSensorValue = moistureSensorValue + analogRead(moistureSensorPin); 
     delay(1); 
   } 
   moistureSensorValue = moistureSensorValue/100.0; 
   Serial.print("Moisture: "); // prints on serial monitor
   Serial.println(moistureSensorValue); 
   lcd.print("Moisture: "); // prints on lcd 
   lcd.println(moistureSensorValue); 

   // Print Data
   Serial.print("Temperature: ");
   Serial.print(temperatureF);
   Serial.println("F");  //print the temperature status
   lcd.print("Temperature: ");
   lcd.print(temperatureF);
   lcd.println("F");  

   lcd.clear(); 
 
   Serial.print("Light Value: ");
   Serial.println(lightValue);
   lcd.print("Light Value: ");
   lcd.println(lightValue);

   lcd.clear(); 
  
  
   delay(1000);
    
}
