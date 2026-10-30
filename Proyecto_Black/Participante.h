	#pragma once
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>
#include <vector>
#include "Mano.h"

class Participante{
protected:
	string nombre;
	vector<Mano> manos;//manos del participante, 1 al inicio, 2 si se divide

public:

	Participante(const std::string& nombre);//crea el participante con su mano vacia

	virtual ~Participante() = default;//

	string getNombre() const;
	const Mano& getMano(int indice) const; //devuelve la mano en la posicion indice sin copiarla, no se modifica desde afuera
	void recibirCarta(const Carta& c, int indice); // Corregido: 'const Carta&' - Agrega la carta c a la mano indice
	bool estaBusted(int indice = 0) const;//es verdadero si la mano indice se paso de 21 puntos

	int getNumManos() const; //cantidad de manos que tiene, 1 o 2 despues de dividir

	bool tieneBlackjack() const; //es verdadero si la mano indice es un blackjack

	//deja al participante con una sola mano vacia al terminar la ronda
	virtual void limpiarManos(); 

};

#endif

