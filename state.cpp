
/*
#include "state.h"
extern char goal[][STATELENGTH];
State::State() {
}

void lookup(char val,int& x, int& y){
    bool b=false;
    for(int i =0;i<STATELENGTH;i++){
        for(int j=0; j<STATELENGTH;j++){
            if(goal[i][j]==val){
                x=i;
                y=j;
                b=true;
                break;
            }
        }
    if(b)
        break;
    }
}

int manhat(int i, int j, int x, int y){
    return abs(i-x)+abs(j-y);
}

int State::getScore(int type){
int score = 0;
if(type==1){
    for(int i =0;i<STATELENGTH;i++){
        for(int j=0; j<STATELENGTH;j++){
           int x,y;
           lookup(s[i][j],x,y);
           score += manhat(i,j,x,y);
        }
    }
}
else{
    int num=1;
    for(int i =0;i<STATELENGTH;i++){
        for(int j=0; j<STATELENGTH;j++){
            int h;
            char val = s[i][j];
            if(val == ' ')
                h=0;
            else
                h=val - '0';
            if(num++!=h)
                score++;
        }
    }
}
    //std::cout<<"score: "<<score<<std::endl;
    return score;
}

State::State(char a[STATELENGTH][STATELENGTH]){
for(int i=0;i<STATELENGTH;i++){
    for(int j=0;j<STATELENGTH;j++){
        set(a[i][j],i,j);
    }
}
}

State::State(char** state){
for(int i=0;i<STATELENGTH;i++){
    for(int j=0;j<STATELENGTH;j++){
        set(state[i][j],i,j);
    }
}
}

void State::print(){
for(int i=0;i<STATELENGTH;i++){
    for(int j=0;j<STATELENGTH;j++){
        std::cout<<s[i][j];
    }
    std::cout<<std::endl;
}
    std::cout<<std::endl;
}

State State::getState(){
    return s;
}

char State::at(int i,int j)const{
    const char* b ="";
    if(s[i][j]==*b)
        return 0;
    else
        return s[i][j];
}

char State::operator[](int& i){
    if(i>=0&&i<STATELENGTH)
        return *state[i];
}

bool State::operator==(const State& s1) {
    bool res=true;
    for(int i=0;i<STATELENGTH;i++){
        for(int j=0;j<STATELENGTH;j++){
            if(at(i,j)!=s1.at(i,j))
                res=false;
        }
    }
    return res;
}


State State::swap(int i, int j, int x, int y){
    State s1 = s;
    char c = s1.at(i,j);
    s1.set(s1.at(x,y),i,j);
    s1.set(c,x,y);
    return s1;
}

StateList State::getActions() {
    StateList sl;
    const char* b=" ";
    int i=0;
    int j=0;
    while(i<STATELENGTH){
        while(j<STATELENGTH){
            char c = at(i,j);
            if(c==*b){
                if(i-1>=0)
                    sl.push_back(swap(i,j,i-1,j));
                if(i+1<STATELENGTH)
                    sl.push_back(swap(i,j,i+1,j));
                if(j-1>=0)
                    sl.push_back(swap(i,j,i,j-1));
                if(j+1<STATELENGTH)
                    sl.push_back(swap(i,j,i,j+1));
                return sl;
            }
            j++;

        }
        j=0;
        i++;
    }
    return sl;
}
*/
