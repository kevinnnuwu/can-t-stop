#include "Juego.h"
#include <iostream>
using namespace std;

int main() {
    int numJugadores;

    cout << "Ingrese la cantidad de jugadores (2-4): ";
    cin >> numJugadores;

    while (numJugadores < 2 || numJugadores > 4) {
        cout << "Número inválido. Ingrese un número entre 2 y 4: ";
        cin >> numJugadores;
    }

    Juego juego(numJugadores);
    juego.jugar();

    return 0;
}