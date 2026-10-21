#pragma once
#include <vector>
#include "Carta.h"

class Mano
{
private:
	std::vector<Carta> cartas;
public:
	Mano();

	void agregarCarta(Carta c);
	int calcularPuntos() const;


	// Mostrar la mano en consola, con opción de ocultar la primera carta (por ejemplo, para la mano del dealer)
	void mostrarMano(bool ocultarPrimera=false, int y=3) const;

	void limpiarMano();
	
	// Getter de el vector
	std::vector<Carta> getCartas() const;

};

