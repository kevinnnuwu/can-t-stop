#include "Juego.h"

Juego::Juego(int numJugadores) : jugadorActual(0), juegoTerminado(false) {
    for (int i = 1; i <= numJugadores; i++) {
        jugadores.emplace_back(i);
    }
}

void Juego::mostrarOpcionesCombinadas(const vector<int>& dados) {
    cout << "Opciones de columnas para avanzar (elige una combinación): " << endl;
    cout << "1. Columna " << dados[0] + dados[1] << " y Columna " << dados[2] + dados[3] << endl;
    cout << "2. Columna " << dados[0] + dados[2] << " y Columna " << dados[1] + dados[3] << endl;
    cout << "3. Columna " << dados[0] + dados[3] << " y Columna " << dados[1] + dados[2] << endl;
}

pair<int, int> Juego::elegirCombinacion(const vector<int>& dados) {
    int eleccion;
    cout << "Elige una combinación (1-3): ";
    cin >> eleccion;

    switch (eleccion) {
        case 1: return make_pair(dados[0] + dados[1], dados[2] + dados[3]);
        case 2: return make_pair(dados[0] + dados[2], dados[1] + dados[3]);
        case 3: return make_pair(dados[0] + dados[3], dados[1] + dados[2]);
        default: return make_pair(dados[0] + dados[1], dados[2] + dados[3]);
    }
}

bool Juego::deseaContinuar() {
    char respuesta;
    cout << "¿Deseas continuar lanzando los dados? (s/n): ";
    cin >> respuesta;
    return respuesta == 's' || respuesta == 'S';
}

void Juego::jugar() {
    while (!juegoTerminado) {
        tablero.mostrar();
        realizarTurno();

        if (!juegoTerminado) {
            jugadorActual = (jugadorActual + 1) % jugadores.size();
        }
    }
}

void Juego::realizarTurno() {
    Jugador& jugadorActivo = jugadores[jugadorActual];
    jugadorActivo.limpiarColumnasElegidas();
    bool turnoTerminado = false;

    tablero.copiarATemporal();

    while (!turnoTerminado) {
        vector<int> opciones = dado.lanzar4Dados();
        mostrarOpcionesCombinadas(opciones);

        auto eleccion = elegirCombinacion(opciones);

        if (!jugadorActivo.agregarColumnaElegida(eleccion.first) ||
            !jugadorActivo.agregarColumnaElegida(eleccion.second)) {
            cout << "Has elegido más de 3 columnas distintas, ¡pierdes el turno!" << endl;
            turnoTerminado = true;
            tablero.descartarTemporal();
            break;
        }

        bool col1Completada = tablero.moverJugadorTemporal(jugadorActivo.getId(), eleccion.first);
        bool col2Completada = tablero.moverJugadorTemporal(jugadorActivo.getId(), eleccion.second);

        tablero.mostrarTemporal();

        if (jugadorActivo.getColumnasCompletadas() >= 3) {
            cout << "¡Jugador " << jugadorActivo.getId() 
                 << " ha completado 3 columnas y gana el juego!" << endl;
            juegoTerminado = true;
            tablero.aplicarTemporalAOriginal();
            break;
        }

        turnoTerminado = !deseaContinuar();
    }

    if (!juegoTerminado) {
        tablero.aplicarTemporalAOriginal();
    }
}