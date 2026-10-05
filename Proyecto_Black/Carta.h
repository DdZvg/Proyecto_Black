#pragma once

#ifndef CARTA_H
#define CARTA_H // se usa para evitar que se incluya varias veces el mismo archivo de cabecera
#include <string>
using namespace std;
class Carta {
	// Atributos de la clase Carta
protected: //por defecto los atributos son privados, pero se pueden heredar a otras clases
	string palo;
	string valor;
	int puntos;
	int posX;
	int posY;
	bool oculto;
public:
	//constructor de la clase Carta
	Carta(string palo, string valor, int puntos, int posX, int posY, bool oculto);
	// Getters y Setters
	string getPalo() const;
	string getValor() const;
	int getPuntos() const;
	bool isOculto() const;
	void setPosicion(int x, int y);
	void setOculta(bool estado);
	// Métodos visuales
	string getColor() const;	
	void dibujarBloque() const;
};

#endif // CARTA_H
