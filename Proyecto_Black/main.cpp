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
    jugador.recibirCarta(zapato.tomarCarta());
    
    dealer.recibirCarta(zapato.tomarCarta());
    jugador.recibirCarta(zapato.tomarCarta());
    dealer.recibirCarta(zapato.tomarCarta());
    cout << "3) Reparto inicial hecho. Quedan " << zapato.cartasRestantes() << " cartas\n";

    cout << "\n" << jugador.getNombre() << ":\n";
    jugador.getMano(0).mostrarMano(false, 7);
    cout << "Puntos: " << jugador.getMano(0).calcularPuntos() << "\n";

    cout << "\nDealer (primera carta oculta):\n";
    dealer.getMano(0).mostrarMano(true, 15);
    cout << "Puntos reales: " << dealer.getMano(0).calcularPuntos() << "\n\n";
}

int main() {
    Consola::inicializar();
    correrDemo();
    return 0;
}