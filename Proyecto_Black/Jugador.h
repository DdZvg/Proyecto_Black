#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H
#include "Participante.h"
#include <vector>
using namespace std;

class Jugador:public Participante{
private:
	int fichas;
	std::vector<int> apuestas;
	int apuestaSeguro;

public:
	Jugador(string nombre, int fichas);

	//metodos apuesta 
	bool hacerApuesta(int cantidad);
	void ganarApuesta(int indice=0);
	void ganarBlackjack(int indice);//paga 3:2
	void empatarApuesta(int indice =0);
	void perderApuesta(int indice=0);
	bool doblarApuesta(int indice=0);//valida 2 cartas

	//acciones
	bool puedeDoblar(int indice = 0)const;
	bool puedeDividir()const;
	bool dividir();

	//seguro
	int getMaxSeguro() const;//mitad de la apuesta original
	bool hacerSeguro(int cantidad);
	void resolverSeguro(bool dealerTieneBlackjack);//se paga 2:1 o se pierde

	//getters
	int getFichas() const;
	int getApuestaActual(int indice=0) const;

	void limpiarManos() override;//limpia apuesta y seguro

};

#endif


