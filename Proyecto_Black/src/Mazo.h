#pragma once
#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo {
private:
    vector<Carta> cartas;

public:
    // numMazos = 1 -> baraja normal (52); numMazos = 6 -> zapato (312)
    Mazo(int numMazos = 1);
    void inicializarMazo(int numMazos = 1);
    void mezclar();
    Carta tomarCarta();
    int cartasRestantes() const;
};
#endif 