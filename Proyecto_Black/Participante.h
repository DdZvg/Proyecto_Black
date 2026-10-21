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
	const Mano& getMano() const; // Corregido: 'const Mano&'
	bool estaBusted() const;
	void recibirCarta(const Carta& c); // Corregido: 'const Carta&'


};

#endif
