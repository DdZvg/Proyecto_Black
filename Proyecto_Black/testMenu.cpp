#include "testMenu.h"
#include "Menu.h"
#include "Consola.h"
#include <iostream>

using namespace std;

namespace TestMenu {

    void probarBienvenida() {
        cout << "\n--- [TEST 1] Probar Pantalla de Bienvenida ---\n";
        Menu menu("BlackProject");
        menu.mostrarBienvenida();
        cout << "  [✓] Pantalla de bienvenida completada con exito.\n";
    }

    void probarMenuPrincipal() {
        cout << "\n--- [TEST 2] Probar Seleccion del Menu Principal ---\n";
        Menu menu("BlackProject");
        int opcion = menu.mostrarMenuPrincipal();
        cout << "  [✓] Opcion elegida y retornada correctamente: " << opcion << "\n";
    }

    void probarReglas() {
        cout << "\n--- [TEST 3] Probar Pantalla de Reglas ---\n";
        Menu menu("BlackProject");
        menu.mostrarReglas();
        cout << "  [✓] Visualizacion de reglas finalizada con exito.\n";
    }

    void probarSolicitudes() {
        cout << "\n--- [TEST 4] Probar Captura y Validacion de Datos ---\n";
        Menu menu("BlackProject");

        int jugadores = menu.solicitarCantidadJugadores(1, 4);
        cout << "  [✓] Cantidad de jugadores recibida: " << jugadores << "\n";

        string nombre = menu.solicitarNombreJugador(1);
        cout << "  [✓] Nombre ingresado: " << nombre << "\n";

        int mazos = menu.solicitarCantidadMazos();
        cout << "  [✓] Cantidad de mazos recibida: " << mazos << "\n";
    }

    void ejecutarTodasLasPruebas() {
        Consola::inicializar();

        cout << "===================================================\n";
        cout << "           INICIANDO BATERIA DE TESTS: MENU        \n";
        cout << "===================================================\n\n";

        probarBienvenida();
        probarMenuPrincipal();
        probarReglas();
        probarSolicitudes();

        cout << "\n===================================================\n";
        cout << "      ¡TODAS LAS PRUEBAS DE MENU CONCLUIDAS!      \n";
        cout << "===================================================\n\n";
    }
}