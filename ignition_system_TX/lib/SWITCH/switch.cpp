#include "switch.h"


SWITCH::SWITCH(int pin){
    pinMode(pin, INPUT);
    _pin = pin; 
}

int SWITCH::isON(){
    return digitalRead(_pin);
}