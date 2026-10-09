#include "Carta.h"
#include "Consola.h"
#include <iostream>

using namespace std;
// CONSTRUCTOR

// Inicializa las propiedades de la carta (palo, valor, puntos, posición inicial en la consola y estado oculta/visible)
Carta::Carta(string palo, string valor, int puntos, int posX, int posY, bool oculto) {
    this->palo = palo;
    this->valor = valor;
    this->puntos = puntos;
    this->posX = posX;
    this->posY = posY;
    this->oculto = oculto;
}


// MÉTODOS GETTER (Lectura de atributos)


string Carta::getPalo() const {
    return this->palo;
}

string Carta::getValor() const {
    return this->valor;
}

int Carta::getPuntos() const {
    return this->puntos;
}

bool Carta::isOculto() const {
    return this->oculto;
}


// MÉTODOS SETTER (Modificación de estado)


// Actualiza las coordenadas de la carta en la pantalla de la consola
void Carta::setPosicion(int x, int y) {
    this->posX = x;
    this->posY = y;
}

// Cambia la visibilidad de la carta (true = boca abajo, false = boca arriba)
void Carta::setOculta(bool estado) {
    this->oculto = estado;
}


// DIBUJO Y FORMATO EN CONSOLA


// Determina el código de color ANSI según el estado o el palo de la carta
string Carta::getColor() const {
    if (oculto) return Consola::AZUL_OSCURO;
    if (palo == "Corazones" || palo == "Diamantes") return Consola::ROJO;
    return Consola::BLANCO;
}

// Renderiza la carta gráficamente en la posición (posX, posY) de la consola mediante arte ASCII
void Carta::dibujarBloque() const {
    string col = getColor();

    // Línea 0: Borde superior
    Consola::moverCursor(posX, posY);
    cout << col << "+---------+" << Consola::RESET;

    Consola::moverCursor(posX, posY + 1);

    if (oculto) {
        // Reverso de la carta boca abajo con trama de asteriscos o almohadillas (#)
        cout << col << "|#########|" << Consola::RESET;
        Consola::moverCursor(posX, posY + 2);
        cout << col << "|   ?     |" << Consola::RESET;
        Consola::moverCursor(posX, posY + 3);
        cout << col << "|#########|" << Consola::RESET;
    }
    else {
        string valForm = (valor.length() == 1) ? valor + " " : valor;
        string simPalo = palo.substr(0, 1); // C, D, P, T

        // Línea 1: Valor esquina superior izquierda
        cout << col << "| " << valForm << "      |" << Consola::RESET;

        // Línea 2: Símbolo del palo en el centro
        Consola::moverCursor(posX, posY + 2);
        cout << col << "|    " << simPalo << "    |" << Consola::RESET;

        // Línea 3: Valor esquina inferior derecha
        Consola::moverCursor(posX, posY + 3);
        cout << col << "|      " << valForm << "|" << Consola::RESET;
    }

    // Línea 4: Borde inferior
    Consola::moverCursor(posX, posY + 4);
    cout << col << "+---------+" << Consola::RESET;
}