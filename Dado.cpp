#include "Dado.h" // Incluye el archivo de encabezado de la clase Dado, donde se declara la clase.
#include <cstdlib> // Incluye la biblioteca para la generación de números aleatorios.
#include <ctime> // Incluye la biblioteca para manejar el tiempo (para la semilla de aleatoriedad).
#include <iostream> // Incluye la biblioteca para la entrada y salida de datos.

Dado::Dado() {
    srand(time(0));  // Inicializa la semilla para números aleatorios usando la hora actual.
}

int Dado::lanzar() {
    return rand() % 6 + 1;  // Genera un número aleatorio entre 1 y 6, simulando el lanzamiento de un dado.
}

std::vector<int> Dado::lanzar4Dados() {
    int dado1 = lanzar(); // Lanza el primer dado y guarda el resultado.
    int dado2 = lanzar(); // Lanza el segundo dado y guarda el resultado.
    int dado3 = lanzar(); // Lanza el tercer dado y guarda el resultado.
    int dado4 = lanzar(); // Lanza el cuarto dado y guarda el resultado.
    
    std::vector<int> resultados = {dado1, dado2, dado3, dado4}; // Almacena los resultados de los cuatro dados en un vector.

    std::cout << "Lanzamiento de dados: " << std::endl; // Muestra un mensaje indicando el lanzamiento de los dados.
    std::cout << "Dado1 = " << dado1 << ", Dado2 = " << dado2 
              << ", Dado3 = " << dado3 << ", Dado4 = " << dado4 << std::endl;
    // Muestra el resultado de cada dado lanzado.
    
    return resultados; // Devuelve el vector con los resultados de los cuatro dados.
}
