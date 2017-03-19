#include <iostream>
#include "agent.h"
#include <algorithm>
using namespace std;
int size=200;
void print(string s){
    istringstream iss;
    for(unsigned int i=0;i<s.size();i++){
        for(unsigned int j=0;j<s.size();j++){
            char c =s.at(j);
            int n=c-'0';
            if(n==(signed)i){
                cout<<"[Q]";
            }
            else{
                cout<<"[ ]";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    srand(time(0));
    string s;
    population pop;
    std::ostringstream oss;
    for(int j=0;j<size;j++){
        for(int i=0;i<SZ;i++){
            oss<<rand()%SZ;
            s+=oss.str();
            oss.str("");
            oss.clear();
        }
        pop.push_back(s);
        s="";
    }
    Agent a;
    board solved = a.experiment(pop);
    cout<<"population size: "<<size<<", board size: "<<SZ<<endl;
    cout<<"solved in "<<a.getGens()<<" Generations."<<endl;
    print(solved);
}
