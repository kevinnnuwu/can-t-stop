#include "Juego.h" // Incluye el archivo de encabezado de la clase Juego, donde está su declaración.
#include <iostream> // Incluye la biblioteca estándar para la entrada y salida de datos.

Juego::Juego(int numJugadores) : jugadorActual(0), juegoTerminado(false) {
    // Inicializa el juego con el jugador actual en 0 y el estado juegoTerminado como false.
    for (int i = 1; i <= numJugadores; i++) {
        jugadores.emplace_back(i); // Agrega un nuevo jugador al vector jugadores, asignándole el ID correspondiente.
    }
}

void Juego::jugar() {
    while (!juegoTerminado) { // Bucle que se ejecuta mientras el juego no haya terminado.
        tablero.mostrar(); // Muestra el estado actual del tablero.
        realizarTurno(); // Llama a realizarTurno() para ejecutar el turno del jugador actual.

        if (!juegoTerminado) { 
            jugadorActual = (jugadorActual + 1) % jugadores.size(); 
            // Pasa al siguiente jugador (uso de % asegura que se mantenga dentro del rango de jugadores).
        }
    }
}

void Juego::realizarTurno() {
    Jugador& jugadorActivo = jugadores[jugadorActual]; // Referencia al jugador actual.
    jugadorActivo.limpiarColumnasElegidas(); // Limpia las columnas elegidas en este turno.
    bool turnoTerminado = false; // Variable para controlar la duración del turno actual.

    while (!turnoTerminado) { // Bucle que continúa mientras el turno esté activo.
        std::vector<int> dados = dado.lanzar4Dados(); // Lanza cuatro dados y guarda los resultados.
        auto eleccion = elegirCombinacion(dados); // Llama a elegirCombinacion para seleccionar dos combinaciones de dados.

        if (!jugadorActivo.agregarColumnaElegida(eleccion.first) || 
            !jugadorActivo.agregarColumnaElegida(eleccion.second)) {
            // Verifica que el jugador no elija más de 3 columnas distintas; si lo hace, pierde el turno.
            std::cout << "Has elegido más de 3 columnas distintas, ¡pierdes el turno!" << std::endl;
            turnoTerminado = true; // Termina el turno.
            break;
        }

        bool col1Completada = tablero.moverJugador(jugadorActivo.getId(), eleccion.first); 
        bool col2Completada = tablero.moverJugador(jugadorActivo.getId(), eleccion.second); 
        // Mueve al jugador en el tablero según las columnas elegidas.

        tablero.mostrar(); // Muestra el estado actual del tablero tras el movimiento.

        if (col1Completada) {
            jugadorActivo.incrementarColumnasCompletadas(); 
            std::cout << "¡Jugador " << jugadorActivo.getId() << " ha completado la columna " 
                      << eleccion.first << "!" << std::endl;
        }
        if (col2Completada) {
            jugadorActivo.incrementarColumnasCompletadas();
            std::cout << "¡Jugador " << jugadorActivo.getId() << " ha completado la columna " 
                      << eleccion.second << "!" << std::endl;
        }

        if (jugadorActivo.getColumnasCompletadas() >= 3) { 
            std::cout << "¡Jugador " << jugadorActivo.getId() 
                      << " ha completado 3 columnas y gana el juego!" << std::endl;
            juegoTerminado = true; // Indica que el juego ha terminado si el jugador completó 3 columnas.
            break;
        }

        turnoTerminado = !deseaContinuar(); // Pregunta si el jugador quiere seguir lanzando los dados.
    }

    tablero.finalizarTurno(jugadorActivo.getId()); // Finaliza el turno del jugador en el tablero.
}

std::pair<int, int> Juego::elegirCombinacion(const std::vector<int>& dados) { 
    std::set<std::pair<int, int>> combinacionesUnicas; // Usamos un set para evitar combinaciones duplicadas.

    // Genera todas las combinaciones posibles de pares de sumas sin repetir.
    combinacionesUnicas.insert(std::make_pair(dados[0] + dados[1], dados[2] + dados[3]));
    combinacionesUnicas.insert(std::make_pair(dados[0] + dados[2], dados[1] + dados[3]));
    combinacionesUnicas.insert(std::make_pair(dados[0] + dados[3], dados[1] + dados[2]));

    // Muestra todas las combinaciones posibles y únicas.
    int opcion = 1;
    std::cout << "Opciones de columnas para avanzar (elige una combinación):" << std::endl;
    for (const auto& combinacion : combinacionesUnicas) {
        std::cout << opcion << ". (" << combinacion.first << ") y (" << combinacion.second << ")" << std::endl;
        opcion++;
    }

    // El jugador elige una opción de las generadas.
    int eleccion;
    std::cout << "Elige una combinación (1-" << combinacionesUnicas.size() << "): ";
    std::cin >> eleccion;

    // Valida la elección del jugador.
    if (eleccion < 1 || eleccion > combinacionesUnicas.size()) {
        std::cout << "Opción inválida, eligiendo la opción por defecto (1)." << std::endl;
        eleccion = 1; // Selecciona la opción por defecto si la elección es inválida.
    }

    // Obtiene la combinación elegida según la opción ingresada.
    auto it = combinacionesUnicas.begin();
    std::advance(it, eleccion - 1); // Avanza el iterador a la opción seleccionada.

    return *it; // Devuelve la combinación seleccionada.
}

bool Juego::deseaContinuar() {
    char respuesta;
    std::cout << "¿Deseas continuar lanzando los dados? (s/n): ";
    std::cin >> respuesta;
    return respuesta == 's' || respuesta == 'S'; // Devuelve true si el jugador quiere continuar.
}
