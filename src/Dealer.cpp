#include "Dealer.h"

using namespace std;

Dealer::Dealer()
    : Participante("Dealer") {
}

bool Dealer::debePedirCarta() const {
    return getMano(0).calcularPuntos() < 17;
}

const Carta& Dealer::getCartaVisible() const {
    // La segunda carta es la visible; la primera permanece oculta hasta revelarla.
    return getMano(0).cartas.at(1);
}

void Dealer::revelarCartaOculta() {
    cartaOcultaRevelada = true;
}

void Dealer::mostrarMano() const {
    getMano(0).mostrarMano(!cartaOcultaRevelada);
}

bool Dealer::debeRevisarBlackjack() const {
    if (getMano(0).getCartas().size() < 2) {
        return false;
    }

    const Carta& visible = getCartaVisible();

    return visible.getValor() == "A" ||
        visible.getPuntos() == 10;
}

void Dealer::limpiarManos() {
    Participante::limpiarManos();
    cartaOcultaRevelada = false;
}




