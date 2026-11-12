#pragma once

#include "Dealer.h"
#include "Jugador.h"
#include "Mazo.h"
#include <string>
#include <vector>

class BlackJackGame {
public:
    // UML: + MAX_JUGADORES : int = 7 {static, const}
    static constexpr int MAX_JUGADORES = 7;

protected:
    // UML: los punteros se crean y se liberan en BlackJackGame.
    // Un solo zapato: Mazo ya contiene numMazos barajas.
    Mazo* mazos;
    std::vector<Jugador*> jugadores;
    Dealer* dealer;
    int numJugadores;

private:
    // Limites de apuesta: el maximo deja fichas libres para doblar, dividir o seguro
    static constexpr int APUESTA_MINIMA = 10;
    static constexpr int APUESTA_MAXIMA = 500;

    // Saldo de cada jugador. El UML no lo muestra en Jugador porque las
    // operaciones de apuesta, pago y seguro viven en Mano.
    std::vector<int> fichas;

    // Apoyo visual de la mesa en vivo (no forma parte del UML)
    void dibujarMesa(int indiceActivo);
    void dibujarZonaDealer(bool revelada);
    void dibujarZonaActiva(int indiceActivo);
    void dibujarZonaOtros(int indiceActivo);
    void estado(const std::string& mensaje);
    void ofrecerSeguro();

public:
    explicit BlackJackGame(int numJugadores, int numMazos = 1);
    // Sobrecarga de conveniencia para conservar el registro de nombres de la interfaz.
    explicit BlackJackGame(const std::vector<std::string>& nombres, int numMazos = 1);
    ~BlackJackGame();

    // Los punteros internos son propios de la clase: no se copian.
    BlackJackGame(const BlackJackGame&) = delete;
    BlackJackGame& operator=(const BlackJackGame&) = delete;

    void ejecutar();
    void iniciarRonda();
    void turnoJugador();
    void turnoDealer();
    void doblarApuesta();
    void determinarGanador();
    void resetearRonda();
};