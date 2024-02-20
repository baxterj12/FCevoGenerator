#include "main.h"

int main(){
    cout<<"Enter the shortened name of the player your wish to evolve."<<endl;
    cout<<"For two named players, type their first initial, a period, and their last name: L. Messi"<<endl;
    cout<<"For one named players, type their name: Casemiro"<<endl;
    string name;
    getline(cin,name);
    onePlayer p(name);
    combo c;
    c.comboSummary(p);
}