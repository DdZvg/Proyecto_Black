#include "Participante.h"

using namespace std;

Participante::Participante(const string& nombre) 
{
	this->nombre = nombre;
	this->manos.push_back(Mano());
}

//getters
string Participante:: getNombre() const {
	return this->nombre;
}

int Participante::getNumMano() const {
	return static_cast<int>(this->manos.size());
}

// CORRECCIÓN AQUÍ: Se agrega 'const' antes de Mano&
const Mano& Participante::getMano(int indice) const {
	return this->manos.at(indice);

}

bool Participante::estaBusted(int indice) const {
	if (indice < 0 || indice >= getNumMano()) {// Verificar si el índice es válido
		return false;
	}

	return this->manos.at(indice).calcularPuntos() > 21;// Verificar si la mano está "busted" (puntos > 21)
}

void Participante::recibirCarta(const Carta& c, int indice) {
	if (indice < 0 || indice >= getNumMano()) {
		return;
	}

	this->manos.at(indice).agregarCarta(c);
}


bool Participante::tieneBlackjack(int indice) const {
	if (indice < 0 || indice >= getNumMano()) {
		return false;
	}

	
	const Mano& m = this->manos.at(indice);

	return m.getCartas().size() == 2 &&
		m.calcularPuntos() == 21;
}

void Participante::limpiarManos() {
	this->manos.clear();
	this->manos.push_back(Mano());
}