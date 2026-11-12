#pragma once
#ifndef VALIDADOR_H
#define VALIDADOR_H
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Validador
{
public:
	// Lee un entero dentro de un rango [minimo, maximo]
	static int leerEntero(const string& mensaje, int minimo, int maximo);
	// Lee un carácter que coincida con una lista de caracteres válidos (ej: "sSnN")
	static char leerCaracter(const string& mensaje, const string& opcionesValidas);
	// Lee un texto que no esté vacío
	static string leerTexto(const string& mensaje);
};

#endif