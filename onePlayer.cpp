#include "onePlayer.h"


onePlayer::onePlayer(){
    name=" "; 
    overall=0;  
    wfoot=0;
    skillMoves=0; 
    pace=0;
    shooting=0;
    passing=0;
    dribbling=0;
    def=0;
    phys=0;
    pSP=0;
}

onePlayer::onePlayer(const onePlayer& p){
    *this = p;
}

onePlayer::onePlayer(string search){
    vector<int> found;
    Players p;
    for (int i=0;i<p.players.size();i++){
        if (p.players[i][0]==search){
            found.push_back(i);
        }
    }

    if (found.size()==0){
        throw NoSuchObject("players:construct:no such object");
    } else if (found.size()==1){
        int i=found.back();
        name=p.players[i][0];
        string positionsList=p.players[i][1];
        positions=listToVect(positionsList);
        overall=stoi(p.players[i][2]);
        wfoot=stoi(p.players[i][3]);
        skillMoves=stoi(p.players[i][4]);
        string playstyles=p.players[i][5];
        pstyles=listToVect(playstyles);
        pace=stoi(p.players[i][6]);
        shooting=stoi(p.players[i][7]);
        passing=stoi(p.players[i][8]);
        dribbling=stoi(p.players[i][9]);
        def=stoi(p.players[i][10]);
        phys=stoi(p.players[i][11]);
        pSP=playStylePlus(pstyles);
        allToPossible();
    } else {
        cout<<"Multiple players with that name: write the number of the player you desire: "<<endl;
        for (int i=0;i<found.size();i++){
            cout<<i<<" "<<p.players[found[i]][0]<<" "<<p.players[found[i]][1]<<" "
            <<p.players[found[i]][2]<<" Overall"<<endl;
        }
        int chosen=0;
        cin>>chosen;
        if (chosen<0||chosen>found.size()-1){
            return;
        } else {
            int i=found[chosen];
            name=p.players[i][0];
            string positionsList=p.players[i][1];
            positions=listToVect(positionsList);
            overall=stoi(p.players[i][2]);
            wfoot=stoi(p.players[i][3]);
            skillMoves=stoi(p.players[i][4]);
            string playstyles=p.players[i][5];
            pstyles=listToVect(playstyles);
            pace=stoi(p.players[i][6]);
            shooting=stoi(p.players[i][7]);
            passing=stoi(p.players[i][8]);
            dribbling=stoi(p.players[i][9]);
            def=stoi(p.players[i][10]);
            phys=stoi(p.players[i][11]);
            pSP=playStylePlus(pstyles);
            allToPossible();
        }
    }
}

int onePlayer::totalStats(){
    return pace+shooting+passing+dribbling+def+phys;
}

vector<string> onePlayer::listToVect(string plist){
    vector<string> pos;
    if (plist=="None"){
        return pos;
    }
    for (int i=0;i<plist.size();i++){
        if (plist[i]==','){
            pos.push_back(plist.substr(0,i));
            plist.erase(0,i+2);
            i=0;
        }
    }
    pos.push_back(plist);
    return pos;
}

bool onePlayer::plays(string pos){
    for (int i=0;i<positions.size();i++){
        if(positions[i]==pos){
            return true;
        }
    }
    return false;
}

int onePlayer::playStylePlus(vector<string> pstyles){
    int temp=0;
    for (int i=0;i<pstyles.size();i++){
        if (pstyles[i].back()=='+'){
            temp++;
        }
    }
    return temp;
}

void onePlayer::pstylesFilter(){
    priority_queue<string> filter;
    for(int i=0;i<pstyles.size();i++){
        filter.push(pstyles[i]);
    }
    vector<string> filterVect;
    while(filter.size()!=0){
        filterVect.push_back(filter.top());
        filter.pop();
    }
    for (int i=1;i<filterVect.size();i++){
        if (filterVect[i]==filterVect[i-1]||(filterVect[i]+"+"==filterVect[i-1])){
            filterVect.erase(filterVect.begin()+i);
            i--;
        }
    }
    pstyles=filterVect;
}

bool onePlayer::canEvo(evo e){
    if (plays(e.positions) && overall<=e.maxOVR && pace<=e.maxSpeed && shooting <=e.maxShot
    && passing<=e.MaxPass && dribbling <= e.maxDribble && def<=e.maxDef && phys<=e.maxPhys
    && pstyles.size()<=e.maxPlaystyles && pSP<=e.maxPsP){
        return true;
    }
    return false;
}

