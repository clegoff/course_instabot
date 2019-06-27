#include "Parameters.h"

int main() {
    //---INSTANCIATIONS---//
    ServiceActionMoteur* hardware;
    ServiceFrontDetect* frontCaptor;
    MyCanvas* brain;
    
    hardware=new Hardware();
    brain=new MyCanvas();
    frontCaptor = new Captor();
    
    //---BINDING---//
    brain->bindServiceActionMoteur(hardware);
    brain->bindServiceFrontDetect(frontCaptor);
    //---CORPS PRINCIPAL---//
    brain->activate();
    
    //wait(1);
    while(1){
        hardware->stop();
        brain->step();
        wait(0.1);
    }
}