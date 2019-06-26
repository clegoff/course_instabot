
#include "Parameters.h"
#include "Captor.h"
#include "RangeFinder.h"

#define DELTA 200
#define DELTATEMPS 0.4

#define UP 0
#define DOWN 1

#define LEFTUP 0
#define LEFTDOWN 1
#define RIGHTUP 1
#define RIGHTDOWN 0

PwmOut redled(D2);
PwmOut greenled(D12);
RangeFinder ranger(D3, 10, 5800.0, 100000);

PwmOut pwmRight(D10);
DigitalOut dirRight(D8);
PwmOut pwmLeft(D9);
DigitalOut dirLeft(D7);

float distance=0;
bool iSeeYou=false;
bool warning=false;

pwmRight.period_us(1000);
pwmLeft.period_us(1000);
dirRight=RIGHTUP;
dirLeft=LEFTUP;
pwmRight.pulsewidth_us(0);
pwmLeft.pulsewidth_us(0);

wait(1);

greenled=UP;redled=UP;
wait(.5);
greenled=DOWN;redled=DOWN;
wait(.5);
greenled=UP;redled=UP;
wait(.5);
greenled=DOWN;redled=DOWN;
wait(.5);
greenled=UP;redled=UP;
wait(.5);
greenled=DOWN;redled=DOWN;
wait(2);

float distance=0;
int blink=DOWN;

void Captor::detect() {
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
}
}