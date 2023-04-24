#ifndef SWITCH_H
#define SWITCH_H
#include <Arduino.h>

class SWITCH{
    public:
        SWITCH(int pin);
        int isON();

    private:
        int _pin;
};

#endif