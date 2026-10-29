#pragma once
#include <vector>
#include "Carta.h"
#include <string>
using namespace std;
class Mano
{
private:
	vector<Carta> cartas;
public:
	Mano();

	void agregarCarta(Carta c);
	Carta quitarUltimaCarta();
	void marcarDeDivision();
	int calcularPuntos() const;


	// Mostrar la mano en consola, con opción de ocultar la primera carta (por ejemplo, para la mano del dealer)
	void mostrarMano(bool ocultarPrimera=false, int y=3) const;

	void limpiarMano();
	
	// Getter de el vector
	vector<Carta> getCartas() const;

};

