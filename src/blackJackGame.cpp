#include "blackJackGame.h"
#include "Consola.h"
#include "Validador.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace {
    void pausar() {
        cout << "Presiona ENTER para continuar...";
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }

    void encabezado(const string& titulo, int y) {
        Consola::escribirEn(1, y, "=======================================================================");
        Consola::centrar(y + 1, titulo);
        Consola::escribirEn(1, y + 2, "=======================================================================");
    }

    string textoResultado(ResultadoMano r) {
        switch (r) {
        case ResultadoMano::BlackJack: return "BLACKJACK";
        case ResultadoMano::Gana: return "GANASTE";
        case ResultadoMano::Empata: return "EMPATE";
        case ResultadoMano::Pierde: return "PERDISTE";
        default: return "PENDIENTE";
        }
    }

    // Lista compacta de cartas (por ejemplo "A♠ K♦ ") para los resumenes de ronda
    string etiquetasCompactas(const Mano& mano) {
        string texto;
        for (const Carta& carta : mano.getCartas()) texto += carta.getValor() + carta.getSimboloPalo() + " ";
        return texto;
    }

    // Linea compacta de un jugador para la zona inferior de la mesa
    string lineaCompactaJugador(const Jugador& jugador) {
        string linea = jugador.getNombre() + ": ";
        for (int i = 0; i < jugador.getNumManos(); ++i) {
            const Mano& mano = jugador.getMano(i);
            if (mano.getApuesta() == 0) continue;
            if (jugador.getNumManos() > 1) linea += "[" + to_string(i + 1) + "] ";
            if (mano.getCartas().empty()) {
                linea += "apuesta " + to_string(mano.getApuesta());
            }
            else {
                linea += etiquetasCompactas(mano) + "= " + to_string(mano.calcularPuntos());
                if (mano.estaBusted()) linea += " (se paso)";
                if (mano.tieneBlackjack()) linea += " BLACKJACK";
            }
            linea += "  ";
        }
        return linea;
    }

    // UML: valida que numJugadores este entre 1 y MAX_JUGADORES (7)
    int limitarJugadores(int cantidad) {
        if (cantidad < 1) return 1;
        return cantidad > BlackJackGame::MAX_JUGADORES ? BlackJackGame::MAX_JUGADORES : cantidad;
    }

    int limitarMazos(int cantidad) {
        return cantidad < 1 ? 1 : cantidad;
    }

    // Filas fijas de la mesa. El dealer ocupa la parte superior y nunca se borra
    // durante la ronda; el jugador activo ocupa el centro y el resto se ve compacto abajo.
    constexpr int FILA_TITULO = 1;
    constexpr int FILA_DEALER_ETIQUETA = 2;
    constexpr int FILA_ACTIVO_ETIQUETA = 9;
    constexpr int FILA_MANO1 = 10;
    constexpr int FILA_MANO2_ETIQUETA = 15;
    constexpr int FILA_MANO2 = 16;
    constexpr int FILA_OTROS = 22;
    constexpr int FILA_MENSAJE = 28;
    constexpr int FILA_ESTADO = 29;
    constexpr int ANCHO_MESA = 78;
}

BlackJackGame::BlackJackGame(int cantidadJugadores, int cantidadMazos)
    : mazos(new Mazo(limitarMazos(cantidadMazos))),
    jugadores(),
    dealer(new Dealer()),
    numJugadores(limitarJugadores(cantidadJugadores)),
    fichas(numJugadores, 1000) {
    for (int i = 0; i < numJugadores; ++i) {
        jugadores.push_back(new Jugador("Jugador " + to_string(i + 1)));
    }
}

BlackJackGame::BlackJackGame(const vector<string>& nombres, int cantidadMazos)
    : mazos(new Mazo(limitarMazos(cantidadMazos))),
    jugadores(),
    dealer(new Dealer()),
    numJugadores(limitarJugadores(static_cast<int>(nombres.size()))),
    fichas(numJugadores, 1000) {
    for (int i = 0; i < numJugadores; ++i) {
        string nombre = (i < static_cast<int>(nombres.size()) && !nombres[i].empty())
            ? nombres[i]
            : "Jugador " + to_string(i + 1);
        jugadores.push_back(new Jugador(nombre));
    }
}

BlackJackGame::~BlackJackGame() {
    for (Jugador* jugador : jugadores) delete jugador;
    delete dealer;
    delete mazos;
}

// ---- Zonas de la mesa ----

