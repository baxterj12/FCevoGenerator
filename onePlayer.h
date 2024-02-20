#ifndef ONEPLAYER_H
#define ONEPLAYER_H

#include "players.h"
#include "nosuchobject.h"
#include "evo.h"
#include <queue>

class onePlayer{

    public:
        onePlayer();
        onePlayer(string);
        bool plays(string);
        onePlayer(const onePlayer&);
        vector<string> listToVect(string plist);
        int playStylePlus(vector<string> psytles);
        bool canEvo(evo);
        void printInternal();
        void summary();
        vector<evo> AllEvos();
        vector<evo> allToPossible();
        void applyEvo(evo);
        int totalStats();
        void recheckPossible();
        void pstylesFilter();
        string name; 
        int overall;  
        int wfoot;
        int skillMoves; 
        int pace;
        int shooting;
        int passing;
        int dribbling;
        int def;
        int phys;
        vector<string> positions;
        vector<string> pstyles;
        int pSP;
        vector<evo> possibleEvos;
        vector<evo> appliedEvos;
};
#endif