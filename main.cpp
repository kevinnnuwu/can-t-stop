#include "Juego.h" // Incluye el archivo de encabezado de la clase Juego, donde está su declaración.
#include <iostream> // Incluye la biblioteca estándar para la entrada y salida de datos.
using namespace std; // Permite usar elementos de la biblioteca estándar sin el prefijo std::.

int main() {
    int numJugadores; // Declara una variable para almacenar el número de jugadores.

    cout << "Ingrese la cantidad de jugadores (2-4): "; // Muestra un mensaje solicitando la cantidad de jugadores.
    cin >> numJugadores; // Lee el número ingresado por el usuario y lo almacena en numJugadores.

    while (numJugadores < 2 || numJugadores > 4) { // Verifica que el número esté dentro del rango permitido (2-4).
        cout << "Número inválido. Ingrese un número entre 2 y 4: "; // Mensaje de error si el número es inválido.
        cin >> numJugadores; // Solicita nuevamente el número de jugadores.
    }

    Juego juego(numJugadores); // Crea un objeto Juego llamado juego, inicializándolo con el número de jugadores especificado.
    juego.jugar(); // Llama al método jugar() del objeto juego para comenzar la partida.

    return 0; // Finaliza la ejecución del programa devolviendo 0, indicando que se ejecutó sin errores.
}
