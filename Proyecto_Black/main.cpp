#include "Consola.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

// Demo: zapato de 6 mazos, barajar, repartir y calcular el valor de una mano
void correrDemo() {
    Consola::limpiarPantalla();

    Mazo zapato(6);
    cout << "1) Zapato creado: " << zapato.cartasRestantes() << " cartas \n";

    
    zapato.mezclar();
    cout << "2) Zapato barajado\n";

    Jugador jugador("Jugador 1", 1000);
    Dealer dealer;

	// Reparto inicial: 2 cartas para el jugador y 2 para el dealer
    jugador.recibirCarta(zapato.tomarCarta(), 0);

	// La primera carta del dealer se reparte oculta
    dealer.recibirCarta(zapato.tomarCarta(), 0);

	// Segunda carta del jugador
    jugador.recibirCarta(zapato.tomarCarta(), 0);

	// Segunda carta del dealer
    dealer.recibirCarta(zapato.tomarCarta(), 0);
    cout << "3) Reparto inicial hecho. Quedan " << zapato.cartasRestantes() << " cartas\n";


    cout << "\n" << jugador.getNombre() << ":\n";
	jugador.getMano(0).mostrarMano(false, 7);// Mostrar la mano del jugador sin ocultar cartas
	cout << "Puntos: " << jugador.getMano(0).calcularPuntos() << "\n";// Mostrar los puntos del jugador


    cout << "\nDealer (primera carta oculta):\n";
	dealer.getMano(0).mostrarMano(true, 15);// Mostrar la mano del dealer con la primera carta oculta
	cout << "Puntos reales: " << dealer.getMano(0).calcularPuntos() << "\n\n";// Mostrar los puntos reales del dealer (aunque la primera carta esté oculta)
}

int main() {
    Consola::inicializar();
    correrDemo();
    return 0;
}