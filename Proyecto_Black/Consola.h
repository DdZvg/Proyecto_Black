#ifndef CONSOLA_H
#define CONSOLA_H

#include <iostream>
#include <string>
using namespace std;
namespace Consola {
	//Por que se usa namespace Consola?
	// se usa para agrupar funciones y constantes relacionadas con la consola,
    // evitando conflictos de nombres y mejorando la organización del código.
    // Códigos ANSI para colores
    const std::string RESET = "\033[0m";
    const std::string ROJO = "\033[91m";
    const std::string BLANCO = "\033[97m";
    const std::string AZUL = "\033[94m";
    const std::string VERDE = "\033[92m";

    inline void limpiarPantalla() {
        std::cout << "\033[2J\033[1;1H";
    }

    inline void moverCursor(int x, int y) {
        std::cout << "\033[" << y << ";" << x << "H";
    }
}

#endif