#include "Jugador.h"
using namespace std;

//contructor
Jugador::Jugador(string nombre, int fichas):Participante(nombre), fichas(fichas), apuestas(1, 0), apuestaSeguro(0) {
}

//Metodos de Apuesta
bool Jugador::hacerApuesta(int cantidad) {
	if (cantidad <= 0 || cantidad > fichas || apuestas[0] > 0) return false;
	fichas -= cantidad;
	apuestas[0] = cantidad;
	return true;
}
	//el jugador gana (1:1)
	void Jugador::ganarApuesta(int indice){
		if (indice < 0 || indice >= static_cast<int>(apuestas.size())) return;
		fichas += apuestas[indice] * 2;
	apuestas[indice] = 0;
	}

	//el jugador gana con blackjack (3:2). La division entera redondea hacia abajo.
	void Jugador::ganarBlackjack(int indice) {
		if (indice < 0 || indice >= static_cast<int>(apuestas.size())) return;
		int apuesta = apuestas[indice];
		fichas += apuesta + (apuesta * 3) / 2;
	apuestas[indice] = 0;
	}
	//el jugador pierde
	void Jugador::perderApuesta(int indice) {
		if (indice >= 0 && indice < static_cast<int>(apuestas.size())) apuestas[indice] = 0;
	}
	//el jugador empata
	void Jugador::empatarApuesta(int indice) {
		if (indice < 0 || indice >= static_cast<int>(apuestas.size())) return;
		fichas += apuestas[indice];
	apuestas[indice] = 0;
	}

	// Solo con las dos primeras cartas
	bool Jugador::puedeDoblar(int indice) const {
		return indice >= 0 && indice < getNumMano() && indice < static_cast<int>(apuestas.size())
		&& getMano(indice).getCartas().size() == 2 && apuestas[indice] > 0
		&& apuestas[indice] <= fichas;
	}


	// Dobla la apuesta actual (descuenta otra vez la misma cantidad)
	bool Jugador::doblarApuesta(int indice) {
		if (!puedeDoblar(indice)) return false;
		fichas -= apuestas[indice];
		apuestas[indice] *= 2;
		return true;
	}

	// Una sola division, solo con las 2 primeras cartas y del mismo VALOR (K y 10 sirven)
	bool Jugador::puedeDividir() const {
		if (getNumMano() != 1 || apuestas.empty() || apuestas[0] <= 0) return false;
		vector<Carta> cartas = getMano(0).getCartas();
		return cartas.size() == 2 && cartas[0].getPuntos() == cartas[1].getPuntos()
		&& apuestas[0] <= fichas;
	}

	// Crea la segunda mano y la segunda apuesta. Luego el juego reparte una carta a cada mano.
	bool Jugador::dividir() {
		if (!puedeDividir()) return false;
		fichas -= apuestas[0];
		apuestas.push_back(apuestas[0]);
		Carta segunda = manos[0].quitarUltimaCarta();
		manos.push_back(Mano());
		manos[0].marcarDeDivision();
		manos[1].marcarDeDivision();
		manos[1].agregarCarta(segunda);
		return true;
	}

	// Seguro,hasta la mitad de la apuesta original
	int Jugador::getMaxSeguro() const {
		return apuestas.empty() ? 0 : apuestas[0] / 2;
	}

	bool Jugador::hacerSeguro(int cantidad) {
		if (apuestaSeguro != 0 || cantidad <= 0 || cantidad > getMaxSeguro() || cantidad > fichas) return false;
		fichas -= cantidad;
		apuestaSeguro = cantidad;
		return true;
	}

	void Jugador::resolverSeguro(bool dealerTieneBlackjack) {
		if (dealerTieneBlackjack) fichas += apuestaSeguro * 3;
		apuestaSeguro = 0;
	}

	//getters
	int Jugador::getFichas() const { return fichas; }

int Jugador::getApuestaActual(int indice) const {
	return indice >= 0 && indice < static_cast<int>(apuestas.size()) ? apuestas[indice] : 0;
}

	void Jugador::limpiarManos() {
		Participante::limpiarManos();
		apuestas.assign(1, 0);
		apuestaSeguro = 0;
	}




