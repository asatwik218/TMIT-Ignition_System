#include "led.h"
#include <Arduino.h>

LED::LED(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void LED::on()
{
    digitalWrite(_pin, HIGH);
    state = 1;
}

void LED::off()
{
    digitalWrite(_pin, LOW);
    state = 0;
}

bool LED::getState(){
    return state;
}