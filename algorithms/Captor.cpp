
#include "Parameters.h"
#include "Captor.h"
#include "RangeFinder.h"

Captor::Captor():
    DELTA(200), DELTATEMPS(0.4), UP(0), DOWN(1), LEFTUP(0), LEFTDOWN(1), RIGHTUP(1), RIGHTDOWN(0), distance(0),
    iSeeYou(false), warning(false), dirRight(RIGHTUP), dirLeft(LEFTUP), blink(DOWN) {

}

boolean Captor::detect() {
    if (blink==UP) {blink=DOWN;} else {blink=UP;}
    distance=ranger.read_m();

    wait(.1);
    if (distance<0.001 || distance>2.0) { distance=0; }

    warning=false;
    iSeeYou=false;
    if (distance>0.15 && distance<0.5) {
        iSeeYou=true;
    }
    if (distance>0.01 && distance<=0.15) {
        warning=true;
    }

    if (iSeeYou) {
        greenled=UP;
        redled=DOWN;
        dirRight=RIGHTUP;
        dirLeft=LEFTUP;
        pwmRight.pulsewidth_us(400);
        pwmLeft.pulsewidth_us(400);
    }

    if (warning) {
        greenled=DOWN;
        redled=blink;
        dirRight=RIGHTDOWN;
        dirLeft=LEFTDOWN;
        pwmRight.pulsewidth_us(0);
        pwmLeft.pulsewidth_us(0);
        wait(1);
        int random = std::rand()%3;
        if (random==0) {
            pwmRight.pulsewidth_us(400);
            pwmLeft.pulsewidth_us(200);
        } else {
            if (random==1) {
                pwmRight.pulsewidth_us(200);
                pwmLeft.pulsewidth_us(400);
            } else {
                pwmRight.pulsewidth_us(300);
                pwmLeft.pulsewidth_us(300);
            }
        }
        wait(1);
    }

    if (!iSeeYou && !warning) {
        greenled=DOWN;
        redled=DOWN;
        pwmRight.pulsewidth_us(0);
        pwmLeft.pulsewidth_us(0);
    }
    wait(DELTATEMPS);

    return iSeeYou;
}