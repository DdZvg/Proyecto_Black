#include "Jugador.h"
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

	// Solo se puede apostar una vez por ronda
	if (this->apuestaActual > 0) {
		return false;
	}

	
		this->fichas = this->fichas - cantidad;
		this->apuestaActual = cantidad;
		return true;
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


	// Dobla la apuesta actual (descuenta otra vez la misma cantidad)
	bool Jugador::doblarApuesta() {
		// Debe haber una apuesta en curso
		if (this->apuestaActual <= 0) {
			return false;
		}

		// Debe tener fichas suficientes para igualar la apuesta
		if (this->apuestaActual > this->fichas) {
			return false;
		}

		this->fichas = this->fichas - this->apuestaActual;
		this->apuestaActual = this->apuestaActual * 2;
		return true;
	}

	//getters
	int Jugador::getFichas() const {
		return this->fichas;
	}

	int Jugador::getApuestaActual() const {
		return this->apuestaActual;
	}





