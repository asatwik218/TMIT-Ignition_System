#ifndef LCHX711_H
#define LCHX711_H

#include <Arduino.h>
#include <HX711.h>

class LCHX711{
    public:
        LCHX711(int d, int s, int cf);
        float getValue();
        

    private:
       int dout;
       int sck;
       int calibrationFactor;
       HX711 scale;
};


#endif