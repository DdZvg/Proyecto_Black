#pragma once
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include "Mano.h"
using namespace std;
class Participante{
protected:
	string nombre;
	vector<Mano>manos;

public:
	Participante(const string nombre);

	string getNombre() const;
	const Mano& getMano(int indice) const; 
	bool estaBusted(int indice = 0) const; 
	void recibirCarta(const Carta& c, int indice = 0); // Corregido: 'const Carta&' and added indice parameter

	int getNumManos() const; 

	bool tieneBlackjack(int indice = 0) const; 

	//deja la mano vacia al final de la ronda
	void limpiarManos(); 

};

#endif
