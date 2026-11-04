#include "Carta.h"
#include "Consola.h"
#include "Colores.h"
#include <string>
#include <iostream>

using namespace std;

// CONSTRUCTOR
Carta::Carta(string palo, string valor, int puntos, bool oculta) {
    this->palo = palo;
    this->valor = valor;
    this->puntos = puntos;
    this->oculta = oculta;
}

// MÉTODOS GETTER
string Carta::getPalo() const {
    return this->palo;
}

string Carta::getValor() const {
    return this->valor;
}

int Carta::getPuntos() const {
    return this->puntos;
}

bool Carta::isOculta() const {
    return this->oculta;
}

// MÉTODOS SETTER
void Carta::setOculta(bool estado) {
    this->oculta = estado;
}

string Carta::getSimboloPalo() const {
    if (palo == "Corazones" || palo == "corazones") return "♥";
    if (palo == "Diamantes" || palo == "diamantes") return "♦";
    if (palo == "Treboles" || palo == "treboles") return "♣";
    if (palo == "Picas" || palo == "picas") return "♠";
    return palo.substr(0, 1);
}

// DIBUJO Y FORMATO EN CONSOLA
string Carta::getColor() const {
    if (oculta) return Colores::AZUL_OSCURO;
    string sim = getSimboloPalo();
    if (sim == "♥" || sim == "♦" || palo == "Corazones" || palo == "Diamantes") {
        return Colores::ROJO;
    }
    return Colores::BLANCO;
}

// Renderiza la carta en la posición (posX, posY)
void Carta::dibujarBloque(int posX, int posY) const {
    string color = getColor();
    string bordeSuperior = "┌─────────┐";
    string bordeInferior = "└─────────┘";

    Consola::moverCursor(posX, posY);
    cout << color << bordeSuperior << Colores::RESET;

    if (oculta) {
        Consola::moverCursor(posX, posY + 1);
        cout << color << "│░░░░░░░░░│" << Colores::RESET;
        Consola::moverCursor(posX, posY + 2);
        cout << color << "│░░░░░░░░░│" << Colores::RESET;
        Consola::moverCursor(posX, posY + 3);
        cout << color << "│░░░░░░░░░│" << Colores::RESET;
        Consola::moverCursor(posX, posY + 4);
        cout << color << "│░░░░░░░░░│" << Colores::RESET;
    }
    else {
        string simPalo = getSimboloPalo();
        string valIzq = (valor.length() == 1) ? valor + " " : valor;
        string valDer = (valor.length() == 1) ? " " + valor : valor;

        Consola::moverCursor(posX, posY + 1);
        cout << color << "|" << valIzq << "       |" << Colores::RESET;

        Consola::moverCursor(posX, posY + 2);
        cout << color << "|    " << simPalo << "    |" << Colores::RESET;

        Consola::moverCursor(posX, posY + 3);
        cout << color << "|       " << valDer << "|" << Colores::RESET;
    }

    Consola::moverCursor(posX, posY + 4);
    cout << color << bordeInferior << Colores::RESET;
}

string Carta::etiqueta() const {
    if (oculta) {
        return "[Carta Oculta]";
    }
    return valor + " de " + palo;
}