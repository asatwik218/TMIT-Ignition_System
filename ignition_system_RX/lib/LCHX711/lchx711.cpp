
#include "lchx711.h"

LCHX711::LCHX711(int d, int s, int cf)
{
    dout = d;
    sck = s;
    calibrationFactor = cf;
    scale.begin(dout, sck);
    scale.set_scale(calibrationFactor);
    scale.tare(); // Assuming there is no weight on the scale at start up, reset the scale to 0
}

float LCHX711::getValue()
{
    if (scale.is_ready())
    {
        float reading = scale.get_units(5);
        return reading;
    }
    return 0.0;
}