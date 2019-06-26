
#include "../characteristics/RangeFinder.h"

RangeFinder::RangeFinder(PinName pin, int pulsetime, float scale, int time):
        pio(pin), scale(scale), pulsetime(pulsetime), timeout(time)  {
}

RangeFinder::~RangeFinder() {
}

float RangeFinder::read_m()  {
    pio.write_us(1, pulsetime);
    float t = (float) pio.read_high_us(timeout);
    if (t == -1.0)   {
        return -1.0;
    }
    return t / scale;
}
