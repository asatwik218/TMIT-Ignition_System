#include <Arduino.h>
#include "nrf.h"
#include "led.h"
#include "switch.h"

NRF nrf(7, 8); // ce,csn

LED safetyLED(6);
LED armLED(10);
LED fireLED(2);

SWITCH armSWITCH(4);
SWITCH fireSWITCH(5);

char text[10];

void setup()
{
  Serial.begin(9600);
}
void loop()
{

  if (!armSWITCH.isON())
  {
    armLED.off();
  }
  else if (armSWITCH.isON() && !fireSWITCH.isON())
  {
    armLED.on();
  }

  if (fireSWITCH.isON() && armLED.getState())
  {
    fireLED.on();
  }
  else
  {
    fireLED.off();
  }

  if (armLED.getState() && fireLED.getState())
  {
    strcpy(text, "FIRE");
  }
  if (armLED.getState() && !fireLED.getState())
  {
    strcpy(text, "ARM");
  }
  else
  {
    strcpy(text, "SAFE");
  }
  nrf.write(text);
}