	#pragma once
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>
#include <vector>
#include "Mano.h"

class Participante{
protected:
	std::string nombre;
	std::vector<Mano> manos;

public:
	Participante(const std::string& nombre);
	virtual ~Participante() = default;

	std::string getNombre() const;
	const Mano& getMano(int indice) const; 
	void recibirCarta(const Carta& c, int indice = 0); // Corregido: 'const Carta&'
	bool estaBusted(int indice = 0) const;

	int getNumMano() const; 

	bool tieneBlackjack(int indice = 0) const; 

	//deja la mano vacia al final de la ronda
	virtual void limpiarManos(); 

};

#endif

