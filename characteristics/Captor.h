#define MBED_RANGEFINDER_H

/*void Captor::bindServiceActionMoteur() {
    actionMoteur=service;
    return;
}*/

class Captor {
public:
    Captor();
    void detect();
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
};