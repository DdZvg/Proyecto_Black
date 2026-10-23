#pragma once

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo {
private:
    vector<Carta> cartas;

public:
    Mazo();

    void inicializarMazo();
    void mezclar();
    Carta tomarCarta();
    int cartasRestantes() const;
};