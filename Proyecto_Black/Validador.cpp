#define NOMINMAX
#include "Validador.h"
#include "Consola.h"
#include <iostream>
#include <limits>

using namespace std;

int Validador::leerEntero(const string& mensaje, int minimo, int maximo) {
    int valor = 0;
    cout << mensaje;

    while (!(cin >> valor) || valor < minimo || valor > maximo) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << Consola::ROJO << "  [!] Entrada invalida. Ingrese un numero (" << minimo << "-" << maximo << "): " << Consola::RESET;
    }

    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    return valor;
}

char Validador::leerCaracter(const string& mensaje, const string& opcionesValidas) {
    char opcion;
    cout << mensaje;

    while (true) {
        if (cin >> opcion) {
            if (opcionesValidas.find(opcion) != string::npos) {
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                return opcion;
            }
        }
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << Consola::ROJO << "  [!] Opcion invalida. Intente de nuevo: " << Consola::RESET;
    }
}

string Validador::leerTexto(const string& mensaje) {
    string texto = "";
    do {
        cout << mensaje;
        getline(cin, texto);
    } while (texto.empty());

    return texto;
}