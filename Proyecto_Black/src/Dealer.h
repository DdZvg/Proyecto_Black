#pragma once
#ifndef DEALER_H
#define DEALER_H
#include "Participante.h"

class Dealer : public Participante{
private:
	bool cartaOcultaRevelada = false;//indica si la carta oculta del dealer ya fue revelada

public:
	Dealer();
	bool debePedirCarta() const;//devuelve verdadero si la mano del dealer tiene menos de 17 puntos

	Carta getCartaVisible() const;
	void revelarCartaOculta();//revela la carta oculta del dealer, para mostrarla al final de la ronda
	void mostrarMano() const;
	bool debeRevisarBlackjack() const;//devuelve verdadero si la carta visible es un As o un 10
	bool ofreceSeguro() const;//devuelve verdadero si la carta visible es un As
	

	
	void limpiarManos() override;
};

#endif