void BlackJackGame::estado(const string& mensaje) {
    Consola::limpiarRegion(3, FILA_MENSAJE, ANCHO_MESA - 2, 2);
    Consola::escribirLinea(3, FILA_MENSAJE, mensaje, ANCHO_MESA - 2);
}

void BlackJackGame::dibujarZonaDealer(bool revelada) {
    Consola::limpiarRegion(1, FILA_DEALER_ETIQUETA, ANCHO_MESA, 6);
    string etiqueta = "DEALER";
    const Mano& mano = dealer->getMano(0);
    if (mano.getCartas().size() >= 2) {
        if (revelada) {
            etiqueta += " - " + to_string(mano.calcularPuntos()) + " puntos";
            if (mano.estaBusted()) etiqueta += " - SE PASO";
            if (mano.tieneBlackjack()) etiqueta += " - BLACKJACK";
        }
        else {
            etiqueta += " - muestra " + dealer->getCartaVisible().getValor();
        }
    }
    Consola::escribirLinea(3, FILA_DEALER_ETIQUETA, etiqueta, ANCHO_MESA - 2);
    dealer->mostrarMano();
}

void BlackJackGame::dibujarZonaActiva(int indiceActivo) {
    Consola::limpiarRegion(1, FILA_ACTIVO_ETIQUETA, ANCHO_MESA, 12);
    const Jugador& jugador = *jugadores[indiceActivo];

    // Etiqueta de puntos de una mano (solo si ya tiene cartas)
    auto textoPuntos = [](const Mano& mano) {
        if (mano.getCartas().empty()) return string();
        string texto = " - " + to_string(mano.calcularPuntos()) + " puntos";
        if (mano.estaBusted()) texto += " - SE PASO";
        if (mano.tieneBlackjack()) texto += " - BLACKJACK";
        return texto;
        };

    const Mano& mano1 = jugador.getMano(0);
    if (jugador.getNumManos() == 1) {
        Consola::escribirLinea(3, FILA_ACTIVO_ETIQUETA, jugador.getNombre()
            + " (apuesta " + to_string(mano1.getApuesta()) + ")" + textoPuntos(mano1), ANCHO_MESA - 2);
        mano1.mostrarMano(false, FILA_MANO1);
    }
    else {
        Consola::escribirLinea(3, FILA_ACTIVO_ETIQUETA, jugador.getNombre() + " - mano 1 (apuesta "
            + to_string(mano1.getApuesta()) + ")" + textoPuntos(mano1), ANCHO_MESA - 2);
        mano1.mostrarMano(false, FILA_MANO1);
        const Mano& mano2 = jugador.getMano(1);
        Consola::escribirLinea(3, FILA_MANO2_ETIQUETA, "mano 2 (apuesta "
            + to_string(mano2.getApuesta()) + ")" + textoPuntos(mano2), ANCHO_MESA - 2);
        mano2.mostrarMano(false, FILA_MANO2);
    }
}

void BlackJackGame::dibujarZonaOtros(int indiceActivo) {
    Consola::limpiarRegion(1, FILA_OTROS, ANCHO_MESA, 6);
    int fila = FILA_OTROS;
    for (int i = 0; i < static_cast<int>(jugadores.size()); ++i) {
        if (i == indiceActivo) continue;
        const Jugador& jugador = *jugadores[i];
        if (jugador.getMano(0).getApuesta() == 0) continue;
        if (fila >= FILA_MENSAJE) break;
        Consola::escribirLinea(3, fila, lineaCompactaJugador(jugador), ANCHO_MESA - 2);
        ++fila;
    }
}

void BlackJackGame::dibujarMesa(int indiceActivo) {
    Consola::limpiarPantalla();
    Consola::centrar(FILA_TITULO, "B  L  A  C  K  J  A  C  K");
    dibujarZonaDealer(false);
    dibujarZonaActiva(indiceActivo);
    dibujarZonaOtros(indiceActivo);
}

// ---- Flujo del juego ----

void BlackJackGame::ejecutar() {
    bool continuar = true;
    while (continuar) {
        bool alguienPuedeJugar = false;
        for (int saldo : fichas) {
            if (saldo >= APUESTA_MINIMA) alguienPuedeJugar = true;
        }
        if (!alguienPuedeJugar) {
            cout << "\nTodos los jugadores se quedaron sin fichas suficientes para apostar.\n";
            break;
        }

        iniciarRonda();
        // Si el dealer tiene blackjack natural, iniciarRonda ya revelo y cerro la ronda.
        if (!dealer->tieneBlackjack()) {
            turnoJugador();
            turnoDealer();
        }
        determinarGanador();

        Consola::limpiarLinea(FILA_ESTADO, ANCHO_MESA);
        Consola::moverCursor(3, FILA_ESTADO);
        char respuesta = Validador::leerCaracter("¿Jugar otra ronda? (s/n): ", "sSnN");
        continuar = respuesta == 's' || respuesta == 'S';
    }

    Consola::moverCursor(3, FILA_ESTADO + 1);
    cout << "Gracias por jugar.\n";
    pausar();
}

