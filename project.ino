#include <LiquidCrystal.h>
// Pin constants
const int tempSensorPin = A0;
const int lightSensorPin = A1;
const int moistureSensorPin = A2;
const int motorPin = 9;

// Moisture Sensor constants
const int AirValue = 444;   // value when dry
const int WaterValue = 208; // value when wet

// Variables
float tempSensorValue;
float voltageOut;
int lightValue;
float temperatureF;
int soilMoistureValue = 0;
int soilmoisturepercent=0;

// Setup LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set pins as input/output
  pinMode(tempSensorPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(moistureSensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  // Begin LCD function
  lcd.begin(16, 2);
}

void loop() {
  // Read Sensor Value
  tempSensorValue = analogRead(tempSensorPin);    //Read the analog 
  // Convert to Farenheit
  voltageOut = (tempSensorValue * 5000) / 1024;
  temperatureF = voltageOut / 10;

  // Read Photoresistor Value
  lightValue = analogRead(lightSensorPin);

  // Read Moisture Value
  soilMoistureValue = analogRead(A2);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  // Set motor to off
  digitalWrite(motorPin, LOW);

  // Print moisture sensor values to row 0
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  if(soilmoisturepercent >= 100)
  {
    lcd.print("100 %");
  }
  else if(soilmoisturepercent <=0)
  {
    lcd.print("0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    lcd.print(soilmoisturepercent);
    lcd.print("%");
    lcd.print("  ");
    
  }
  
  // Print Temp and Light values to LCD row 1
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatureF);
  lcd.print("F");
  lcd.print(" L:");
  lcd.print(lightValue);
  lcd.print(" ");
  
  // Update every 1000 ms
  delay(1000);
}
