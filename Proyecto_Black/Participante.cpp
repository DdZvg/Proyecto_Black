#include <iostream>
#include "Participante.h"

using namespace std;

Participante::Participante(string nombre) {
	this->nombre = nombre;
}

//getters
string Participante:: getNombre() const {
	return this->nombre;
}

Mano& Participante:: getMano() const {
	return this->mano;
}


bool Participante:: estaBusted() const {
	return this->mano.calcularPuntos() > 21;

}

void Participante::recibirCarta(const Carta& c) {
	this->mano.agregarCarta(c);   
}