void BlackJackGame::iniciarRonda() {
    resetearRonda();

    // Pantalla de apuestas
    Consola::limpiarPantalla();
    encabezado("NUEVA RONDA", 1);
    Consola::moverCursor(3, 5);
    for (int i = 0; i < static_cast<int>(jugadores.size()); ++i) {
        Jugador* jugador = jugadores[i];
        if (fichas[i] < APUESTA_MINIMA) {
            cout << jugador->getNombre() << " no tiene fichas suficientes (minimo "
                << APUESTA_MINIMA << ") y pasa esta ronda.\n";
            continue;
        }
        int maximo = min(APUESTA_MAXIMA, fichas[i]);
        int apuesta = Validador::leerEntero(jugador->getNombre() + " - fichas " + to_string(fichas[i])
            + ", apuesta (" + to_string(APUESTA_MINIMA) + "-" + to_string(maximo) + "): ", APUESTA_MINIMA, maximo);
        while (!jugador->hacerApuesta(apuesta)) {
            apuesta = Validador::leerEntero("Apuesta invalida. Intenta de nuevo: ", APUESTA_MINIMA, maximo);
        }
        fichas[i] -= apuesta;
    }

    // Mesa en vivo: el dealer queda arriba, el jugador activo en el centro
    // y el resto de los jugadores se ve compacto abajo.
    int activo = 0;
    for (int i = 0; i < static_cast<int>(jugadores.size()); ++i) {
        if (jugadores[i]->getMano(0).getApuesta() > 0) { activo = i; break; }
    }
    dibujarMesa(activo);

    // Reparto en vivo: cada carta aparece en su lugar sobre la mesa
    estado("Repartiendo las cartas...");
    for (int vuelta = 0; vuelta < 2; ++vuelta) {
        for (int i = 0; i < static_cast<int>(jugadores.size()); ++i) {
            Jugador* jugador = jugadores[i];
            if (jugador->getMano(0).getApuesta() == 0) continue;
            jugador->recibirCarta(mazos->tomarCarta());
            if (i == activo) dibujarZonaActiva(activo);
            else dibujarZonaOtros(activo);
            Consola::esperar(300);
        }
        dealer->recibirCarta(mazos->tomarCarta());
        dibujarZonaDealer(false);
        Consola::esperar(300);
    }

    // Seguro: solo se ofrece cuando el dealer muestra un As
    if (dealer->getCartaVisible().getValor() == "A") ofrecerSeguro();

    // El dealer revisa su carta oculta si muestra As o 10: si tiene blackjack la ronda termina
    if (dealer->debeRevisarBlackjack() && dealer->tieneBlackjack()) {
        dealer->revelarCartaOculta();
        dibujarZonaDealer(true);
        estado("El dealer tiene BLACKJACK: la ronda termina de inmediato.");
        Consola::esperar(1800);
    }
}

void BlackJackGame::ofrecerSeguro() {
    estado("El dealer muestra un AS: el seguro paga 2:1 (hasta media apuesta).");
    Consola::esperar(1500);
    for (int i = 0; i < static_cast<int>(jugadores.size()); ++i) {
        Jugador* jugador = jugadores[i];
        Mano& mano = jugador->getMano(0);
        if (mano.getApuesta() == 0) continue;
        int maximo = min(mano.getMaxSeguro(), fichas[i]);
        if (maximo <= 0) continue;
        Consola::limpiarLinea(FILA_ESTADO, ANCHO_MESA);
        Consola::moverCursor(3, FILA_ESTADO);
        int cantidad = Validador::leerEntero(jugador->getNombre() + " - seguro (0-" + to_string(maximo) + "): ", 0, maximo);
        if (cantidad > 0) {
            if (mano.hacerSeguro(cantidad)) {
                fichas[i] -= cantidad;
                estado(jugador->getNombre() + " asegura " + to_string(cantidad) + " fichas.");
            }
            else {
                estado("[!] No se pudo colocar el seguro de " + jugador->getNombre() + ".");
            }
        }
    }
}

