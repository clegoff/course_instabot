#include "Parameters.h"

int main() {
    //---INSTANCIATIONS---//
    ServiceActionMoteur* hardware;
    MyCanvas* brain;
    Captor* captors;
    
    hardware=new Hardware();
    brain=new MyCanvas();
    captors=new Captor();
    
    //---BINDING---//
    brain->bindServiceActionMoteur(hardware);
    
    //---CORPS PRINCIPAL---//
    brain->activate();
    
    //wait(1);
    while(1){
        hardware->stop();
        brain->step();
        captors->detect();
        wait(0.1);
    }
}