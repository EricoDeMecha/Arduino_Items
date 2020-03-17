#include <SoftwareSerial.h>// for the ESP8266
#define DEBUG true// allow for simple arduino debugging(printing)

SoftwareSerial esp8266(11,12);

#include <LiquidCrystal.h>//for LCD
LiquidCrystal lcd(9,8,4,5,6,7);// LCD connected pins

#define SSID "Erico"// wifi name
#define PASS "Erico4134"// wifi password

#include "src/DHT.h"
DHT dht(2 , DHT11); // object of the module class
/*******End of header files*********/

float temp = 0; // temp
float humidity = 0; // humidity
float heat_index = 0; // heat index
boolean flag = false;
// esp8266 connecting Wifi
boolean connectWifi()
{
  Serial.println("AT+CWMODE=1");
  esp8266.println("AT+CWMODE=1");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd +="\",\"";
  cmd +=PASS;
  cmd+="\"";
  Serial.println(cmd);
  esp8266.println(cmd);
  delay(5000);
  if (esp8266.find("OK"))
  {
    Serial.println("OK");
    return true;
  }
  else
  {
    return false;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin(); // initializes the module
  lcd.begin(16,2);

  lcd.print("Connecting...");
  esp8266.begin(9600);// initialize the ESP module
  Serial.println("AT");
  esp8266.println("AT");
  delay(5000);
  if(esp8266.find("OK"))
  {
    if(connectWifi())
    {
      flag = true;
    }
    else
    {
      flag = false;
    }
  }
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);// for the temp and humid readings
  temp = dht.readTemperature();
  humidity = dht.readHumidity();
  heat_index = dht.computeHeatIndex(temp ,humidity, false);
  // DHT 11 display
  lcd.setCursor(0,0);
  lcd.print("Temp:");// 5 chars (pos 4)
  lcd.setCursor(5,0);
  lcd.print(temp);
  lcd.setCursor(7,0);
  lcd.print((char) 223);
  lcd.setCursor(8,0);
  lcd.print("C ");

  lcd.setCursor(10,0);
  lcd.print("H.I:");// 4 chars
  lcd.setCursor(14,0);
  lcd.print(heat_index);
  
  lcd.setCursor(0,1);
  lcd.print("Hum.:");// 5 chars (pos 4)
  lcd.setCursor(5,1);
  lcd.print(humidity);
  lcd.setCursor(7,1);
  lcd.print("% ");

  // connected display
  lcd.setCursor(9,1);
  lcd.print("Con:");// 4 chars
  lcd.setCursor(13,1);
  if(flag)
  {
   lcd.print('Y'); 
  }
  else
  {
    lcd.print('N');
  }
}
