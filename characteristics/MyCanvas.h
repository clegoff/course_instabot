MyCanvas::MyCanvas():actionMoteur(){}
void MyCanvas::move(){actionMoteur->move(); return;}
void MyCanvas::moveBack(){actionMoteur->moveBack(); return;}
void MyCanvas::stepTurn(int dir){actionMoteur->stepTurn(dir); return;}
void MyCanvas::resetCounterGauche(){actionMoteur->resetCounterGauche(); return;}
void MyCanvas::resetCounterDroite(){actionMoteur->resetCounterDroite(); return;}
int MyCanvas::readCounterGauche(){return actionMoteur->readCounterGauche();}
int MyCanvas::readCounterDroite(){return actionMoteur->readCounterDroite();}

void MyCanvas::bindServiceActionMoteur(ServiceActionMoteur* service) {
    actionMoteur=service;
    return;
}
