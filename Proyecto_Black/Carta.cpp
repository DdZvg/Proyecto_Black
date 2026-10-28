#include "Carta.h"
#include "Consola.h"
#include <iostream>

using namespace std;
// CONSTRUCTOR

// Inicializa las propiedades de la carta (palo, valor, puntos, posición inicial en la consola y estado oculta/visible)
Carta::Carta(string palo, string valor, int puntos, bool oculto) {
    this->palo = palo;
    this->valor = valor;
    this->puntos = puntos;

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



// Cambia la visibilidad de la carta (true = boca abajo, false = boca arriba)
void Carta::setOculta(bool estado) {
    this->oculto = estado;
}
string Carta::getSimboloPalo() const {
    if (palo == "Corazones" || palo =="corazones") return "♥";
    if (palo == "Diamantes" || palo == "diamantes") return "♦";
    if (palo == "Treboles" || palo == "treboles") return "♣";
    if (palo == "Picas" || palo == "picas") return "♠";
    return palo.substr(0, 1);
}

// DIBUJO Y FORMATO EN CONSOLA
// 
// Determina el código de color ANSI según el estado o el palo de la carta
string Carta::getColor() const {
    if (oculto) return Consola::AZUL_OSCURO;
    string sim = getSimboloPalo();
    if (sim == "♥" || sim == "♦" || palo == "Corazones" || palo == "Diamantes") {
        return Consola::ROJO;
    }
    return Consola::BLANCO;
}

// Renderiza la carta gráficamente en la posición (posX, posY) de la consola mediante arte ASCII
void Carta::dibujarBloque(int posX, int posY) const {
	string color = getColor();
	// bordes de la carta
	string bordeSuperior = "┌─────────┐";
	string bordeInferior = "└─────────┘";
	// contenido de la carta
	Consola::moverCursor(posX, posY);
	cout << color << bordeSuperior << Consola::RESET;
    if (oculto) {
		//cuerpo de la carta oculta / fila de 1 a 5
        Consola::moverCursor(posX, posY + 1);
		cout << color << "│░░░░░░░░░│" << Consola::RESET;
		Consola::moverCursor(posX, posY + 2);
		cout << color << "│░░░░░░░░░│" << Consola::RESET;
		Consola::moverCursor(posX, posY + 3);
		cout << color << "│░░░░░░░░░│" << Consola::RESET;
		Consola::moverCursor(posX, posY + 4);
		cout << color << "│░░░░░░░░░│" << Consola::RESET;


    }
    else {
		string simPalo = getSimboloPalo();
        string valIzq = (valor.length() == 1) ? valor + " " : valor;
        string valDer = (valor.length() == 1) ? " " + valor : valor;
		//linea 1, valor de esquina superior izquierda
		Consola::moverCursor(posX, posY + 1);
		cout << color << "|" << valIzq << "       |" << Consola::RESET;

		//linea 2, símbolo del palo en el centro
		Consola::moverCursor(posX, posY + 2);
		cout << color << "|    " << simPalo << "    |" << Consola::RESET;

		//linea 3, valor de esquina inferior derecha
		Consola::moverCursor(posX, posY + 3);
		cout << color << "|       " << valDer << "|" << Consola::RESET;
    }
	// línea 4, borde inferior
	Consola::moverCursor(posX, posY + 4);
	cout << color << bordeInferior << Consola::RESET;
}
// Retorna una etiqueta textual legible
string Carta::etiqueta() const {
    if (oculto) {
        return "[Carta Oculta]";
    }
    return valor + " de " + palo;
}