#include "Dado.h"

Dado::Dado() {
    srand(time(0));
}

int Dado::lanzar() {
    return rand() % 6 + 1;
}

vector<int> Dado::lanzar4Dados() {
    int dado1 = lanzar();
    int dado2 = lanzar();
    int dado3 = lanzar();
    int dado4 = lanzar();
    vector<int> resultados = {dado1, dado2, dado3, dado4};

    cout << "Lanzamiento de dados:" << endl;
    cout << "Dado1 = " << dado1 << ", Dado2 = " << dado2
         << ", Dado3 = " << dado3 << ", Dado4 = " << dado4 << endl;

    return resultados;
}