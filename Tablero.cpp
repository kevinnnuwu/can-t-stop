#include "Tablero.h"
#include <iostream>

using namespace std;
Tablero::Tablero() {
    inicializarConfiguracion();
    inicializarPosiciones();
}

void Tablero::inicializarConfiguracion() {
    configuracion[2] = 3;
    configuracion[3] = 5;
    configuracion[4] = 7;
    configuracion[5] = 9;
    configuracion[6] = 11;
    configuracion[7] = 13;
    configuracion[8] = 11;
    configuracion[9] = 9;
    configuracion[10] = 7;
    configuracion[11] = 5;
    configuracion[12] = 3;
}

void Tablero::inicializarPosiciones() {
    posiciones.resize(13);
}

bool Tablero::moverJugador(int jugador, int columna) {
    int posicion = posiciones[columna].size();

    if (posicion < configuracion.at(columna)) {
        for (int i = 0; i < posiciones[columna].size(); i++) {
            if (posiciones[columna][i] == std::to_string(jugador)) {
                posiciones[columna][i] = "-";
                break;
            }
        }
        posiciones[columna].push_back("+");
        return false;
    } else {
        std::cout << "No hay más espacio en la columna " << columna << std::endl;
    }
    return false;
}

void Tablero::finalizarTurno(int jugador) {
    for (int columna = 2; columna <= 12; columna++) {
        for (int i = 0; i < posiciones[columna].size(); i++) {
            if (posiciones[columna][i] == "+") {
                posiciones[columna][i] = std::to_string(jugador);
            }
        }
    }
}

void Tablero::mostrar() const {
    cout << "Tablero de Can't Stop:" << endl;
    for (int columna = 2; columna <= 12; columna++) {
        cout << "Columna " << columna << ": ";
        for (int i = 0; i < configuracion.at(columna); i++) {
            if (posiciones[columna].size() > i) {
                cout << posiciones[columna][i] << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}