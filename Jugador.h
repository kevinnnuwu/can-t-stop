#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <set>
using namespace std;

class Jugador {
private:
    int id;
    int columnasCompletadas;
    set<int> columnasElegidas;

public:
    Jugador(int id);
    int getId() const;
    int getColumnasCompletadas() const;
    void incrementarColumnasCompletadas();
    void limpiarColumnasElegidas();
    bool agregarColumnaElegida(int columna);
};

#endif