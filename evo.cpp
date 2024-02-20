#include "evo.h"

evo::evo(string n, string pos, int ovr, int spd, int sht, int pss, int dri, int def, int phys, int ps, int psp, int newSM,
    int newWF, int newOVR, int newPace, int newShot, int newPass, int newDrib, int newDef, int newPhys, string newPS, string newPos){
    name=n;
    positions=pos;
    maxOVR=ovr;
    maxSpeed=spd;
    maxShot=sht;
    MaxPass=pss;
    maxDribble=dri;
    maxDef=def;
    maxPhys=phys;
    maxPlaystyles=ps;
    maxPsP=psp;
    addSM=newSM;
    addWF=newWF;
    addOVR=newOVR;
    addPace=newPace;
    addShot=newShot;
    addPass=newPass;
    addDrib=newDrib;
    addDef=newDef;
    addPhys=newPhys;
    addPS=newPS;
    addPos=newPos;

}