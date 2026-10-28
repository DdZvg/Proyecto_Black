#include "Mano.h"
#include "consola.h"
#include <iostream>

using namespace std;

Mano::Mano() {}

void Mano::agregarCarta(Carta c) {
	cartas.push_back(c);
}

int Mano::calcularPuntos() const {
	int total = 0; // Suma de puntos de todas las cartas

	int numAses = 0;// Contador de ases para ajustar su valor si es necesario
	for (const Carta& carta : cartas) {
		total += carta.getPuntos();// Suma los puntos de la carta actual
		if (carta.getValor() == "A") {// Si la carta es un As, incrementa el contador de ases
			numAses++;// Incrementa el contador de ases
		}
	}
	// Ajuste de puntos para ases si el total excede 21
	while (total > 21 && numAses > 0) {
		total -= 10; // Cambia un As de 11 a 1
		numAses--;
	}
	return total;
}

	void Mano::mostrarMano(bool ocultarPrimera, int y) const {
		const int ANCHO_CARTA = 12;/// Ancho de cada carta en caracteres
			const int X_INICIAL = 5;/// Posición X inicial para dibujar la primera carta

		for (size_t i = 0; i < cartas.size(); ++i) {
			Carta carta = cartas[i];

			// Si se solicita ocultar la primera carta y estamos en la primera iteración, se marca como oculta
			if (ocultarPrimera && i == 0) {
				carta.setOculta(true);
			}
			int posX = X_INICIAL + static_cast<int>(i) * ANCHO_CARTA; // Calcula la posición X para la carta actual
			int posY = y;// Posición Y para dibujar la carta (constante para todas las cartas)

			//se utiliza metodo de carta.h 
			carta.dibujarBloque(posX, posY);// Dibuja la carta en la consola

		}// Fin del bucle que recorre todas las cartas de la mano

		//se utiliza la funcion de consola.h
		Consola::moverCursor(1, y + 5); // Mueve el cursor a la siguiente línea después de dibujar la carta)
	}


	void Mano::limpiarMano() {
		cartas.clear(); // Elimina todas las cartas de la mano
	}

	vector<Carta> Mano::getCartas() const {
		return cartas; // Retorna el vector de cartas
	}

