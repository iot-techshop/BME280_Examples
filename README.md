# BME280_Examples
Customized BME280 Examples

by Bill Poulsen
bill.iottechshop@gmail.com

www.iot-techshop.com

Join our FB group at https://www.facebook.com/groups/3188341227932417/


BME280

The BME280 environmental sensor is an amazing device.
It accurately measures Temperature, Humidity, and Atmospheric pressure and sends that data to a microcontroller  via the I2C or SPI bus.
The current consumption is a tiny 3.6uA when reporting every second with all three sensor parameters turned on.  Sleep mode is miniscule, at  .1uA, making this an ideal choice for battery operated or small solar powered IoT devices.
Reading accuracy is decent.
Relative Humidity: +/- 3%
Temperature: +/- 1 deg C from 0 to 60C, +/- 1.25 deg C from -20 to 0 deg C, +/- 1.5 deg C from -40 to -20 deg C
Atm Pressure: +/- 1.7 hPa

Arduino Libraries:  Install Both
adafruit bme280
Adafruit Unified Sensor

Sample Tutorials
ESP32 with BME280 using Arduino IDE (Pressure, Temperature, Humidity) | Random Nerd Tutorials
https://youtu.be/O8FgrHR2laM

What can you do with this sensor??
Predictive Weather Station:
Using the data from this device you can create a weather monitoring and prediction application.  With temperature and humidity you can calculate dew point.  Using the pressure readings you can monitor trends in pressure changes; dropping pressures usually indicate a storm is likely in the near future. Rising pressure indicates clear weather ahead.  Doing a bit of research you can piece together humidity, temperature, and pressure trends to predict weather for the next 24 hours fairly accurately.  Studying the data for your specific area and looking for some local trend patterns in the data can even help you create a highly accurate model for your location.


Example 1:
Reads BME Sensors and reports over serial port.
Temp, Humidity, Pressure and Alt based on local sea level pressure.
A button is included to allow Zeroing out of ALtitude to measure height above a surface mlore accurately.
Cal should be run every so often to offset for any sea level pressure changes.

Eaxample 2:
