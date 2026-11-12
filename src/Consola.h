#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <chrono>
#include <thread>
#endif

using namespace std;

namespace Consola {

    const string CODIGO_RESTABLECER_FORMATO = "\033[0m";

    inline void inicializar() {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        // Activa el procesamiento de secuencias ANSI (colores y movimiento del cursor).
        // La consola clasica de Windows no lo trae habilitado por defecto y sin esto
        // los movimientos de cursor se imprimen como caracteres raros.
        HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
        if (salida != INVALID_HANDLE_VALUE) {
            DWORD modo = 0;
            if (GetConsoleMode(salida, &modo)) {
                SetConsoleMode(salida, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
            }
        }
#endif
    }

    inline void limpiarPantalla() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    inline void moverCursor(int x, int y) {
        cout << "\033[" << y << ";" << x << "H";
    }

    inline void escribirEn(int x, int y, const string& texto) {
        moverCursor(x, y);
        cout << texto;
    }

    inline void limpiarLinea(int y, int ancho = 78) {
        moverCursor(1, y);
        cout << string(ancho, ' ');
    }

    // Borra un rectangulo de la pantalla sin tocar el resto de la mesa.
    // Sirve para actualizar una zona (una mano, el dealer) sin limpiar todo.
    inline void limpiarRegion(int x, int y, int ancho, int alto) {
        const string espacios(static_cast<size_t>(ancho), ' ');
        for (int fila = 0; fila < alto; ++fila) escribirEn(x, y + fila, espacios);
    }

    inline void centrar(int y, const string& texto, int ancho = 78) {
        int espacios = (ancho - static_cast<int>(texto.size())) / 2;
        if (espacios < 0) espacios = 0;
        escribirEn(1 + espacios, y, texto);
    }

    // Pausa breve para animar el reparto de cartas en vivo
    inline void esperar(int milisegundos) {
#ifdef _WIN32
        Sleep(milisegundos);
#else
        std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
#endif
    }

}