vector<evo> onePlayer::AllEvos(){
    vector<evo> evos;
    evo DoublePlusPursuit("Double Plus Pursuit", "CM",75,80,74,100,100,100,100,7,0,0,2,
    14,6,12,13,12,11,9,"Slide Tackle, Incisive Pass+, Relentless+","None");
    evo FsRightBackPowerUp("FS Right Back Power Up","RB",85,87,100,100,100,100,90,100,0,0,0,
    4,3,0,4,3,3,0,"Slide Tackle +","None");
    evo FsAttackingMidfielder("FS Attacking Midfielder","CAM",85,87,100,100,100,100,100,8,0,
    1,1,4,2,2,5,0,0,0,"Press Proven, Rapid+","None");
    evo WingWizard("Wing Wizard","LW",85,87,100,100,100,100,85,8,0,0,0,4,3,4,4,4,0,3,
    "Trivela, Rapid+","None");
    evo RightSideStar("Right Side Star","RW",85,86,87,100,86,100,86,9,0,1,0,3,3,4,3,3,0,2,
    "Chip Shot","None");
    evo FounderEvo("Founder Evolution","ST",85,94,80,79,86,100,88,100,100,1,0,2,2,3,3,2,0,2,
    "None","None");
    //ADD UPGRADES FOR EVOS
    evos.push_back(DoublePlusPursuit);
    evos.push_back(FsRightBackPowerUp);
    evos.push_back(FsAttackingMidfielder);
    evos.push_back(WingWizard);
    evos.push_back(RightSideStar);
    evos.push_back(FounderEvo);
    return evos;
}

vector<evo> onePlayer::allToPossible(){
    vector<evo> allEvos=AllEvos();
    vector<evo> possEvo;
    for (int i=0;i<allEvos.size();i++){
        if (canEvo(allEvos[i])){
            possEvo.push_back(allEvos[i]);
        }
    }
    possibleEvos=possEvo;
    return possEvo;
}

void onePlayer::applyEvo(evo e){
    overall=overall+e.addOVR;
    wfoot=wfoot+e.addWF;
    if(wfoot>5){
        wfoot=5;
    }
    skillMoves=skillMoves+e.addSM;
    if(skillMoves>5){
        skillMoves=5;
    }
    pace=pace+e.addPace;
    shooting=shooting+e.addShot;
    passing=passing+e.addPass;
    dribbling=dribbling+e.addDrib;
    def=def+e.addDef;
    phys=phys+e.addPhys;
    vector<string> newPos=listToVect(e.addPos);
    positions.insert(positions.end(),newPos.begin(),newPos.end());
    vector<string> newPS=listToVect(e.addPS);
    pstyles.insert(pstyles.end(),newPS.begin(),newPS.end());
    for (int i=0;i<possibleEvos.size();i++){
        if (e.name==possibleEvos[i].name){
            possibleEvos.erase(possibleEvos.begin()+i);
            i--;
        }
    }
    appliedEvos.push_back(e);
    pstylesFilter();
}

void onePlayer::recheckPossible(){
    for (int i=0;i<possibleEvos.size();i++){
        if (canEvo(possibleEvos[i])==false){
            possibleEvos.erase(possibleEvos.begin()+i);
            i--;
        }
    }
}

void onePlayer::printInternal(){
    cout<<name<<endl;
    cout<<"OVR: "<<overall<<endl;
    cout<<"Skill Moves: "<<skillMoves<<"  Weak foot: "<<wfoot<<endl;
    cout<<"Pace: "<<pace<<"  Shooting: "<<shooting<<"  Passing: "<<passing<<endl;
    cout<<"Dribbling: "<<dribbling<<"  Defense:  "<<def<<"  Physical: "<<phys<<endl;
    cout<<"Sum of all stats: "<<totalStats()<<endl;
    cout<<"Positions: ";
    for(int i=0;i<positions.size();i++){
        cout<<positions[i]<<" ";
    }
    cout<<endl<<"Playstyles:";
    for (int i=0;i<pstyles.size();i++){
        if (i%4==0){
            cout<<endl;
        }
        cout<<pstyles[i]<<"  ";
    }
    cout<<endl;
    cout<<"Available Evolutions: ";
    for (int i=0;i<possibleEvos.size();i++){
        if(i%4==0){
            cout<<endl;
        }
        cout<<possibleEvos[i].name<<"  ";
    }
    cout<<endl;
    cout<<"Used Evos: ";
    for (int i=0;i<appliedEvos.size();i++){
        if(i%4==0){
            cout<<endl;
        }
        cout<<appliedEvos[i].name<<"  ";
    }
    cout<<endl;
}

void onePlayer::summary(){
    cout<<name<<" OVR: "<<overall<<" "<<pace<<" "<<shooting<<" "<<passing<<" "
    <<dribbling<<" "<<def<<" "<<phys<<endl;
}