void BlackJackGame::turnoJugador() {
    for (int j = 0; j < static_cast<int>(jugadores.size()); ++j) {
        Jugador& jugador = *jugadores[j];
        if (jugador.getMano(0).getApuesta() == 0) continue;
        // El jugador j pasa a la zona activa (sus cartas grandes) sin tocar la del dealer
        dibujarZonaActiva(j);
        dibujarZonaOtros(j);
        for (int indice = 0; indice < jugador.getNumManos(); ++indice) {
            bool doblada = false;
            bool plantado = false;
            while (!plantado) {
                // La referencia se vuelve a tomar en cada vuelta:
                // dividir puede reubicar las manos y dejaria invalida una referencia vieja.
                Mano& mano = jugador.getMano(indice);
                if (mano.getApuesta() == 0) break;
                dibujarZonaActiva(j);

                if (mano.tieneBlackjack()) {
                    estado("¡BLACKJACK de " + jugador.getNombre() + "! Esta mano no se juega.");
                    Consola::esperar(1600);
                    break;
                }
                if (mano.estaBusted()) {
                    estado(jugador.getNombre() + " se pasa de 21 con " + to_string(mano.calcularPuntos()) + " puntos.");
                    Consola::esperar(1600);
                    break;
                }
                if (doblada) {
                    estado("Apuesta doblada: " + jugador.getNombre() + " se planta con " + to_string(mano.calcularPuntos()) + " puntos.");
                    Consola::esperar(1600);
                    break;
                }

                bool puedeDoblar = mano.getCartas().size() == 2 && mano.getApuesta() > 0
                    && fichas[j] >= mano.getApuesta();
                bool puedeDividir = jugador.puedeDividir(indice)
                    && fichas[j] >= mano.getApuesta();
                string opciones = "pPsS";
                if (puedeDoblar) opciones += "dD";
                if (puedeDividir) opciones += "vV";
                string mensaje = jugador.getNombre() + ": pedir (p), plantarse (s)";
                if (puedeDoblar) mensaje += ", doblar (d)";
                if (puedeDividir) mensaje += ", dividir (v)";
                mensaje += "? ";
                Consola::limpiarLinea(FILA_ESTADO, ANCHO_MESA);
                Consola::moverCursor(3, FILA_ESTADO);
                char accion = Validador::leerCaracter(mensaje, opciones);

                if (accion == 'p' || accion == 'P') {
                    jugador.recibirCarta(mazos->tomarCarta(), indice);
                    dibujarZonaActiva(j);
                    estado(jugador.getNombre() + " pide " + mano.getCartas().back().etiqueta()
                        + " → " + to_string(mano.calcularPuntos()) + " puntos.");
                    Consola::esperar(800);
                }
                else if (accion == 'd' || accion == 'D') {
                    int apuestaOriginal = mano.getApuesta();
                    if (mano.doblarApuesta()) {
                        fichas[j] -= apuestaOriginal;
                        jugador.recibirCarta(mazos->tomarCarta(), indice);
                        dibujarZonaActiva(j);
                        estado("Apuesta doblada: " + jugador.getNombre() + " recibe "
                            + mano.getCartas().back().etiqueta() + ".");
                        Consola::esperar(1400);
                        doblada = true;
                    }
                }
                else if (accion == 'v' || accion == 'V') {
                    int apuestaOriginal = jugador.getMano(0).getApuesta();
                    if (jugador.dividir()) {
                        fichas[j] -= apuestaOriginal;
                        jugador.recibirCarta(mazos->tomarCarta(), 0);
                        jugador.recibirCarta(mazos->tomarCarta(), 1);
                        dibujarZonaActiva(j);
                        estado(jugador.getNombre() + " divide el par: una carta nueva para cada mano.");
                        Consola::esperar(1400);
                    }
                }
                else {
                    estado(jugador.getNombre() + " se planta con " + to_string(mano.calcularPuntos()) + " puntos.");
                    Consola::esperar(1000);
                    plantado = true;
                }
            }
        }
    }
}

