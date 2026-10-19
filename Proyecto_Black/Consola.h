#pragma once
#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>
#include <string>

// Soporte para consolas Windows (UTF-8)
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

using namespace std;

namespace Consola {
    // Códigos ANSI para colores
    const string RESET = "\033[0m";
    const string ROJO = "\033[91m";
    const string BLANCO = "\033[97m";
    const string AZUL_OSCURO = "\033[34m";
    const string VERDE = "\033[92m";

    // Configura la consola al arrancar 
    inline void inicializar() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
    }

    // Limpia la pantalla y posiciona el cursor en el origen (1,1)
    inline void limpiarPantalla() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
        cout << "\033[2J\033[1;1H";
    }

    // Mueve el cursor a las coordenadas (x, y) de la consola
    inline void moverCursor(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
    }
}

#endif