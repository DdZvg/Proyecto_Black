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

void Dealer::revelarCartaOculta() {
	cartaOcultaRevelada = true;
}

// Muestra la mano ocultando la primera carta hasta que se revele
void Dealer::mostrarMano() const {
	getMano(0).mostrarMano(!cartaOcultaRevelada);
}

bool Dealer::ofreceSeguro() const {
	if (getMano(0).getCartas().size() < 2) return false;
	return getCartaVisible().getValor() == "A";
}

bool Dealer::ofrecerSeguro() const {
return ofreceSeguro();
}

bool Dealer::debeRevisarBlackjack() const {
	if (getMano(0).getCartas().size() < 2) {
		return false;
	}
	Carta visible = getCartaVisible();
	return visible.getValor() == "A" || visible.getPuntos() == 10;
}

void Dealer::limpiarManos() {
	Participante::limpiarManos();
	cartaOcultaRevelada = false;
}




