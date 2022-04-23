#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 float Celcius=0;
 float Fahrenheit=0;
 const int Relay_pin = A5;
 int start = 0;
 int ledPin = 7;
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(ledPin, OUTPUT);
}
void loop(void)
{
  sensors.requestTemperatures();
  delay(250);
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  
  if(Celcius >= 75){
    digitalWrite(ledPin, HIGH);
    delay(6000)
    // digitalWrite(Relay_pin, HIGH);
    // delay(6000);
    // digitalWrite(Relay_pin, LOW);
    //exit(0);
  }
  }
