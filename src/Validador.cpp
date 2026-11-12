#define NOMINMAX // Evita conflictos con min y max en Windows
#include "Validador.h"
#include "Colores.h"
#include <iostream>
#include <limits>

using namespace std;
// Valida y lee un entero dentro de un rango específico
int Validador::leerEntero(const string& mensaje, int minimo, int maximo) {
    int valor = 0;
    cout << mensaje;
	// Bucle hasta que el usuario ingrese un valor válido
    while (!(cin >> valor) || valor < minimo || valor > maximo) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << Colores::ROJO << "  [!] Entrada invalida. Ingrese un numero (" << minimo << "-" << maximo << "): " << Colores::RESET;
    }
	// Limpiar el buffer de entrada antes de retornar el valor
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    return valor;
}
// Valida y lee un carácter que debe estar dentro de un conjunto de opciones válidas
char Validador::leerCaracter(const string& mensaje, const string& opcionesValidas) {
    char opcion;
    cout << mensaje;
	// Bucle hasta que el usuario ingrese un carácter válido
    while (true) {
        if (cin >> opcion) {
            if (opcionesValidas.find(opcion) != string::npos) {
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                return opcion;
            }
        }
		// Limpiar el buffer de entrada y mostrar mensaje de error
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << Colores::ROJO << "  [!] Opcion invalida. Intente de nuevo: " << Colores::RESET;
    }
}
// Valida y lee un texto no vacío
string Validador::leerTexto(const string& mensaje) {
    string texto = "";
    do {
        cout << mensaje;
        getline(cin, texto);
    } while (texto.empty());

    return texto;
}