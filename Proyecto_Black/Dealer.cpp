#include "Dealer.h"

using namespace std;

Dealer::Dealer() : Participante("Dealer") {

}

// El dealer pide carta mientras tenga menos de 17 puntos
bool Dealer::debePedirCarta() const {
	return getMano(0).calcularPuntos() < 17;
}

//la carta visible es la segunda que recibe dealer
Carta Dealer::getCartaVisible() const {
	vector<Carta> cartas = getMano(0).getCartas();
	return cartas[1];   // el juego debe repartir 2 cartas antes de llamarlo
}

// Revela la carta oculta del dealer, para mostrarla al final de la ronda
void Dealer::revelarCartaOculta() {
	cartaOcultaRevelada = true;
}

// Muestra la mano ocultando la primera carta hasta que se revele
void Dealer::mostrarMano() const {
	getMano(0).mostrarMano(!cartaOcultaRevelada);
}

// Devuelve verdadero si la carta visible es un As o un 10
bool Dealer::ofreceSeguro() const {
	if (getMano(0).getCartas().size() < 2) return false;
	return getCartaVisible().getValor() == "A";//solo se ofrece seguro si la carta visible es un As
}
// Devuelve verdadero si la carta visible es un As o un 10, para revisar blackjack
bool Dealer::debeRevisarBlackjack() const {//si no hay 2 cartas, no se puede revisar blackjack
	if (getMano(0).getCartas().size() < 2) {
		return false;
	}
	Carta visible = getCartaVisible();//la carta visible es la segunda que recibe dealer
	return visible.getValor() == "A" || visible.getPuntos() == 10;//si la carta visible es un As o un 10, se revisa blackjack
}

// Sobrescribe la mano de participante, además de vaciar las manos y reiniciar la carta oculta
void Dealer::limpiarManos() {
	Participante::limpiarManos();
	cartaOcultaRevelada = false;
}




