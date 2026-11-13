#include "Jugador.h"
using namespace std;

//Contructor
Jugador::Jugador(const string& nombre) : Participante(nombre) {
}

// La apuesta se registra directamente en la mano (Mano es duena de ese estado).
bool Jugador::hacerApuesta(int cantidad) {
	return getMano(0).apostar(cantidad);
}

// Una sola division, solo con las 2 primeras cartas del mismo VALOR (K y 10 sirven).
// El saldo de fichas lo valida BlackJackGame antes de ofrecer la division.
bool Jugador::puedeDividir(int indice) const {
	if (indice < 0 || indice >= getNumManos()) return false;
	if (getNumManos() != 1) return false;

	return getMano(indice).puedeDividir();
}

// Crea la segunda mano con la misma apuesta. Luego el juego reparte una carta a cada mano.
bool Jugador::dividir() {
	if (!puedeDividir(0)) return false;

	int apuestaOriginal = getMano(0).getApuesta();
	Carta segunda = getMano(0).quitarUltimaCarta();

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

//prepara al jugador para la siguiente ronda, borrando todas las manos
void Jugador::limpiarManos() {
	Participante::limpiarManos();
}
