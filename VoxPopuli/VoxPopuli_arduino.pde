#include "Wire.h"
#include "SRF02.h"

SRF02 srf02[8] =
{
  SRF02(0x70, SRF02_CENTIMETERS),
  SRF02(0x71, SRF02_CENTIMETERS),
  SRF02(0x72, SRF02_CENTIMETERS),
  SRF02(0x73, SRF02_CENTIMETERS),
  SRF02(0x74, SRF02_CENTIMETERS),
  SRF02(0x75, SRF02_CENTIMETERS),
  SRF02(0x76, SRF02_CENTIMETERS),
  SRF02(0x77, SRF02_CENTIMETERS)
};

unsigned long previousMillis = 0;        // will store last time sensors were updated
unsigned long interval = 70;

//anzahl der sensoren
#define sensors 8

int distance = 0;
int distance2 = 0;
int x = 0;
int y = 2;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  SRF02::setInterval(interval);
}

void loop()
{
  SRF02::update();
  if (millis() - previousMillis > interval)
  {
    previousMillis = millis();
      distance = srf02[x].read();
      distance2 = srf02[y].read();
      //Serial.print(x);
      //Serial.print(": ");
      /*Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.println(y);*/
      if(distance == 0) {
        Serial.println(700);
      }
      else {
        Serial.println(distance);
      }
      if(distance2 == 0) {
        Serial.println(700);
      }
      else {
        Serial.println(distance2);
      }
  x++;
  y++;
   if(y == 8) {
  y = 0;
}   
  if(x == 8) {
  x = 0;
}  
}
}
