
/*
 * Arduino Weather Station / Estacion Meteorologica con Arduino
 * 
 * Sensors: Schematics and How to Read Values
 * C-Innova, Bogota, Colombia
 * January 23, 2017
 * 
 * contact: jugarciasa@unal.edu.co (Juliana Garcia)
 * 
 */

 /*
  * Arduino Breadboard Schematic and Value Readings:
  * 
  * 
  * Temperature/Humidity Sensor:
  *   temperature: degrees Celcius
  *   humidity: 0-100%
  *   Dat (sensor) to D2 (arduino)
  * 
  * Rain Drop Sensor:
  *   1023: dry
  *   0: wet
  *   A0 (sensor) to A1 (arduino)
  *   
  * Soil Sensor:
  *   1023: dry
  *   0: wet
  *   D0 (sensor) to D11 (arduino)
  *   A0 (sensor) to A0 (arduino)
  *   
  * LCD Screen:
  *   SDA (sensor) to SDA (arduino) (left)
  *   SCL (sensor) to SCL (arduino) (right)
  * 
  */
 
 //-------------LCD------------------
#include <I2CIO.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <MyLCD.h>
#include <dht.h>                // library for temp and humidity sensor

//----- Sensor Libraries -------
#include <SoilHumidity.h>
#include <RainDrop.h>
#include <Temperature.h>
// ----- Creates the objects of each type of sensor
MyLCD mylcd;
SoilHumidity soilhumidity(A0); // set up humidity reader at pin A0
RainDrop raindrop(A1);         // set up RainDrop reader at pin A1
Temperature temperature(2); // set up temperature reader at pin 2
Temperature humedad(2);
//Humedad humedad(2); // set up air humidity reader at pin 2

// -----------------------------------

// #include <dht.h>                // library for temp and humidity sensor
// dht DHT;                        // define constant DHT
#define DHT11_PIN 2             // temp and humidity sensor to digital pin 2

void setup() {
  Serial.begin(9600);
  mylcd.init(); // set LCD to 16x2 screen, and set backlight
  delay(1000);
}

int wait = 1000;

void loop() {
// ---- Print sensors data in the LCD -----
   mylcd.printData(soilhumidity.getFormattedData());  
   delay(wait);
  
   mylcd.printData( raindrop.getFormattedData() );  
   delay(wait);
  
   mylcd.printData( temperature.getFormattedData() );  
   delay(wait);
  
   mylcd.printData(  humedad.getFormattedData2() );  
   delay(wait);
  
 /*
  ------------------------------------------
  -------- Show data in Serial monitor------
  ------------------------------------------
  */
  
  // Rain Sensor
  Serial.print("Rain Sensor: ");
  Serial.println(raindrop.getRawData());           // print rain sensor data from analog pin 1
  delay(wait);
   
  // DHT11 Sensor 
  // Air temperature
  Serial.print("Temperatura: ");
  Serial.println(temperature.getRawData());          // print temperature data
  delay(wait);
  // Air humidity
  Serial.print("Humedad: ");
  Serial.println(humedad.getRawData2());             // print humidity data
  delay(wait);
  // Soil Sensor
  Serial.print("Soil Sensor: ");
  Serial.println(soilhumidity.getRawData());           // print soil humidity sensor data from analog pin 0 
  Serial.println("");

  delay(wait);

}
