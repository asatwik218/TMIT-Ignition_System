#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED{
    public:
        LED(int puin);
        void on();
        void off();
        bool getState();

    private:
        int _pin;
        bool state;
};


#endif