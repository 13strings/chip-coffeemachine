
// code guide by https://create.arduino.cc/projecthub/pibots555/how-to-connect-dht11-sensor-with-arduino-uno-f4d239

#include "DHT.h"

#define DHTPIN 2 // the pin that the DHT sensor is connected to
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature testing");

  dht.begin();
}

void loop() {
  delay(2000);
float temperature = dht.readTemperature(); // will return in Celcius

if (isnan(temperature){
  temperature = 0.0;
}

temp_string = std::to_string(temperature);
Serial.print(temp_string + " Celcius");
}
