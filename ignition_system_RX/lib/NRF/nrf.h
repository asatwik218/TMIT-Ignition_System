#ifndef NRF_H
#define NRF_H
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <String.h>

class NRF
{
public:
    NRF(int CE, int CSN);
    void write(char *text);
    char *read();

private:
    RF24 radio;
};

#endif
