#define NOMINMAX // Evita conflictos con min y max en Windows
#include "Validador.h"
#include "Colores.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

namespace {
	// Si la entrada se cierra (EOF, por ejemplo Ctrl+Z en la consola) el juego
	// termina de forma ordenada en lugar de entrar en un bucle infinito de errores.
	void finDeEntrada() {
		cout << "\n[!] Entrada cerrada. Fin del juego.\n";
		exit(0);
	}

	// Quita espacios, tabuladores y saltos de linea de los extremos
	string recortar(const string& texto) {
		size_t inicio = 0;
		size_t fin = texto.size();
		while (inicio < fin && isspace(static_cast<unsigned char>(texto[inicio]))) ++inicio;
		while (fin > inicio && isspace(static_cast<unsigned char>(texto[fin - 1]))) --fin;
		return texto.substr(inicio, fin - inicio);
	}

	// Lee una linea completa. Si la entrada esta cerrada, termina el juego.
	void leerLinea(string& linea) {
		if (!getline(cin, linea)) finDeEntrada();
	}
}

// Valida y lee un entero dentro de un rango [minimo, maximo].
// Rechaza lineas vacias, con solo espacios/tabuladores o con texto adicional.
int Validador::leerEntero(const string& mensaje, int minimo, int maximo) {
	cout << mensaje;
	while (true) {
		string linea;
		leerLinea(linea);
		const string limpia = recortar(linea);
		if (limpia.empty()) {
			cout << Colores::ROJO << "  [!] No puedes dejarlo vacio. Ingrese un numero (" << minimo << "-" << maximo << "): " << Colores::RESET;
			continue;
		}
		istringstream flujo(limpia);
		int valor = 0;
		char sobrante = '\0';
		// Debe ser un numero y no quedar ningun caracter adicional
		if (!(flujo >> valor) || (flujo >> sobrante) || valor < minimo || valor > maximo) {
			cout << Colores::ROJO << "  [!] Entrada invalida. Ingrese un numero (" << minimo << "-" << maximo << "): " << Colores::RESET;
			continue;
		}
		return valor;
	}
}

// Valida y lee un carácter que debe estar dentro de un conjunto de opciones válidas (ej: "sSnN").
// Rechaza lineas vacias o con solo espacios/tabuladores.
char Validador::leerCaracter(const string& mensaje, const string& opcionesValidas) {
	cout << mensaje;
	while (true) {
		string linea;
		leerLinea(linea);
		const string limpia = recortar(linea);
		if (limpia.empty()) {
			cout << Colores::ROJO << "  [!] No puedes dejarlo vacio. Escribe una opcion: " << Colores::RESET;
			continue;
		}
		const char opcion = limpia[0];
		if (opcionesValidas.find(opcion) != string::npos) return opcion;
		cout << Colores::ROJO << "  [!] Opcion invalida. Intente de nuevo: " << Colores::RESET;
	}
}

// Valida y lee un texto no vacío. Los espacios y tabuladores de los extremos se
// recortan, y una linea con solo espacios/tabuladores no cuenta como contenido.
string Validador::leerTexto(const string& mensaje) {
	cout << mensaje;
	while (true) {
		string linea;
		leerLinea(linea);
		const string limpia = recortar(linea);
		if (!limpia.empty()) return limpia;
		cout << Colores::ROJO << "  [!] No puedes dejarlo vacio. Escribe un texto: " << Colores::RESET;
	}
}