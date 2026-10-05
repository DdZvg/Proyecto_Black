#include "Carta.h"
#include "Consola.h"
using namespace std;
// Constructor de la clase Carta
Carta::Carta(string palo, string valor, int puntos, int posX, int posY, bool oculto) {
	this->palo = palo;
	this->valor = valor;
	this->puntos = puntos;
	this->posX = posX;
	this->posY = posY;
	this->oculto = oculto;
}
// Getters y Setters
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
void Carta::setPosicion(int x, int y) {
	//posiciones
	posX = x;
    
	posY = y;
}
void Carta::setOculta(bool estado) {
	oculto = estado; 
}
string Carta::getColor() const {
	if (oculto) return Consola::AZUL;
	if (palo == "Corazones" || palo == "Diamantes") return Consola::ROJO;
	return Consola::BLANCO;
}
void Carta::dibujarBloque() const {
    std::string col = getColor();

    Consola::moverCursor(posX, posY);
    std::cout << col << "┌─────────┐" << Consola::RESET;

    Consola::moverCursor(posX, posY + 1);
    if (oculto) {
        std::cout << col << "│░░░░░░░░░│" << Consola::RESET;
        Consola::moverCursor(posX, posY + 2);
        std::cout << col << "│░░░ ? ░░░│" << Consola::RESET;
        Consola::moverCursor(posX, posY + 3);
        std::cout << col << "│░░░░░░░░░│" << Consola::RESET;
    }
    else {
        std::string valForm = (valor.length() == 1) ? valor + " " : valor;
        std::string simPalo = palo.substr(0, 1); // C, P, D, T

        std::cout << col << "│ " << valForm << "      │" << Consola::RESET;
        Consola::moverCursor(posX, posY + 2);
        std::cout << col << "│    " << simPalo << "    │" << Consola::RESET;
        Consola::moverCursor(posX, posY + 3);
        std::cout << col << "│      " << valForm << "│" << Consola::RESET;
    }

    Consola::moverCursor(posX, posY + 4);
    std::cout << col << "└─────────┘" << Consola::RESET;
}
