#include "Jugador.h"
#include <iostream>
using namespace std;

//contructor
Jugador::Jugador(string nombre, int fichas):Participante(nombre){
	this->fichas = fichas;
	this->apuestaActual = 0;
}

//Metodos de Apuesta

bool Jugador::hacerApuesta(int cantidad) {
	if (cantidad <= 0) {
		return false;
	}

	if (cantidad > this->fichas) {
		return false;
	}

	if (this->apuestaActual > 0) {
		return false;
	}

	if (cantidad > 0 && cantidad <= this->fichas && this->apuestaActual == 0) {
		this->fichas = this->fichas - cantidad;
		this->apuestaActual = cantidad;
		return true;
	}
	return false;
}
	//el jugador gana 
	void Jugador::ganarApuesta(){
		this->fichas = this->fichas + (this->apuestaActual*2);
		this->apuestaActual = 0;
	}
	//el jugador pierde
	void Jugador::perderApuesta() {
		this->apuestaActual = 0;
	}
	//el jugador empata
	void Jugador::empatarApuesta() {
		this->fichas = this->fichas + this->apuestaActual;
		this->apuestaActual = 0;
	}

	//getters
	int Jugador::getFichas() const {
		return this->fichas;
	}

	int Jugador::getApuestaActual() const {
		return this->apuestaActual;
	}





