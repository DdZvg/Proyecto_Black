#include "Dealer.h"

using namespace std;

Dealer::Dealer() : Participante("Dealer") {

}

// El dealer pide carta mientras tenga menos de 17 puntos
bool Dealer::debePedirCarta() const {
	return this->mano.calcularPuntos() < 17;
}