# Remotely Controlled Chicken Brooder
This project involve monitoring a chicken brooder through a web applications interface
## Basic of ESP8266-01
### Operation modes of ESP8266-01
1.__Station Mode(STA)__
In  station mode the module will be connected to a WIFI network that is already setup by an Access Point like a WIFI router.
2.__Soft AccesPoint(AP)__
In this mode the module acts as an accesspoint and provide WIFI network to other devices. But then the only means of connection is wireless therefore the name 'Soft'
3.__Soft AP and Station__
In this mode, the module acts as both an access point and can also connect to any wireless access point available.
_All this modes are set using AT commands send from arduino_
### Flashing firmware to ESP8266-01
* Find a firmware flashing firmware.
* Find a ESP8266 firmware files.
[AT firmware](https://drive.google.com/open?id=19Ur1cryN11c9mpoOcBVEp_VYyagoK1P2)
[git espressif](https://github.com/espressif/ESP8266_AT)
[google drive1](https://drive.google.com/file/d/0B3dUKfqzZnlwdUJUc2hkZDUyVjA/view)
[google drive2](https://drive.google.com/open?id=1c0zO8dbw5pIAc0lDYAg0cBx-PXFS_iTg)
* Connect ESP8266-01 in flashing mode
Connected ESP8266-01:
![Image not loaded](<link> "ESP connection 1")
__Connecting  the GPIO0 pin to the ground puts the module into flashing mode__
* Upload the firmware

### Connecting  ESP8266-01 to wifi using the serial command window
* Fire up Arduino IDE with the circuit connected as show above
* Open up the serial monitor and set the Baud rate to 115200 and then select the option    "Both NL and CR"
* Type in __AT__ to test if the communication is successful.
* Restart the module using the following command __AT+RST__
* Set the mode of operation to station mode __AT+CWMODE=1__
* See the list of all nearby WiFi networks __AT+CWLAP__
* Join a network using the followinng command __AT+CWJAP="SSID","PASSWORD"
* Check the ip address of your ESP8266-01 module __AT+CIFSR__

### Connecting ESP8266-01 to wifi using an arduino program
[sketch](<#>)
