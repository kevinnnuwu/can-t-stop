#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Tablero {
private:
    map<int, int> configuracion;
    vector<vector<string>> posiciones;         // Tablero original
    vector<vector<string>> posicionesTemporal; // Tablero temporal para el turno

public:
    Tablero();
    void inicializarConfiguracion();
    void inicializarPosiciones();
    void copiarATemporal();
    void aplicarTemporalAOriginal();
    void descartarTemporal();
    bool moverJugadorTemporal(int jugador, int columna);
    void mostrarTemporal() const;
    void mostrar() const;
};

#endif