#include "Parameters.h"
#include "MyCanvas.h"

int MAXPASDEJEU=280;

int pasDeJeuCourrant;

void MyCanvas::activate() {
    pasDeJeuCourrant=0;
    return;
}

void MyCanvas::step() {

    if (pasDeJeuCourrant>MAXPASDEJEU) {return;}

    pasDeJeuCourrant++;

    if (pasDeJeuCourrant>=180){
        move();
        return;
    }

    if (pasDeJeuCourrant>=150){
        stepTurn(LEFT);
        return;
    }

    if (pasDeJeuCourrant>=120){
        return;
    }

    if (pasDeJeuCourrant>=80){
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