void BlackJackGame::turnoDealer() {
    // La carta oculta se voltea en su lugar sobre la mesa
    dealer->revelarCartaOculta();
    dibujarZonaDealer(true);
    estado("El dealer revela su carta oculta: " + to_string(dealer->getMano(0).calcularPuntos()) + " puntos.");
    Consola::esperar(1200);

    // El dealer solo roba si queda al menos una mano de jugador sin pasarse de 21
    bool hayManosVivas = false;
    for (const Jugador* jugador : jugadores) {
        for (int i = 0; i < jugador->getNumManos(); ++i) {
            const Mano& mano = jugador->getMano(i);
            if (mano.getApuesta() > 0 && !mano.estaBusted()) hayManosVivas = true;
        }
    }
    if (!hayManosVivas) {
        estado("Todos los jugadores se pasaron de 21: el dealer no necesita robar.");
        Consola::esperar(1400);
        return;
    }
    while (dealer->debePedirCarta()) {
        dealer->recibirCarta(mazos->tomarCarta());
        dibujarZonaDealer(true);
        estado("El dealer roba " + dealer->getMano(0).getCartas().back().etiqueta()
            + " → " + to_string(dealer->getMano(0).calcularPuntos()) + " puntos.");
        Consola::esperar(900);
    }
    if (dealer->getMano(0).estaBusted()) estado("El dealer se pasa de 21.");
    else estado("El dealer se planta con " + to_string(dealer->getMano(0).calcularPuntos()) + " puntos.");
    Consola::esperar(1200);
}

void BlackJackGame::doblarApuesta() {
    // La accion se ejecuta dentro de turnoJugador(), donde se conoce la mano activa.
    // Se conserva el metodo publico que aparece en el UML.
}

void BlackJackGame::determinarGanador() {
    int puntosDealer = dealer->getMano(0).calcularPuntos();
    bool dealerBlackjack = dealer->tieneBlackjack();

    // Los resultados se escriben en la zona de jugadores;
    // las cartas del dealer permanecen visibles arriba.
    Consola::limpiarRegion(1, FILA_ACTIVO_ETIQUETA, ANCHO_MESA, FILA_MENSAJE - FILA_ACTIVO_ETIQUETA);
    string resumen = "RESULTADOS";
    if (dealerBlackjack) resumen += " - el dealer tiene BLACKJACK";
    else if (puntosDealer > 21) resumen += " - el dealer se paso de 21";
    else resumen += " - dealer: " + to_string(puntosDealer) + " puntos";
    Consola::escribirLinea(3, FILA_ACTIVO_ETIQUETA, resumen, ANCHO_MESA - 2);

    int fila = FILA_ACTIVO_ETIQUETA + 2;
    for (int j = 0; j < static_cast<int>(jugadores.size()); ++j) {
        Jugador* jugador = jugadores[j];
        for (int i = 0; i < jugador->getNumManos(); ++i) {
            Mano& mano = jugador->getMano(i);
            if (mano.getApuesta() == 0) continue;

            // El seguro se resuelve antes de mostrar el resultado de la mano
            string mensajeSeguro;
            if (mano.getApuestaSeguro() > 0) {
                mano.resolverSeguro(dealerBlackjack);
                fichas[j] += mano.getApuestaSeguro();// 0 si se perdio; apuesta*3 si se gano (pago 2:1)
                mensajeSeguro = dealerBlackjack
                    ? " [seguro cobrado: +" + to_string(mano.getApuestaSeguro()) + "]"
                    : " [seguro perdido]";
            }

            if (mano.estaBusted()) {
                mano.perderApuesta();
            }
            else if (mano.tieneBlackjack() && !dealerBlackjack) {
                mano.ganarBlackjack();
                fichas[j] += mano.getApuesta() + (mano.getApuesta() * 3) / 2;
            }
            else if (dealerBlackjack && mano.tieneBlackjack()) {
                mano.empatarApuesta();
                fichas[j] += mano.getApuesta();
            }
            else if (dealerBlackjack || (puntosDealer <= 21 && puntosDealer > mano.calcularPuntos())) {
                mano.perderApuesta();
            }
            else if (puntosDealer == mano.calcularPuntos()) {
                mano.empatarApuesta();
                fichas[j] += mano.getApuesta();
            }
            else {
                mano.ganarApuesta();
                fichas[j] += mano.getApuesta() * 2;
            }

            string linea = jugador->getNombre() + (jugador->getNumManos() > 1 ? " mano " + to_string(i + 1) : "")
                + ": " + textoResultado(jugador->recibirResultado(i))
                + " (" + to_string(mano.calcularPuntos()) + " puntos)" + mensajeSeguro
                + " - fichas: " + to_string(fichas[j]);
            if (fila < FILA_MENSAJE) Consola::escribirLinea(3, fila, linea, ANCHO_MESA - 2);
            ++fila;
        }
    }
    estado("Fin de la ronda.");
}

void BlackJackGame::resetearRonda() {
    for (Jugador* jugador : jugadores) jugador->limpiarManos();
    dealer->limpiarManos();
    // El zapato se rebaraja solo cuando se queda sin cartas (Mazo::tomarCarta).
}