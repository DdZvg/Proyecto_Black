#pragma once
#include <vector>
#include "Carta.h"
#include "ResultadoMano.h"
#include <string>
using namespace std;
class Mano
{
private:
	vector<Carta> cartas;
	int apuesta;
	int apuestaSeguro;
	bool esDeDivision;
	ResultadoMano resultado;
public:
	Mano();

	void agregarCarta(Carta c);

	// Quitar la última carta de la mano y devolverla
	Carta quitarUltimaCarta();

	// Marcar la mano como resultado de una división (split)
	void marcarDeDivision();

	int calcularPuntos() const;

	bool tieneBlackjack() const;
	bool estaBusted() const;
	bool puedeDividir() const;

	// Mostrar la mano en consola, con opción de ocultar la primera carta (por ejemplo, para la mano del dealer)
	void mostrarMano(bool ocultarPrimera=false, int y=3) const;

	void limpiarMano();
	
	// Getter de el vector
	vector<Carta> getCartas() const;

	// Acceso a una carta concreta sin copiar el vector
	const Carta& getCarta(int indice) const;

	// Apuestas y resultado de la mano
	bool apostar(int cantidad);
	int getApuesta() const;
	bool doblarApuesta();
	void ganarApuesta();
	void ganarBlackjack();
	void empatarApuesta();
	void perderApuesta();

	// Seguro de la mano
	int getMaxSeguro() const;
	bool hacerSeguro(int cantidad);
	void resolverSeguro(bool dealerTieneBlackjack);
	int getApuestaSeguro() const;

	ResultadoMano getResultado() const;
};
