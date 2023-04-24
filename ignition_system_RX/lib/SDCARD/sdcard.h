#ifndef SDCARD_H
#define SDCARD_H
#include <SPI.h>
#include <SD.h>
#include <Arduino.h>

class SDCARD{
    public:
        SDCARD(int chipSelect);
        void write(float text);
    private:
        File myFile;
        int CS;
};


#endif