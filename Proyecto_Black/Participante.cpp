#include "Participante.h"

using namespace std;

Participante::Participante(const string& nombre) //guarda el nombre y crea la primera mano
{
	this->nombre = nombre;
	this->manos.push_back(Mano());
}

//getters

string Participante:: getNombre() const {
	return this->nombre;
}

//cuantas manos tiene el participante en este momento
int Participante::getNumManos() const {
	return static_cast<int>(this->manos.size());//
}

// CORRECCIÓN AQUÍ: Se agrega 'const' antes de Mano&
// Devuelve una referencia constante a la mano pedida.
// at() revisa el indice: si esta fuera de rango lanza una excepcion en lugar de leer memoria invalida.
const Mano& Participante::getMano(int indice) const {
	return this->manos.at(indice);

}

//sirve para saber si la mano se paso de 21, si el indice no existe devuelve falso
bool Participante::estaBusted(int indice) const {
	if (indice < 0 || indice >= getNumManos()) {// Verificar si el índice es válido
		return false;
	}

	return this->manos.at(indice).calcularPuntos() > 21;// Verificar si la mano está "busted" (puntos > 21)
}

//agrega una carta a la mano indicada
void Participante::recibirCarta(const Carta& c, int indice) {
	if (indice < 0 || indice >= getNumManos()) { // si el indice es invalido no se hace nada,para eviatar errores
		return;
	}

	this->manos.at(indice).agregarCarta(c);
}

//una mano es blackjack si tiene exactamente 2 cartas y suman 21
bool Participante::tieneBlackjack() const {
	if (getNumManos() != 1) {
		return false;
	}

	const Mano& m = manos.at(0);

	return m.getCartas().size() == 2 &&
		m.calcularPuntos() == 21;
}

//prepara el participante para la egunda ronda, borrando todas las manos
void Participante::limpiarManos() {
	this->manos.clear();
	this->manos.push_back(Mano());
}