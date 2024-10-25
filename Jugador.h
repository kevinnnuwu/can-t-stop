#ifndef JUGADOR_H
#define JUGADOR_H
#include <set>

class Jugador {
private:
    int id;
    int columnasCompletadas;
    std::set<int> columnasElegidas;

public:
    Jugador(int id);

    int getId() const;
    int getColumnasCompletadas() const;
    void incrementarColumnasCompletadas();
    
    void limpiarColumnasElegidas();
    bool agregarColumnaElegida(int columna);
};

#endif
