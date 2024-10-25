#include "Jugador.h" // Incluye el archivo de encabezado de la clase Jugador, donde se declara la clase.

Jugador::Jugador(int id) : id(id), columnasCompletadas(0) {} 
// Constructor de Jugador que inicializa el id del jugador y establece columnasCompletadas en 0.

int Jugador::getId() const {
    return id; // Devuelve el ID del jugador.
}

int Jugador::getColumnasCompletadas() const {
    return columnasCompletadas; // Devuelve el número de columnas completadas por el jugador.
}

void Jugador::incrementarColumnasCompletadas() {
    columnasCompletadas++; // Incrementa en 1 el número de columnas completadas por el jugador.
}

void Jugador::limpiarColumnasElegidas() {
    columnasElegidas.clear(); // Limpia el conjunto de columnas elegidas para el turno actual.
}

bool Jugador::agregarColumnaElegida(int columna) {
    columnasElegidas.insert(columna); // Agrega una columna elegida al conjunto.
    return columnasElegidas.size() <= 3; // Verifica que el jugador no elija más de 3 columnas diferentes en un turno.
}
