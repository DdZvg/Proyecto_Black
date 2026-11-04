#pragma once

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo {
private:
    vector<Carta> cartas;
    int numMazos;

public:
    Mazo(int numMazos = 1);

    void inicializarMazo(int numMazos = 1);
    void mezclar();
    Carta tomarCarta();
    int cartasRestantes() const;
};

