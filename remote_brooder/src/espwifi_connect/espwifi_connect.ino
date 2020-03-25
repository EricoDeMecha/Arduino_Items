/**
 * Uncomment this if you have got a working ESP8266WiFi.h header file in your dirs
#include "src/ESP8266WiFi.h"
**/

#include <ESP8266WiFi.h>

const char* ssid = "WifiName";// replace with your own
const char* password= "wifi_password";//replace with your own

void setup()
{
  Serial.begin(115200); // rate recommended for the AT commands. Read below in READEME

  // connect to WiFi
  WiFi.begin(ssid,password);
  Serial.print("Connecting...");
  while(WiFi.status() != WL_CONNECTED )
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Device Connected to WiFi");
  // just incase you need the local IP
  Serial.print("Device IP: ");
  Serial.print(WiFi.localIP());
  Serial.println();
}
void loop()
{
  // do your stuff
}
