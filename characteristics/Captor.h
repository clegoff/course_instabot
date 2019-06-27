#define MBED_RANGEFINDER_H

#include "RangeFinder.h"
#include "mbed.h"

class Captor {
public:
    Captor();
    boolean detect();
private:
    float DELTA;
    float DELTATEMPS;
    int UP;
    int DOWN;
    int LEFTUP;
    int LEFTDOWN;
    int RIGHTUP;
    int RIGHTDOWN;

    float distance;
    bool iSeeYou;
    bool warning;

    int dirRight;
    int dirLeft;
    int blink;

    RangeFinder ranger(D3, 10, 5800.0, 100000);
};