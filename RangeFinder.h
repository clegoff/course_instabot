#define MBED_RANGEFINDER_H

#include "Pulse.h"

/** Range Finder class
 */

class RangeFinder   {
  public:
    /** Create a RangeFinder object
     * @param pin Digital I/O pin the range finder is connected to.
     * @param pulsetime Time of pulse to send to the rangefinder to trigger a measurement, in microseconds.
     * @param scale Scaling of the range finder's output pulse from microseconds to metres.
     * @param timeout Time to wait for a pulse from the range finder before giving up.
     */
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


