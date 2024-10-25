#ifndef TABLERO_H
#define TABLERO_H

#include <map>
#include <vector>

using namespace std;

class Tablero {
private:
    std::map<int, int> columnas;
    std::vector<std::vector<int>> posiciones;

public:
    Tablero();
    void mostrarTablero() const;
    bool moverJugador(int jugador, int columna);
};

#endif