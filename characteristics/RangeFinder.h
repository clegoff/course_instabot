#define MBED_RANGEFINDER_H

#include "../Pulse.h"

/** Range Finder class
 */

class RangeFinder   {
public:

    RangeFinder(PinName pin, int pulsetime, float scale, int timeout);
    ~RangeFinder();
    /** Return the distance to the nearest object, or -1.0 if reading the pulse timed out.
     */
    float read_m();
private:
    PulseInOut pio;
    float scale;
    int pulsetime, timeout;
};


