#include <Arduino.h>
#include "smarthome\SmartHome.h"
#include <SoftwareSerial.h>


SmartHome home = SmartHome();


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello 1");

  home.init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Hello 2");
  home.run();
}
