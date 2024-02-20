#ifndef EVO_H
#define EVO_H

#include <string>
#include <iostream>
using namespace std;

class evo{

    public:
        evo(string, string, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, 
        int, int, int, string,string);
        string name;
        string positions;
        int maxOVR;
        int maxSpeed;
        int maxShot;
        int MaxPass;
        int maxDribble;
        int maxDef;
        int maxPhys;
        int maxPlaystyles;
        int maxPsP;
        int addSM;
        int addWF;
        int addOVR;
        int addPace;
        int addShot;
        int addPass;
        int addDrib;
        int addDef;
        int addPhys;
        string addPS;
        string addPos;

};

#endif
