#ifndef AGENT_H
#define AGENT_H
#include "state.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits>
#include <sstream>
extern int size;
class Agent {
public:
    Agent();
    Agent(int s);
    board experiment(population);
    void printExploredSet();
    void scramble(population);
    population select(population);
    population cross(population);
    population mutate(population&);
    int getGens(){return gens;}

private:
    std::ostringstream oss;
    int gens;
};

#endif
