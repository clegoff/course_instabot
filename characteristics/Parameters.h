#include "mbed.h"

#define SUCCESS 1
#define FAILURE 0
#define RIGHT 0x12345
#define LEFT 0x54321

//---SERVICES---//
class ServiceActionMoteur {
public:
    virtual void move()=0;
    virtual void moveBack()=0;
    virtual void stepTurn(int dir)=0;
    virtual void forward(int puissance)=0;
    virtual void stop()=0;
    virtual int getHeadingDeg()=0;
    virtual void initHeadingDeg()=0;
    virtual void resetCounterGauche()=0;
    virtual void resetCounterDroite()=0;
    virtual int readCounterGauche()=0;
    virtual int readCounterDroite()=0;
};

class ServiceRequisActionMoteur {
public:
    virtual void bindServiceActionMoteur(ServiceActionMoteur* service)=0;
};

class ServiceInitialisation {
public:
    virtual void activate()=0;
};
class ServiceRequisInitialisation {
public:
    virtual void bindServiceInitialisation(ServiceInitialisation* service)=0;
};

class ServiceActionPasAPas {
public:
    virtual void step()=0;
};
class ServiceRequisActionPasAPas {
public:
    virtual void bindServiceActionPasAPas(ServiceActionPasAPas* service)=0;
};



//---COMPOSANTS---//
class Hardware: public ServiceActionMoteur {
public:
    Hardware();
    void move();
    void moveBack();
    void stepTurn(int dir);
    void forward(int puissance);
    void stop();
    int getHeadingDeg();
    void initHeadingDeg();
    void resetCounterGauche();
    void resetCounterDroite();
    int readCounterGauche();
    int readCounterDroite();
};

class MyCanvas: public ServiceRequisActionMoteur,
                    public ServiceInitialisation,
                    public ServiceActionPasAPas {
private:
    ServiceActionMoteur* actionMoteur;
public:
    MyCanvas();
    void activate();
    void step();
    void bindServiceActionMoteur(ServiceActionMoteur* service);
    void move();
    void moveBack();
    void stepTurn(int dir);
    void resetCounterGauche();
    void resetCounterDroite();
    int readCounterGauche();
    int readCounterDroite();
};

class Captor {
public:
    Captor();
    void detect();
};