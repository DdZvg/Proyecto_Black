#pragma once

#include <iostream>
#include "Colores.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

using namespace std;

namespace Consola {

    // Configura la consola al arrancar (UTF-8 en Windows)
    inline void inicializar() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
    }

    // Limpia la pantalla
    inline void limpiarPantalla() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    // Mueve el cursor a las coordenadas (x, y)
    inline void moverCursor(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
    }

}