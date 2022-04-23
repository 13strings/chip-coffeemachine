#include <Servo.h>
Servo servo;
int eastLDRPin = A1;
int westLDRPin = A2;
int eastLDR = 0;
int westLDR = 0;
int difference = 0;
int error = 10;
int servoPos = 130;
void setup() {
 servo.attach(10);
 Serial.begin(9600);
}
void loop() {
 eastLDR = analogRead(eastLDRPin);
 westLDR = analogRead(westLDRPin);
 if (eastLDR < 400 && westLDR < 400) {
   while (servoPos <=140 && servoPos >=15) {
     servoPos ++;
     servo.write(servoPos);
     delay(100);
   }
 }
 difference = eastLDR - westLDR ;
 if (difference > 10) {
   if (servoPos <= 140) {
     servoPos ++;
     servo.write(servoPos);
   }
 } else if (difference < -10) {
   if (servoPos >= 15) {
     servoPos --;
     servo.write(servoPos);
   }
 }
 Serial.print(eastLDR);      //Serial monitor can be useful for debugging/setting up
 Serial.print("   -   ");    //Use it to see if your LDR’s are noticeably different when
 Serial.print(westLDR);      //They have equal light shining on them, if so, correct with the error value
 Serial.print("   -   ");
 Serial.print(difference);
 Serial.print("   -   ");
 Serial.print(servoPos);     //Fine tune the servo settings, to maximise swing available
 Serial.print("   -   ");
 Serial.println("   -   ");
 delay(100);}
