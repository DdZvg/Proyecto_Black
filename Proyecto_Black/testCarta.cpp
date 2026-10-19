#include "TestCarta.h"
#include "Carta.h"
#include "Consola.h"
#include <iostream>
#include <cassert>

using namespace std;

// Prueba de métodos y getters/setters
static void probarLogicaCarta() {
    cout << "==========================================" << endl;
    cout << "Ejecutando pruebas logicas de Carta..." << endl;
    cout << "==========================================" << endl;

    Carta c1("Corazones", "A", 11, 0, 0, false);

    // Verificación de datos
    assert(c1.getPalo() == "Corazones");
    assert(c1.getValor() == "A");
    assert(c1.getPuntos() == 11);
    assert(c1.isOculto() == false);
    assert(c1.etiqueta() == "A de Corazones");

    // Modificación de coordenadas y visibilidad
    c1.setPosicion(10, 5);
    c1.setOculta(true);
    assert(c1.isOculto() == true);
    assert(c1.etiqueta() == "[Carta Oculta]");

    cout << " -> [OK] Logica de Carta verificada con exito.\n" << endl;
}

// Prueba gráfica en consola
static void probarDibujoConsola() {
    Consola::limpiarPantalla();

    Consola::moverCursor(2, 1);
    cout << "=== PRUEBA VISUAL: DIBUJO DE CARTA Y CONSOLA ===";

    Carta cRoja("Corazones", "K", 10, 2, 3, false);
    Carta cOculta("Picas", "A", 11, 16, 3, true);

    cRoja.dibujarBloque();
    cOculta.dibujarBloque();

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
    probarLogicaCarta();

    cout << "Presiona Enter para iniciar la prueba visual...";
    cin.get();

    probarDibujoConsola();
}