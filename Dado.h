#ifndef DADO_H
#define DADO_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Dado {
public:
    Dado();
    int lanzar();
    vector<int> lanzar4Dados();
};

#endif