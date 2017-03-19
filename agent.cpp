#include "agent.h"
using namespace std;
Agent::Agent(){
    gens=0;
}

int scoreState(board s){
    int diff=0;
    unsigned int i;
    unsigned int j;
    int score;
    for(i=0;i<s.size();i++){
        for(j=i+1;j<s.size();j++){
            diff++;
            if(s.at(j)==s.at(i)) score++;
            else if(s.at(j)==(s.at(i))+diff)score++;
            else if(s.at(j)==(s.at(i))-diff)score++;
        }
        diff=0;
    }
    return score;
}

void Agent::scramble(population p){
    string s="";
    p.clear();
    std::ostringstream oss;
    for(int j=0;j<size;j++){
        for(int i=0;i<SZ;i++){
            oss<<rand()%SZ;
            s+=oss.str();
            oss.str("");
            oss.clear();
        }
        p.push_back(s);
        s="";
    }
}

population Agent::select(population p){
    int score =0;
    int scores[p.size()];
    for(unsigned int i = 0;i<p.size();i++){ //generate score list
        board curboard = p.at(i);
        score = scoreState(curboard);
        if(score ==0){  //return answer
            population one;
            one.push_back(curboard);
            return one;
        }
        else{
            scores[i] = (SZ-score);
        }
    }
    population spop;                     //make a population where the
    for(unsigned int i=0;i<p.size();i++){//difference of their score and the board size
        for(int j=0;j<scores[i];j++){    //is the number of times they appear in the population
            spop.push_back(p.at(i));     //so that low scores appear more in the population.
        }                                //If score > board size then a negative number will never be
    }                                    //greater than j so really bad scores dont have a chance to mate.
    population npop;
    for(unsigned int i=0;i<p.size();i++){  //select 100(pop size) random boards from the selectionpop(spop)
        npop.push_back(spop.at(rand()%spop.size()));
    }
    return npop;
}

population Agent::cross(population p){
    population npop;
    for(unsigned int i = 0;i<p.size()-1;i+=2){ //cross in pairs (0,1), (2,3), (4,5),...,(popsize-1,popsize)
        board b1 = p.at(i);
        board b2 = p.at(i+1);
        int r= rand()%SZ;
        board b1post = b1.substr(r);
        board b2post = b2.substr(r);
        b2post+=b1.substr(0,r);
        b1post+=b2.substr(0,r);
        npop.push_back(b1post);
        npop.push_back(b2post);
    }
    return npop;
}

population Agent::mutate(population& p){
    for(unsigned int i = 0;i<p.size();i++){
        if(rand()%SZ==0){  // 1 in 8 change to mutate
            int r=(rand()%4)+3;
            oss<<r;
            string n=oss.str();
            oss.str("");
            oss.clear();
            string pre=p.at(i).substr(0,r-1);
            string post= p.at(i).substr(r);
            pre+=n+=post;
            p.at(i) = pre;
        }
    }
    return p;
}

board Agent::experiment(population p){
    population ngen = select(p);
    while(true){
        if(gens>10000){
            cout<<"reset"<<endl;
            scramble(p);
            gens=0;
        }
        if(gens!=0)
            ngen = select(ngen);
        if(ngen.size()==1){   //check if select() returned a solution
            return ngen.at(0);
        }
        ngen = cross(ngen);
        ngen = mutate(ngen);
        gens++;
    }
}

