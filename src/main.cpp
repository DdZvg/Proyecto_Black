#include "blackJackGame.h"
#include "Consola.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    Consola::inicializar();

    Menu menu("BlackProject");
    menu.mostrarBienvenida();

    bool salir = false;
    while (!salir) {
        switch (menu.mostrarMenuPrincipal()) {
        case 1: {
            int cantidadJugadores = menu.solicitarCantidadJugadores(1, BlackJackGame::MAX_JUGADORES);

            vector<string> nombres;
            nombres.reserve(cantidadJugadores);
            for (int i = 1; i <= cantidadJugadores; ++i) {
                nombres.push_back(menu.solicitarNombreJugador(i));
            }

            int cantidadMazos = menu.solicitarCantidadMazos();
            BlackJackGame juego(nombres, cantidadMazos);
            juego.ejecutar();
            break;
        }
        case 2:
            menu.mostrarReglas();
            break;
        case 3:
            salir = true;
            break;
        }
    }

    cout << "\nGracias por jugar.\n";
    return 0;
}