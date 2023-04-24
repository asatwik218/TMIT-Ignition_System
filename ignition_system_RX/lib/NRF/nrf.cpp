#include "Arduino.h"
#include "nrf.h"

NRF::NRF(int CE, int CSN)
{
    radio = RF24(CE, CSN); // CE, CSN
    const byte address[6] = "00001";
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
}

void NRF::write(char *text)
{
    radio.stopListening();
    radio.write(&text, sizeof(text));
    delay(1000);
}

char *NRF::read()
{
    radio.startListening();
    if (radio.available())
    {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        return text;
    }
}
