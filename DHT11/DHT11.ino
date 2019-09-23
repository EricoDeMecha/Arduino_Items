#include <DHT.h>

#define DHTPIN 2 //the digital pin  connected to the sensor

#define DHTTYPE DHT11 //the sensor type

DHT dht(DHTPIN, DHTTYPE); //initialize the sensor

void setup()
{
  Serial.begin(9600);
  Serial.println(F("DHTXX test"));
  dht.begin();
}

void loop()
{
  delay(2000);//wait for 2 seconds before the sensor starts  to operate
  float h = dht.readHumidity();
  float t = dht.readTemperature();//in celsius the default
  float f = dht.readTemperature(true);//set isFarenHeit = true 
  //check if any reads failed  and exit if any
  if(isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println(F("Failed to take the data"));
    return;
  }
  //compute heat index (FarenHeit= default)
  float hif = dht.computeHeatIndex(f,h);
  //compute head index  in celsius ( isFarenHeit = false)
  float hic = dht.computeHeatIndex(f,h,false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("*C  "));
  Serial.print(f);
  Serial.print(F("*F Heat Index: "));
  Serial.print(hic);
  Serial.print(F("*C"));
  Serial.print(hif);
  Serial.println(F("*F"));
}
