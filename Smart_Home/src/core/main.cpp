#include <Arduino.h>
#include "smarthome\SmartHome.h"

SmartHome home = SmartHome();


void setup()
{
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  home.init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  home.run();
}
