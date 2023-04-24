#include <Arduino.h>
#include "led.h"
#include "nrf.h"
#include "lchx711.h"
#include "sdcard.h"
#include <string.h>

NRF nrf(7, 8); // ce,csn

SDCARD sdc(10); // chip select

LED fireMOSFET(5);
LED buzzerPIN(6);

LCHX711 loadCell(2,3,-1777);//(dout, sck, calibration factor) 

char text[10];

void setup()
{
}

void loop()
{

  strcpy(text, nrf.read());
  if (strcmp(text, "ARM"))
  {
    buzzerPIN.on();
  }
  else if (strcmp(text, "FIRE") && buzzerPIN.getState())
  {
    fireMOSFET.on();
    delay(20);
    fireMOSFET.off();
  }
  else if (strcmp(text, "SAFE"))
  {
    buzzerPIN.off();
  }

  float loadCellVal = loadCell.getValue();
  sdc.write(loadCellVal);


}