// setting up libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// variables/pins
 float Celcius=0;
 
 int start = 0;
 int ledPin = 7;
 int relay1Pin = 6;
 int buttonPin = 5;

 int relay2Pin = 4;
 

 int buttonState = 0;

 int timer = 0;
 
 
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(relay1Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(relay2Pin, OUTPUT);
}
void loop(void)
{
  sensors.requestTemperatures();
  delay(250);
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" C  ");
  Serial.print(Celcius);

 
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    while (timer < 50){
      digitalWrite(ledPin, HIGH); // turning on LED
      digitalWrite(relay1Pin, HIGH); // turning on heater
      delay(2400);
      timer ++;
      Celcius=sensors.getTempCByIndex(0);
      Serial.print(" C  ");
      Serial.print(Celcius);

    }
    digitalWrite(relay1Pin, LOW);
    digitalWrite(ledPin, LOW);
  
    digitalWrite(relay2Pin, HIGH);
    delay(7000);

    digitalWrite(relay2Pin, LOW); 
    
    // turn on pump
    
  }

}
 // https://tutorial.cytron.io/2012/08/01/identify-terminal-pins-of-a-relay-without-reference-to-datasheet-2/
