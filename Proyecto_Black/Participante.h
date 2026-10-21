#pragma once
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include "Mano.h"
using namespace std;
class Participante{
protected:
	string nombre;
	Mano mano;

public:
	Participante(const string nombre);

	string getNombre() const;
	Mano& getMano() const;
	void recibirCarta(Carta& c);
	bool estaBusted() const;


};

#endif
