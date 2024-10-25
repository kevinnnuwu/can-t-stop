#include "Tablero.h" // Incluye el archivo de encabezado de la clase Tablero.
#include <iostream> // Incluye la biblioteca estándar para la entrada y salida de datos.

using namespace std;

Tablero::Tablero() {
    inicializarConfiguracion(); // Inicializa la configuración de las columnas en el tablero.
    inicializarPosiciones(); // Inicializa las posiciones de los jugadores en el tablero.
}

void Tablero::inicializarConfiguracion() {
    // Define la cantidad máxima de posiciones en cada columna.
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
    posiciones.resize(13); // Ajusta el tamaño del vector de posiciones para las 13 columnas (2-12).
}

bool Tablero::moverJugador(int jugador, int columna) {
    int posicion = posiciones[columna].size(); // Obtiene el número de posiciones ocupadas en la columna.

    if (posicion < configuracion.at(columna)) { 
        // Verifica si hay espacio disponible en la columna.
        for (int i = 0; i < posiciones[columna].size(); i++) {
            if (posiciones[columna][i] == std::to_string(jugador)) {
                posiciones[columna][i] = "-"; // Limpia la posición anterior del jugador.
                break;
            }
        }
        posiciones[columna].push_back("+"); // Marca la nueva posición del jugador con "+".
        return false; // Retorna false indicando que la columna no está completada.
    } else {
        std::cout << "No hay más espacio en la columna " << columna << std::endl;
        // Muestra un mensaje si la columna está llena.
    }
    return false; // Retorna false ya que la columna no puede ser completada.
}

void Tablero::finalizarTurno(int jugador) {
    for (int columna = 2; columna <= 12; columna++) { 
        // Recorre todas las columnas para actualizar la posición del jugador.
        for (int i = 0; i < posiciones[columna].size(); i++) {
            if (posiciones[columna][i] == "+") {
                posiciones[columna][i] = std::to_string(jugador); 
                // Reemplaza la posición temporal del jugador con su número de ID.
            }
        }
    }
}

void Tablero::mostrar() const {
    cout << "Tablero de Can't Stop:" << endl; // Muestra el título del tablero.
    for (int columna = 2; columna <= 12; columna++) {
        cout << "Columna " << columna << ": "; // Muestra el número de cada columna.
        for (int i = 0; i < configuracion.at(columna); i++) {
            if (posiciones[columna].size() > i) {
                cout << posiciones[columna][i] << " "; // Muestra las posiciones ocupadas en la columna.
            } else {
                cout << "- "; // Muestra "-" para las posiciones vacías.
            }
        }
        cout << endl; // Salta a la siguiente línea para mostrar la próxima columna.
    }
}
