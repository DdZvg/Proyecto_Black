#pragma once

#include "Participante.h"
#include "ResultadoMano.h"
#include <vector>
using namespace std;

class Jugador : public Participante {
private:
	int fichas;//saldo disponible (se conserva para poder validar las apuestas)

public:
	//crea el jugador con su nombre y su saldo de fichas
	explicit Jugador(const string& nombre, int fichas = 1000);

	//apuesta inicial de la ronda; descuenta las fichas y se la asigna a la mano
	bool hacerApuesta(int cantidad);

	//se permite dividir si hay una sola mano, es un par y hay fichas suficientes
	bool puedeDividir(int indice = 0) const;

	//separa el par en dos manos
	bool dividir();

	//devuelve el resultado de la mano indicada
	ResultadoMano recibirResultado(int indice = 0) const;

	//consultas
	int getFichas() const;

	//limpia las manos para la nueva ronda
	void limpiarManos() override;
};
