#include "combo.h"

vector<onePlayer> combo::allCombo(onePlayer p){
    if (p.appliedEvos.size()!=0){
        if (p.appliedEvos.back().name=="Founder Evolution"){
            evo founder2("Founder Evolution 2","ST",100,100,100,100,100,100,100,9,100,0,0,2,1,
            1,3,2,0,2,"Power Shot","None");
            p.possibleEvos.push_back(founder2);
        }
    }
    p.recheckPossible();
    vector<evo> allPos=p.possibleEvos;
    vector<onePlayer> allPlayers;
    allPlayers.push_back(p);
    for (int i=0;i<allPos.size();i++){
        onePlayer p2=p;
        p2.applyEvo(allPos[i]);
        vector<onePlayer> evoed=allCombo(p2);
        allPlayers.insert(allPlayers.end(),evoed.begin(),evoed.end());
    }
    return allPlayers;
}

void combo::comboSummary(onePlayer p){
    vector<onePlayer> all=allCombo(p);
    onePlayer best;
    for (int i=0;i<all.size();i++){
        if (all[i].totalStats()>best.totalStats()){
            best=all[i];
        }
    }
    cout<<"All Evos: "<<endl;
    for (int i=0;i<all.size();i++){
        all[i].summary();
    } 
    cout<<endl<<"Best evo by total stats: "<<endl;
    best.printInternal();
}

vector<onePlayer> combo::allComboForAll(){
    Players p;
    vector<onePlayer> allPlayers;
    for (int i=0;i<p.players.size();i++){
        onePlayer individual;
        individual.name=p.players[i][0];
        string positionsList=p.players[i][1];
        individual.positions=individual.listToVect(positionsList);
        individual.overall=stoi(p.players[i][2]);
        individual.wfoot=stoi(p.players[i][3]);
        individual.skillMoves=stoi(p.players[i][4]);
        string playstyles=p.players[i][5];
        individual.pstyles=individual.listToVect(playstyles);
        individual.pace=stoi(p.players[i][6]);
        individual.shooting=stoi(p.players[i][7]);
        individual.passing=stoi(p.players[i][8]);
        individual.dribbling=stoi(p.players[i][9]);
        individual.def=stoi(p.players[i][10]);
        individual.phys=stoi(p.players[i][11]);
        individual.pSP=individual.playStylePlus(individual.pstyles);
        individual.allToPossible();
        allPlayers.push_back(individual);
    }
}