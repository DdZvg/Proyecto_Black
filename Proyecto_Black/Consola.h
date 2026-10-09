#pragma once
#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>
#include <string>
using namespace std;
namespace Consola {
    // Códigos ANSI para colores
    const string RESET = "\033[0m";
    const string ROJO = "\033[91m";
    const string BLANCO = "\033[97m";
    const string AZUL_OSCURO = "\033[34m"; 
    const string VERDE = "\033[92m";

    inline void limpiarPantalla() {
        cout << "\033[2J\033[1;1H";
    }

    inline void moverCursor(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
    }
}

#endif