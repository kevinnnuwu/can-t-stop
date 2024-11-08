#include "Jugador.h"

Jugador::Jugador(int id) : id(id), columnasCompletadas(0) {}

int Jugador::getId() const {
    return id;
}

int Jugador::getColumnasCompletadas() const {
    return columnasCompletadas;
}

void Jugador::incrementarColumnasCompletadas() {
    columnasCompletadas++;
}

void Jugador::limpiarColumnasElegidas() {
    columnasElegidas.clear();
}

bool Jugador::agregarColumnaElegida(int columna) {
    columnasElegidas.insert(columna);
    return columnasElegidas.size() <= 3;
}