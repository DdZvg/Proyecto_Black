#pragma once

#include "Participante.h"
#include "ResultadoMano.h"
#include <string>

using namespace std;

class Jugador : public Participante {
public:
	//crea el jugador con su nombre; el saldo de fichas lo administra BlackJackGame
	explicit Jugador(const string& nombre);

	//apuesta inicial de la ronda; delega en Mano::apostar
	bool hacerApuesta(int cantidad);

	//se permite dividir si hay una sola mano y es un par
	bool puedeDividir(int indice = 0) const;

	//separa el par en dos manos
	bool dividir();

	//devuelve el resultado de la mano indicada
	ResultadoMano recibirResultado(int indice = 0) const;

	//limpia las manos para la nueva ronda
	void limpiarManos() override;
};