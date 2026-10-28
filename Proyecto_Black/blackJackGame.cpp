#include "blackJackGame.h"
#include <iostream>

BlackJackGame::BlackJackGame(int numJugadores) : numJugadores(numJugadores) {
    for (int i = 0; i < numJugadores; ++i) {
        jugadores.emplace_back("Jugador " + to_string(i + 1));
    }
    mazos.emplace_back();
}

void BlackJackGame::ejecutar() {
    // Lógica para ejecutar el flujo principal del juego
}

void BlackJackGame::iniciarRonda() {
    // Lógica para repartir cartas iniciales
}

void BlackJackGame::turnoJugador() {
    // Lógica para el turno del jugador (pedir, plantarse, etc.)
}

void BlackJackGame::turnoDealer() {
    // Lógica para el turno del dealer
}

void BlackJackGame::doblarApuesta() {
    // Lógica para doblar la apuesta del jugador
}

void BlackJackGame::determinarGanador() {
    // Comparación de puntos entre el dealer y los jugadores
}

void BlackJackGame::resetearRonda() {
    // Limpiar las manos de los jugadores y el dealer para una nueva ronda
}