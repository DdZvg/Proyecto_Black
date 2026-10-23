#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H
#include "Participante.h"
using namespace std;

class Jugador:public Participante{
private:
	int fichas;
	int apuestaActual;

public:
	Jugador(string nombre, int fichas);

	//metodos apuesta 
	bool hacerApuesta(int cantidad);
	void ganarApuesta();
	void empatarApuesta();
	void perderApuesta();
	bool doblarApuesta();

	//getters
	int getFichas() const;
	int getApuestaActual() const;

};

#endif
