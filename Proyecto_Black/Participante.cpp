#include "Participante.h"

using namespace std;

Participante::Participante(string nombre) {
	this->nombre = nombre;
	this->manos.push_back(Mano());
}

//getters
string Participante:: getNombre() const {
	return this->nombre;
}

int Participante::getNumManos() const {
	return static_cast<int>(this->manos.size());
}

// CORRECCIÓN AQUÍ: Se agrega 'const' antes de Mano&
const Mano& Participante::getMano(int indice) const {
	return this->manos.at(indice);

}

bool Participante:: estaBusted(int indice) const {
	return this->manos.at(indice).calcularPuntos() > 21;

}

void Participante::recibirCarta(const Carta& c, int indice) {
	this->manos.at(indice).agregarCarta(c);
}

bool Participante::tieneBlackjack(int indice) const {
	if (this->manos.size() != 1 || indice != 0) {
		return false;
	}
	const Mano& m = this->manos[0];
	return m.getCartas().size() == 2 && m.calcularPuntos() == 21;
}

void Participante::limpiarManos() {
	this->manos.clear();
	this->manos.push_back(Mano());
}