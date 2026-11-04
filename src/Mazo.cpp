
#include "Mazo.h"
#include <algorithm>
#include <random>
#include <string>

using namespace std;

Mazo::Mazo(int numMazos) {
    inicializarMazo(numMazos);
    mezclar();
}

// 52 cartas (6 mazos = 312 cartas)
void Mazo::inicializarMazo(int numMazos) {

    cartas.clear();

    // numero de mazos es menor que 1, se establece en 1
    if (numMazos < 1) numMazos = 1;

    // guardar la cantidad de mazos
    this->numMazos = numMazos;

    cartas.reserve(52 * this->numMazos);

    string palos[4] = {
        "Corazones", "Diamantes",
        "Treboles", "Picas"
    };

    string valores[13] = {
        "A", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "J", "Q", "K"
    };
	// agregar valores de cada carta
    for (int m = 0; m < this->numMazos; m++) {
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
                    puntos, false
                );

                cartas.push_back(nuevaCarta);
            }
        }
    }
}

// mezclar cartas
void Mazo::mezclar() {

    random_device rd;
    mt19937 generador(rd());

    shuffle(cartas.begin(),
        cartas.end(),
        generador);
}

// sacar carta
Carta Mazo::tomarCarta() {

    Carta carta = cartas.back();

    cartas.pop_back();

    return carta;
}

// cartas restantes
int Mazo::cartasRestantes() const {

    return static_cast<int>(cartas.size());
}
