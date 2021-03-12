/*********
  BME 280 TEST with Height/Altitude Zero function
  by Bill Poulsen
  03/12/21

  Visit our website www.iot-techshop.com
  Join our Facebook Group  https://www.facebook.com/groups/3188341227932417/
Code written for ESP32

This code reads the Temp/Humid/Atm Pressure and Calculates Altitude/Height 
based on Pressure. Initial altitude is based on using an estimate of Atm pressure 
at your current sea level. See altCalFactor.

To measure height above a known surface point(ground level), place sensor at ground level
and press and hold Zero Cal Btn for a few seconds.  All altitude readings after that will
be referenced to that point.  You can reset to a new level at any time by pressing button again.



  
*********/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define btnCal 13 //Pin for Zero Cal Button


Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;
 bool status;
  bool calBtnState=HIGH;
float pressure= 0.0;
float altCalFactor=1013.25;//initialize at estimated sea level pressure
  
void setup() {
  Serial.begin(115200);
  Serial.println(F("BME280 test")); 
  pinMode(btnCal, INPUT_PULLUP);  
  status = bme.begin(0x76);  // Set to BME280 I2C address
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
   while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 1000; // time in mS between readings

  Serial.println();
}


void loop() { 
  printValues();
  delay(delayTime);
  Serial.println(digitalRead(btnCal));
  if(digitalRead(btnCal) == LOW){
    calAlt();
  }
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  // Convert temperature to Fahrenheit
  /*Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");*/
  
  Serial.print("Pressure = ");
  pressure = (bme.readPressure() / 100.0F);
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(altCalFactor));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}

// If Cal Zero button pressed gets new zero height pressure value
void calAlt(){
altCalFactor = pressure;

  
}
