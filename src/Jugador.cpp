#include "Jugador.h"
using namespace std;

//Contructor
Jugador::Jugador(const string& nombre, int fichas) : Participante(nombre), fichas(fichas) {
}

//Metodos de Apuesta

// Descuenta las fichas de la apuesta inicial y la registra en la primera mano
bool Jugador::hacerApuesta(int cantidad) {
	if (cantidad <= 0 || cantidad > fichas) return false;

	Mano& mano = getMano(0);
	if (!mano.apostar(cantidad)) return false;

	fichas -= cantidad;
	return true;
}

// Una sola division, solo con las 2 primeras cartas del mismo VALOR (K y 10 sirven)
bool Jugador::puedeDividir(int indice) const {
	if (indice < 0 || indice >= getNumManos()) return false;
	if (getNumManos() != 1) return false;

	const Mano& mano = getMano(indice);
	return mano.puedeDividir() && fichas >= mano.getApuesta();
}

// Crea la segunda mano con la misma apuesta. Luego el juego reparte una carta a cada mano.
bool Jugador::dividir() {
	if (!puedeDividir(0)) return false;

	int apuestaOriginal = getMano(0).getApuesta();
	Carta segunda = getMano(0).quitarUltimaCarta();

	fichas -= apuestaOriginal;//descuenta la segunda apuesta

	getMano(0).marcarDeDivision();
	manos.push_back(Mano());

	Mano& nuevaMano = manos.back();
	nuevaMano.apostar(apuestaOriginal);
	nuevaMano.marcarDeDivision();
	nuevaMano.agregarCarta(segunda);

	return true;
}

// Devuelve el resultado de la mano indicada
ResultadoMano Jugador::recibirResultado(int indice) const {
	if (indice < 0 || indice >= getNumManos()) return ResultadoMano::Pendiente;
	return getMano(indice).getResultado();
}

//Getters

int Jugador::getFichas() const { return fichas; }//devuelve la cantidad de fichas disponibles

//prepara al jugador para la siguiente ronda, borrando todas las manos
void Jugador::limpiarManos() {
	Participante::limpiarManos();
}
