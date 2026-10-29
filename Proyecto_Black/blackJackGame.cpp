#include "blackJackGame.h"
#include <iostream>

BlackJackGame::BlackJackGame(int numJugadores) : numJugadores(numJugadores) {
    for (int i = 0; i < numJugadores; ++i) {
        jugadores.emplace_back("Jugador " + to_string(i + 1), 1000);
    }
    mazos.emplace_back(6); // zapato de 6 mazos (312 cartas) en un solo Mazo
}

void BlackJackGame::ejecutar() {
    // Lgica para ejecutar el flujo principal del juego
}

void BlackJackGame::iniciarRonda() {
    // Lgica para repartir cartas iniciales
}

void BlackJackGame::turnoJugador() {
    // Lgica para el turno del jugador (pedir, plantarse, etc.)
}

void BlackJackGame::turnoDealer() {
    // Lgica para el turno del dealer
}

void BlackJackGame::doblarApuesta() {
    // Lgica para doblar la apuesta del jugador
}

void BlackJackGame::determinarGanador() {
    // Comparacin de puntos entre el dealer y los jugadores
}

void BlackJackGame::resetearRonda() {
    // Limpiar las manos de los jugadores y el dealer para una nueva ronda
}