#pragma once

#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;
class Carta {
	// Atributos de la clase Carta
protected: //por defecto los atributos son privados, pero se pueden heredar a otras clases
	string palo;
	string valor;
	int puntos;
	bool oculto;
	// se eliminaron posX y posY ya que no son necesarios
	// para la lógica de la carta, pero si para el dibujo en consola

public:
	//constructor de la clase Carta
	Carta(string palo, string valor, int puntos, bool oculto);
	// Getters y Setters
	string getPalo() const;
	string getValor() const;
	int getPuntos() const;
	string getSimboloPalo() const;
	bool isOculto() const;
	void setOculta(bool estado);
	// Métodos visuales
	string getColor() const;
	void dibujarBloque(int posX, int posY) const;
	string etiqueta() const;
};

#endif // CARTA_H
