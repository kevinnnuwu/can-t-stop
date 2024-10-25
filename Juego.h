#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include "Tablero.h"
#include "Jugador.h"
#include "Dado.h"

class Juego {
private:
    Tablero tablero;
    std::vector<Jugador> jugadores;
    Dado dado;
    int jugadorActual;
    bool juegoTerminado;

    std::pair<int, int> elegirCombinacion(const std::vector<int>& dados);
    bool deseaContinuar();

public:
    Juego(int numJugadores);
    void jugar();
    void realizarTurno();
};
