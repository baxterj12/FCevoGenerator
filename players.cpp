#include "players.h"

Players::Players(){
    read();
}

void Players::read(){
    ifstream in;
    in.open("allData.txt");
    string header;
    in>>header;
    string name;
    string positions;
    string overall;
    string wfoot;
    string skillMoves;
    string playstyles;
    string pace;
    string shooting;
    string passing;
    string dribbling;
    string def;
    string phys;
    string fill;
    while (getline(in,fill,',') && getline(in,fill,'"') && getline(in,name,'"') && getline(in,fill,',')
        && getline(in,fill,'"') && getline(in,positions,'"') && getline(in,fill,',') && getline(in,overall,',')
        && getline(in,wfoot,',') && getline(in,skillMoves,',') && getline(in,fill,'"')
        && getline(in,playstyles,'"') && getline(in,fill,',') && getline(in,pace,',') && getline(in,shooting,',')
        && getline(in,passing,',') && getline(in,dribbling,',') && getline(in,def,',')
        && getline(in,phys)){
            vector<string> player;
            player.push_back(name);
            player.push_back(positions);
            player.push_back(overall);
            player.push_back(wfoot);
            player.push_back(skillMoves);
            player.push_back(playstyles);
            player.push_back(pace);
            player.push_back(shooting);
            player.push_back(passing);
            player.push_back(dribbling);
            player.push_back(def);
            player.push_back(phys);
            players.push_back(player);
    }
}