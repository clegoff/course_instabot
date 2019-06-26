#include "Parameters.h"

int main() {
    //---INSTANCIATIONS---//
    ServiceActionMoteur* hardware;
    MyCanvas* brain;
    
    hardware=new Hardware();
    brain=new MyCanvas();
    frontCaptor = new Captor();
    
    //---BINDING---//
    brain->bindServiceActionMoteur(hardware);
    
    //---CORPS PRINCIPAL---//
    brain->activate();
    
    //wait(1);
    while(1){
        hardware->stop();
        brain->step();
        frontCaptor->detect();
        wait(0.1);
    }
}