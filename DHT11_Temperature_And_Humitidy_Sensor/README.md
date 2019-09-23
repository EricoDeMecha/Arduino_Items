# Adafruit DHT Humidity & Temperature Sensor Library [![Build Status](https://travis-ci.com/adafruit/DHT-sensor-library.svg?branch=master)](https://travis-ci.com/adafruit/DHT-sensor-library)

An Arduino library for the DHT series of low cost temperature/humidity sensors.

Tutorial: https://learn.adafruit.com/dht

**You must have the following Arduino libraries installed to use this class:**

- [Adafruit Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor)

Examples include both a "standalone" DHT example, and one that works along with the Adafruit Unified Sensor Library. Unified sensor library is required even if using the standalone version.

Recent Arduino IDE releases include the Library Manager for easy installation. Otherwise, to download, click the DOWNLOADS button in the top right corner, rename the uncompressed folder DHT. Check that the DHT folder contains DHT.cpp and DHT.h. Place the DHT library folder your
<arduinoInstallationsDirectory>/libraries/ 

Open all the files using your favorite editor and  edit the included header
files  as follows  __#include<<filename>>__  change to
__#include"<filename>"__.

Add Adafruit_Sensor header file to the same directory as this library using
the format specified above. Re-compile your project. 

