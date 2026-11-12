#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

using namespace std;

namespace Consola {

    const string CODIGO_RESTABLECER_FORMATO = "\033[0m";

    inline void inicializar() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
    }

    inline void limpiarPantalla() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    inline void moverCursor(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
    }

}