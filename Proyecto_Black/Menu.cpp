#include "Menu.h"
#include <iostream>
#include <string>
#include "Consola.h"
#include "Validador.h"
using namespace std;

Menu::Menu(string titulo) {
	this->titulo = titulo;
}
void Menu::mostrarBienvenida() const {
    // Encabezado Principal con Banner ASCII
	Consola::limpiarPantalla();
    cout << "=======================================================================\n";
    cout << "  ██████╗ ██╗      █████╗  ██████╗██╗  ██╗   ██████╗ ██████╗ \n";
    cout << "  ██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝   ██╔══██╗██╔══██╗\n";
    cout << "  ██████╔╝██║     ███████║██║     █████═╝    ██████╔╝██████╔╝\n";
    cout << "  ██╔══██╗██║     ██╔══██║██║     ██╔═██╗    ██╔═══╝ ██╔══██╗\n";
    cout << "  ██████╔╝███████╗██║  ██║╚██████╗██║  ██╗   ██║     ██║  ██║\n";
    cout << "  ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝   ╚═╝     ╚═╝  ╚═╝\n";
    cout << "=======================================================================\n";
    cout << "                    ¡ BIENVENIDO A "<< this->titulo << " !\n";
    cout << "                       El juego clásico de 21                          \n";
    cout << "=======================================================================\n\n";


    cout << "            ┌─────────┐   ┌─────────┐   ┌─────────┐            \n";
    cout << "            │ A       │   │ K       │   │ 10      │            \n";
    cout << "            │    ♠    │   │    ♥    │   │    ♣    │            \n";
    cout << "            │       A │   │       K │   │      10 │            \n";
    cout << "            └─────────┘   └─────────┘   └─────────┘            \n\n";

    cout << "=======================================================================\n";
    cout << "              Presiona [ENTER] para ingresar al juego...               \n";
    cout << "=======================================================================\n";

    // Pausa para que el usuario presione ENTER antes de continuar
    cin.get();
}
int Menu::mostrarMenuPrincipal() const {
    Consola::limpiarPantalla();
    cout << "=======================================================================\n";
    cout << "                      " << this->titulo << " - MENÚ PRINCIPAL\n";
    cout << "=======================================================================\n\n";
    cout << "  ┌─────────────────────────────────────────────────────────────────┐\n";
    cout << "  │   [1] Iniciar Nueva Partida                                     │\n";
    cout << "  │   [2] Ver Reglas del Juego                                      │\n";
    cout << "  │   [3] Salir                                                     │\n";
    cout << "  └─────────────────────────────────────────────────────────────────┘\n\n";

    // Validador imprime el mensaje, lee la opción de la consola, la valida y la retorna
    return Validador::leerEntero("  >> Selecciona una opcion (1-3): ", 1, 3);
}
void Menu::mostrarReglas() const {
    Consola::limpiarPantalla();

    cout << "=======================================================================\n";
    cout << "                    REGLAS Y MANUAL DE " << this->titulo << "                    \n";
    cout << "=======================================================================\n\n";

    // 1. Objetivo Principal
    cout << "┌─────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ 1. OBJETIVO DEL JUEGO                                               │\n";
    cout << "├─────────────────────────────────────────────────────────────────────┤\n";
    cout << "│ • Vencer la mano del crupier obteniendo mas puntos que el sin      │\n";
    cout << "│   exceder los 21, o manteniendose activo si el crupier se pasa.    │\n";
    cout << "│ • Se juega con un calzado virtual de 6 barajas (312 cartas).        │\n";
    cout << "└─────────────────────────────────────────────────────────────────────┘\n\n";

    // 2. Valor de las Cartas y Tipos de Manos
    cout << "┌─────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ 2. VALOR DE LAS CARTAS Y TIPOS DE MANO                              │\n";
    cout << "├─────────────────────────────────────────────────────────────────────┤\n";
    cout << "│ • Numericas (2 al 10): Conservan su valor nominal.                  │\n";
    cout << "│ • Figuras (J, Q, K)  : Valen 10 puntos cada una.                    │\n";
    cout << "│ • As (A)             : Vale 1 u 11 puntos (dinamico).               │\n";
    cout << "│                                                                     │\n";
    cout << "│ • Mano Suave (Soft)  : Contiene un As con valor de 11 sin pasarse.  │\n";
    cout << "│ • Mano Dura (Hard)   : Sin As, o con As obligado a valer 1.         │\n";
    cout << "└─────────────────────────────────────────────────────────────────────┘\n\n";

    // 3. Acciones Tácticas
    cout << "┌─────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ 3. ACCIONES DEL JUGADOR                                             │\n";
    cout << "├─────────────────────────────────────────────────────────────────────┤\n";
    cout << "│ • Plantarse (Stand) : Finaliza el turno y conserva la puntuacion.   │\n";
    cout << "│ • Pedir (Hit)       : Solicita una carta adicional.                 │\n";
    cout << "│ • Doblar (Double)   : Duplica la apuesta y recibe SOLO una carta.   │\n";
    cout << "│ • Dividir (Split)   : Separa un par del mismo valor en 2 manos.    │\n";
    cout << "│ • Seguro (Insurance): Apuesta opcional (50%) si el crupier enseña As│\n";
    cout << "└─────────────────────────────────────────────────────────────────────┘\n\n";

    // 4. Reglas del Dealer y Pagos
    cout << "┌─────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ 4. REGLAS DEL CRUPIER Y TABLA DE PAGOS                              │\n";
    cout << "├─────────────────────────────────────────────────────────────────────┤\n";
    cout << "│ • Regla Crupier      : Pide con 16 o menos | Se planta con 17+    │\n";
    cout << "│ • Victoria Normal    : Paga 1 : 1 (Ganas el 100% de tu apuesta).    │\n";
    cout << "│ • Blackjack Natural  : Paga 3 : 2 (Ganas el 150% con As + 10/Figura) │\n";
    cout << "│ • Empate (Push)      : Se devuelve el 100% de la apuesta.           │\n";
    cout << "│ • Seguro Ganador     : Paga 2 : 1.                                  │\n";
    cout << "└─────────────────────────────────────────────────────────────────────┘\n\n";

    cout << "=======================================================================\n";
    cout << "              Presiona [ENTER] para regresar al menu...                \n";
    cout << "=======================================================================\n";

    cin.get();
}
// 1. Solicitar Cantidad de Jugadores
int Menu::solicitarCantidadJugadores(int min, int max) const {
    Consola::limpiarPantalla();
    cout << "=======================================================================\n";
    cout << "                    CONFIGURACIÓN DE LA PARTIDA                        \n";
    cout << "=======================================================================\n\n";
    cout << "  ┌─────────────────────────────────────────────────────────────────┐\n";
    cout << "  │  Paso 1: Definir número de participantes                        │\n";
    cout << "  └─────────────────────────────────────────────────────────────────┘\n\n";

    return Validador::leerEntero("  >> Ingrese la cantidad de jugadores (" + to_string(min) + "-" + to_string(max) + "): ", min, max);
}
/* se que se ve mal pero en la consola se ve bien*/
// 2. Solicitar Nombre del Jugador
string Menu::solicitarNombreJugador(int index) const {
    cout << "\n  ┌─────────────────────────────────────────────────────────────────┐\n";
    cout << "  │  Registro de Jugador " << index << "                                          │\n";
    cout << "  └─────────────────────────────────────────────────────────────────┘\n";

    return Validador::leerTexto("  >> Nombre para el Jugador " + to_string(index) + ": ");
}

// 3. Solicitar Cantidad de Mazos
int Menu::solicitarCantidadMazos() const {
    cout << "\n  ┌─────────────────────────────────────────────────────────────────┐\n";
    cout << "  │  Paso 2: Configuración del Zapato / Baraja                      │\n";
    cout << "  └─────────────────────────────────────────────────────────────────┘\n\n";

    return Validador::leerEntero("  >> Cantidad de mazos a utilizar (1-8) [Recomendado: 6]: ", 1, 8);
}
//int Menu::solicitarApuesta(const Jugador& j) const{}
