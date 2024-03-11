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