#pragma once
#ifndef DEALER_H
#define DEALER_H
#include "Participante.h"

class Dealer : public Participante{
private:
	bool cartaOcultaRevelada = false;

public:
	Dealer();
	bool debePedirCarta() const;

	Carta getCartaVisible() const;
	void revelarCartaOculta();
	void mostrarMano() const;
	bool debeRevisarBlackjack() const;
	bool ofreceSeguro() const;
	


	void limpiarManos() override;
};

#endif




