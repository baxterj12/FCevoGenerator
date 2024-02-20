#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Players
{
    public:
        Players();
        void read();
        vector<vector<string> > players;
        /*string name;
        string positions;
        string overall;
        string pfoot;
        string wfoot;
        string skillMoves;
        string playstyles;
        string pace;
        string shooting;
        string passing;
        string dribbling;
        string def;
        string phys;*/
};

#endif