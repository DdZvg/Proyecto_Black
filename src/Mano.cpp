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
	const int ANCHO_MESA = 78;
	const int ANCHO_CARTA = 12;
	const int X_INICIAL = 5;

	const int cartasVisibles =
		(ANCHO_MESA - X_INICIAL) / ANCHO_CARTA;

	const int limite = static_cast<int>(cartas.size()) < cartasVisibles
		? static_cast<int>(cartas.size())
		: cartasVisibles;

	for (int i = 0; i < limite; ++i) {
		Carta carta = cartas[static_cast<size_t>(i)];

		if (ocultarPrimera && i == 0) {
			carta.setOculta(true);
		}

		const int posX = X_INICIAL + i * ANCHO_CARTA;
		carta.dibujarBloque(posX, y);
	}

	const int restantes = static_cast<int>(cartas.size()) - limite;

	if (restantes > 0) {
		Consola::escribirEn(
			X_INICIAL,
			y + 5,
			"+" + to_string(restantes) + " cartas"
		);
	}

	Consola::moverCursor(1, y + 5);
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