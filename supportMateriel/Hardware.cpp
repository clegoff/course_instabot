#include "Parameters.h"
#include "HMC5883L.h"
#include "MotorEncoder.h"
#include "Captor.h"

#define PWMGAUCHE D9
#define DIRGAUCHE D7
#define PWMDROITE D10
#define DIRDROITE D8
#define I2C_SDA   D14
#define I2C_SCL   D15

PwmOut pwmgauche(PWMGAUCHE);
DigitalOut dirgauche(DIRGAUCHE);
PwmOut pwmdroite(PWMDROITE);
DigitalOut dirdroite(DIRDROITE);
HMC5883L compass(I2C_SDA,I2C_SCL);

Counter counterGauche(PB_14);
Counter counterDroite(PB_13);

Captor frontCaptor();

double initHeading;

Hardware::Hardware() {
    pwmgauche.period_us(1000);
    pwmdroite.period_us(1000);
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(0);
    dirgauche=0;
    dirdroite=0;
    //compass.init();
    //initHeading=compass.getHeadingXYDeg(); 
}

void Hardware::move() {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(400);
    pwmdroite.pulsewidth_us(400);
    return;
}

void Hardware::moveBack() {
    dirgauche=1;
    dirdroite=0;
    pwmgauche.pulsewidth_us(400);
    pwmdroite.pulsewidth_us(400);
    return;
}

void Hardware::stepTurn(int dir) {
    if (dir==RIGHT) {
        dirgauche=0;
        dirdroite=0;
        pwmgauche.pulsewidth_us(400);
        pwmdroite.pulsewidth_us(200);
    } else {
        dirgauche=1;
        dirdroite=1;
        pwmgauche.pulsewidth_us(200);
        pwmdroite.pulsewidth_us(400);
    }
    return;
}

void Hardware::forward(int puissance) {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(puissance);
    pwmdroite.pulsewidth_us(puissance);
    return;
}

void Hardware::stop() {
    dirgauche=0;
    dirdroite=1;
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(0);
    return;
}

void Hardware::initHeadingDeg(){
    compass.init();
    wait(1);
    initHeading=compass.getHeadingXYDeg();
    wait(1);
    return;
}

int Hardware::getHeadingDeg(){
    return fabs(compass.getHeadingXYDeg()-initHeading);
}

void Hardware::resetCounterGauche(){
    return counterGauche.reset();
}

void Hardware::resetCounterDroite(){
    return counterDroite.reset();
}

int Hardware::readCounterGauche(){
    return counterGauche.read();
}

int Hardware::readCounterDroite(){
    return counterDroite.read();
}

void Hardware::detect(){
    frontCaptor.detect()
}
