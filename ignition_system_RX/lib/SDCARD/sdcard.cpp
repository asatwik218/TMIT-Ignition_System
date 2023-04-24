#include <Arduino.h>
#include "sdcard.h"

SDCARD::SDCARD(int chipSelect)
{
    CS = chipSelect;
    Serial.print("Initializing SD card...");

    if (!SD.begin(CS))
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
}

void SDCARD::write(float text){

  myFile = SD.open("dataLog.txt", FILE_WRITE);

  if (myFile) {
    myFile.println(text);
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }

}