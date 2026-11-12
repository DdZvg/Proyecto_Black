#include "Mano.h"
#include "Consola.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Mano::Mano() : apuesta(0), apuestaSeguro(0), esDeDivision(false), resultado(ResultadoMano::Pendiente) {}

void Mano::agregarCarta(Carta c) {
	cartas.push_back(c);
}


Carta Mano::quitarUltimaCarta() {
	Carta carta = cartas.back();// Obtiene la última carta de la mano
	cartas.pop_back();// Elimina la última carta de la mano
	return carta;
}


void Mano::marcarDeDivision() {
	esDeDivision = true;
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

// Un blackjack natural solo es posible con las dos primeras cartas de una mano sin dividir
bool Mano::tieneBlackjack() const {
	return !esDeDivision && cartas.size() == 2 && calcularPuntos() == 21;
}

bool Mano::estaBusted() const {
	return calcularPuntos() > 21;
}

// Solo se puede dividir un par con la apuesta colocada y sin haber dividido antes
bool Mano::puedeDividir() const {
	return !esDeDivision && apuesta > 0 && cartas.size() == 2
		&& cartas[0].getPuntos() == cartas[1].getPuntos();
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
	apuesta = 0;
	apuestaSeguro = 0;
	esDeDivision = false;
	resultado = ResultadoMano::Pendiente;
}

vector<Carta> Mano::getCartas() const {
	return cartas; // Retorna el vector de cartas
}

// Apuestas de la mano

bool Mano::apostar(int cantidad) {
	if (cantidad <= 0 || apuesta != 0) return false;
	apuesta = cantidad;
	return true;
}

int Mano::getApuesta() const {
	return apuesta;
}

bool Mano::doblarApuesta() {
	if (cartas.size() != 2 || apuesta <= 0) return false;
	apuesta *= 2;
	return true;
}

void Mano::ganarApuesta() {
	resultado = ResultadoMano::Gana;
}

void Mano::ganarBlackjack() {
	resultado = ResultadoMano::BlackJack;
}

void Mano::empatarApuesta() {
	resultado = ResultadoMano::Empata;
}

void Mano::perderApuesta() {
	resultado = ResultadoMano::Pierde;
}

// Seguro de la mano

int Mano::getMaxSeguro() const {
	return apuesta / 2;
}

bool Mano::hacerSeguro(int cantidad) {
	if (apuestaSeguro != 0 || cantidad <= 0 || cantidad > getMaxSeguro()) return false;
	apuestaSeguro = cantidad;
	return true;
}

void Mano::resolverSeguro(bool dealerTieneBlackjack) {
	if (!dealerTieneBlackjack) {
		apuestaSeguro = 0;// el seguro se pierde
	}
	else {
		apuestaSeguro *= 3;// se cobra la apuesta del seguro + el pago 2:1
	}
}

int Mano::getApuestaSeguro() const {
	return apuestaSeguro;
}

ResultadoMano Mano::getResultado() const {
	return resultado;
}