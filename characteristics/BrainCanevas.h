BrainCanevas::BrainCanevas():actionMoteur(){}
void BrainCanevas::move(){actionMoteur->move(); return;}
void BrainCanevas::moveBack(){actionMoteur->moveBack(); return;}
void BrainCanevas::stepTurn(int dir){actionMoteur->stepTurn(dir); return;}
void BrainCanevas::resetCounterGauche(){actionMoteur->resetCounterGauche(); return;}
void BrainCanevas::resetCounterDroite(){actionMoteur->resetCounterDroite(); return;}
int BrainCanevas::readCounterGauche(){return actionMoteur->readCounterGauche();}
int BrainCanevas::readCounterDroite(){return actionMoteur->readCounterDroite();}

void BrainCanevas::bindServiceActionMoteur(ServiceActionMoteur* service) {
    actionMoteur=service;
    return;
}
