#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H
#include "Participante.h"
#include <vector>
using namespace std;

class Jugador:public Participante{
private:
	int fichas;//saldo disponible
	std::vector<int> apuestas;//una apuesta por mano
	int apuestaSeguro;//apuesta de seguro de la ronda

public:
	Jugador(string nombre, int fichas);//crea el jugador con su nombre y su saldo de fichas

	//metodos apuesta 
	bool hacerApuesta(int cantidad);//apuesta inicial de la ronda
	void ganarApuesta(int indice=0);//gana 1:1
	void ganarBlackjack(int indice);//gana 3:2 (blackjack)
	void empatarApuesta(int indice =0);//empate, se recupera la apuesta
	void perderApuesta(int indice=0);//pierde la apuesta
	bool doblarApuesta(int indice=0);//duplica la apuesta,valida 2 cartas

	//	Acciones especiales
	bool puedeDoblar(int indice = 0)const;// ¿se permite doblar esta mano?
	bool puedeDividir()const;//se permite dividir?
	bool dividir();//separa el par en dos manos 

	//Seguro
	int getMaxSeguro() const;//maximo permitodp,mitad de la apuesta original
	bool hacerSeguro(int cantidad);//coloca la apuesta de seguro
	void resolverSeguro(bool dealerTieneBlackjack);//se paga 2:1 o se pierde

	//Consultas
	int getFichas() const;
	int getApuestaActual(int indice=0) const;

	//sobrescribe la mano de participante,ademas de vaciar las manos
	void limpiarManos() override;//limpia apuesta y seguro para la nueva ronda

};

#endif


