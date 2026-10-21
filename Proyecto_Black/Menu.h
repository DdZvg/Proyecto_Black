#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;  
class Menu {
private:
    string titulo;
public:
    Menu(string titulo);
    void mostrarBienvenida() const;
    int mostrarMenuPrincipal() const;
    void mostrarReglas() const;
    int solicitarCantidadJugadores(int min, int max) const;
    string solicitarNombreJugador(int numero) const;
    int solicitarCantidadMazos() const;
    //int solicitarApuesta(const Jugador& j) const;



};
#endif