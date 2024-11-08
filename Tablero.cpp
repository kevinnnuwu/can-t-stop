#include "Tablero.h"

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
    posicionesTemporal.resize(13);
}

void Tablero::copiarATemporal() {
    posicionesTemporal = posiciones;
}

void Tablero::aplicarTemporalAOriginal() {
    posiciones = posicionesTemporal;
}

void Tablero::descartarTemporal() {
    posicionesTemporal = posiciones;
}

bool Tablero::moverJugadorTemporal(int jugador, int columna) {
    int posicion = posicionesTemporal[columna].size();

    if (posicion < configuracion.at(columna)) {
        for (int i = 0; i < posicionesTemporal[columna].size(); i++) {
            if (posicionesTemporal[columna][i] == to_string(jugador)) {
                posicionesTemporal[columna][i] = "-";
                break;
            }
        }
        posicionesTemporal[columna].push_back(to_string(jugador));
        return true;
    } else {
        cout << "No hay más espacio en la columna " << columna << endl;
    }
    return false;
}

void Tablero::mostrarTemporal() const {
    cout << "Tablero de Can't Stop (turno actual):" << endl;
    for (int columna = 2; columna <= 12; columna++) {
        cout << "Columna " << columna << ": ";
        for (int i = 0; i < configuracion.at(columna); i++) {
            if (posicionesTemporal[columna].size() > i) {
                cout << posicionesTemporal[columna][i] << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
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