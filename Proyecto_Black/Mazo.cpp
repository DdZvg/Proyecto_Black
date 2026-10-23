#include "Mazo.h"
#include <algorithm>
#include <random>
#include <string>

using namespace std;

Mazo::Mazo() {
    inicializarMazo();
    mezclar();
}

//las 52 cartas
void Mazo::inicializarMazo() {

    cartas.clear();

    string palos[4] = {
        "Corazones", "Diamantes",
        "Treboles", "Picas"
    };

    string valores[13] = {
        "A", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "J", "Q", "K"
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {

            int puntos;

            if (valores[j] == "A") {
                puntos = 11;
            }
            else if (valores[j] == "J" ||
                valores[j] == "Q" ||
                valores[j] == "K") {
                puntos = 10;
            }
            else {
                puntos = stoi(valores[j]);
            }

            Carta nuevaCarta(
                palos[i], valores[j],
                puntos, 0, 0, false
            );

            cartas.push_back(nuevaCarta);
        }
    }
}

// Mezclar cartas
void Mazo::mezclar() {

    random_device rd;
    mt19937 generador(rd());

    shuffle(cartas.begin(),
        cartas.end(),
        generador);
}

// Sacar carta
Carta Mazo::tomarCarta() {

    Carta carta = cartas.back();

    cartas.pop_back();

    return carta;
}

// Cantidad de cartas restantes
int Mazo::cartasRestantes() const {

    return cartas.size();
}