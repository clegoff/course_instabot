#include "Parameters.h"
#include "MyCanvas.h"

int MAXPASDEJEU=280;

int pasDeJeuCourrant;

void MyCanvas::activate() {
    pasDeJeuCourrant=0;
    //wait(1);
    //actionMoteur->initHeadingDeg();
    return;
}

void MyCanvas::step() {

    if (pasDeJeuCourrant>MAXPASDEJEU) {return;}
    pasDeJeuCourrant++;


    //SOME RANDOM STUFF
    /*if (pasDeJeuCourrant>=121){
        if (readCounterGauche()>=10000 && readCounterDroite() >=10000) {
            moveBack();
            if (readCounterGauche()>=15000 && readCounterDroite()>=15000){
                resetCounterDroite();
                resetCounterGauche();
            }
        } else {
            move();
        }
        return;
    }
    if (pasDeJeuCourrant>=120){
        resetCounterGauche();
        resetCounterDroite();
    }*/

    if (pasDeJeuCourrant>=200){
        move();
        return;
    }

    if (pasDeJeuCourrant>=160){
        stepTurn(LEFT);
        return;
    }

    if (pasDeJeuCourrant>=130){
        return;
    }

    if (pasDeJeuCourrant>=90){
        move();
        return;
    }

    if (pasDeJeuCourrant>=70){
        stepTurn(RIGHT);
        return;
    }

    if (pasDeJeuCourrant>40){
        return;
    }

    if (pasDeJeuCourrant<=40){
        move();
        return;
    }

    return;
}