#include "Dado.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Dado::Dado() {
    srand(time(0));  // Inicializa la semilla para números aleatorios
}

int Dado::lanzar() {
    return rand() % 6 + 1;  // Genera un número entre 1 y 6
}

std::vector<int> Dado::lanzar4Dados() {
    int dado1 = lanzar();
    int dado2 = lanzar();
    int dado3 = lanzar();
    int dado4 = lanzar();
    
    std::vector<int> resultados = {dado1, dado2, dado3, dado4};

    std::cout << "Lanzamiento de dados: " << std::endl;
    std::cout << "Dado1 = " << dado1 << ", Dado2 = " << dado2 
              << ", Dado3 = " << dado3 << ", Dado4 = " << dado4 << std::endl;
    
    return resultados;
}