#pragma once
#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Mazo.h"
#include "Dealer.h"
#include "Jugador.h"
#include <vector>
#include <string>
#include "Mano.h"

using namespace std;
class BlackJackGame {
protected:
    vector<Mazo> mazos;
    vector<Jugador> jugadores;
    Dealer dealer;
    int numJugadores;
public:
    BlackJackGame(int numJugadores);
    void ejecutar();
    void iniciarRonda();
    void turnoJugador();
    void turnoDealer();
    void doblarApuesta();
    void determinarGanador();
    void resetearRonda();
};

#endif
