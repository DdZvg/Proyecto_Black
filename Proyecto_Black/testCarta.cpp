#include "TestCarta.h"
#include "Carta.h"
#include "Consola.h"
#include <iostream>
#include <cassert>

using namespace std;

// Prueba de métodos y getters/setters

// Prueba gráfica en consola
static void probarDibujoConsola() {
    Consola::limpiarPantalla();

    Consola::moverCursor(2, 1);
    cout << "=== PRUEBA VISUAL: DIBUJO DE CARTA Y CONSOLA ===";

    Carta cRoja("Corazones", "K", 10, false);
    Carta cOculta("Picas", "A", 11, true);

    cRoja.dibujarBloque(2, 3);
    cOculta.dibujarBloque(16, 3);

    Consola::moverCursor(2, 9);
    cout << "Carta 1: " << cRoja.etiqueta();

    Consola::moverCursor(2, 10);
    cout << "Carta 2: " << cOculta.etiqueta();

    Consola::moverCursor(2, 13);
    cout << "Prueba completada. Presiona Enter para volver a main...";
    cin.get();
}

// Función expuesta hacia main.cpp
void ejecutarPruebasCarta() {

    probarDibujoConsola();
}