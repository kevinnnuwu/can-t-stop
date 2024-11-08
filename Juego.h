#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include "Tablero.h"
#include "Jugador.h"
#include "Dado.h"
using namespace std;

class Juego {
private:
    Tablero tablero;
    vector<Jugador> jugadores;
    Dado dado;
    int jugadorActual;
    bool juegoTerminado;

    void mostrarOpcionesCombinadas(const vector<int>& dados);
    pair<int, int> elegirCombinacion(const vector<int>& dados);
    bool deseaContinuar();

public:
    Juego(int numJugadores);
    void jugar();
    void realizarTurno();
};

#endif