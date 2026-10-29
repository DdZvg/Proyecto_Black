# BlackProject — Blackjack en C++

Aplicación de consola en C++ que reúne los componentes iniciales de un juego de Blackjack: cartas, zapato de varios mazos, manos, jugadores, crupier, validación de entradas y pantallas de menú. El proyecto está organizado como solución de Visual Studio y utiliza C++20.

> **Estado del proyecto:** en desarrollo. El ejecutable corre actualmente una **demostración** del zapato de 6 mazos: crear, barajar, repartir y calcular el valor de una mano. El flujo completo de una partida todavía no está implementado.

## Características implementadas

- Representación de cartas con palo, valor, puntos, estado oculto y dibujo en consola.
- Creación y barajado aleatorio de un zapato de **N mazos de 52 cartas** (6 mazos = 312 cartas para Blackjack).
- Cálculo de puntos de una mano, con ajuste del As de 11 a 1 cuando se supera 21.
- Clases para participantes, jugador y crupier, incluida lógica básica de fichas y apuestas.
- Soporte para varias manos por participante (base para la acción de dividir).
- Menú de bienvenida, pantalla de reglas y captura validada de datos.
- Demostración en consola del reparto inicial y el cálculo de puntos.

## Tecnologías

- C++20
- Visual Studio con herramientas de desarrollo para C++ de escritorio
- Windows 10 SDK (según la configuración del proyecto)

El proyecto no declara dependencias externas de terceros. La solución utiliza configuraciones Debug y Release para Win32 y x64.

## Requisitos

1. Windows y Visual Studio con la carga de trabajo **Desarrollo para el escritorio con C++**.
2. Un compilador compatible con C++20.
3. El SDK de Windows requerido por la configuración local de Visual Studio.

## Compilar y ejecutar

1. Clona el repositorio:

   ```bash
   git clone https://github.com/DdZvg/Proyecto_Black.git
   cd Proyecto_Black
   ```

2. Abre `Proyecto_Black.slnx` en Visual Studio.
3. Selecciona la configuración **Debug** o **Release** y la plataforma **x64** (recomendado).
4. Compila la solución con **Compilar > Compilar solución** (`Ctrl+Shift+B`).
5. Ejecuta el proyecto de inicio con `F5` o `Ctrl+F5`.

## Demostración

Al ejecutar, `main.cpp` llama a `correrDemo()`, que:

1. Crea un zapato de 6 mazos (`Mazo zapato(6)`) y muestra que contiene 312 cartas.
2. Baraja el zapato.
3. Reparte dos cartas al jugador y dos al crupier (quedan 308 cartas).
4. Dibuja las manos en consola, con la primera carta del crupier oculta.
5. Muestra los puntos calculados con `Mano::calcularPuntos()`.

## Estructura del proyecto

```
Proyecto_Black/
├── Proyecto_Black.slnx              # Solución de Visual Studio
└── Proyecto_Black/
    ├── main.cpp                     # Punto de entrada y demostración
    ├── Consola.h                    # Utilidades de consola (colores, cursor, limpiar pantalla)
    ├── Menu.h / Menu.cpp            # Bienvenida, menú, reglas y solicitudes
    ├── Validador.h / Validador.cpp  # Validación de entradas de consola
    ├── Carta.h / Carta.cpp          # Modelo y representación visual de una carta
    ├── Mazo.h / Mazo.cpp            # Creación, barajado y extracción de cartas (zapato)
    ├── Mano.h / Mano.cpp            # Cartas de una mano y cálculo de puntos
    ├── Participante.h / .cpp        # Clase base de participantes
    ├── Jugador.h / Jugador.cpp      # Fichas y apuestas del jugador
    ├── Dealer.h / Dealer.cpp        # Comportamiento básico del crupier
    ├── blackJackGame.h / .cpp       # Esqueleto del flujo de juego
    ├── testMenu.h / testMenu.cpp    # Pruebas interactivas del menú
    └── testCarta.h / testCarta.cpp  # Prueba visual de cartas
```

## Reglas representadas en la interfaz

La pantalla informativa del menú describe reglas típicas de Blackjack, entre ellas los valores de las cartas, el objetivo de llegar a 21 sin excederlo, y las acciones de pedir, plantarse, doblar, dividir y contratar seguro. También presenta pagos de referencia para victorias y Blackjack natural.

> **Importante:** esa pantalla es informativa y no implica que todas esas acciones o pagos estén implementados en el motor. Varios métodos de `BlackJackGame` son únicamente esqueletos: la ejecución de rondas, los turnos, la determinación del ganador y el reinicio aún no tienen lógica funcional.

## Pruebas disponibles

- `testMenu` contiene pruebas interactivas de la bienvenida, la selección del menú, la visualización de reglas y la captura de cantidad de jugadores, nombre y cantidad de mazos.
- `testCarta` contiene una prueba visual de cartas, accesible mediante `ejecutarPruebasCarta()`.

Ninguna de las dos es invocada por el `main` actual, que ejecuta solo la demostración. El repositorio no incluye por ahora un framework de pruebas automatizadas.

## Notas de implementación

- `Mazo` recibe el número de mazos en su constructor: `Mazo(1)` genera 52 cartas y `Mazo(6)` genera el zapato de 312 cartas en un único vector, por lo que `tomarCarta()` no necesita pasar de un mazo a otro.
- `BlackJackGame` crea en su constructor un zapato de 6 mazos.
- `Mazo::tomarCarta()` no valida si el zapato está vacío; antes de llamarlo conviene revisar `cartasRestantes()`.
- Aún no se rebaraja el zapato cuando quedan pocas cartas.
- La interfaz usa caracteres Unicode y control de consola para mostrar cartas. La apariencia puede variar según la terminal y su configuración de codificación.

## Próximos pasos

- Implementar `iniciarRonda()`, `turnoJugador()`, `turnoDealer()`, `determinarGanador()` y `resetearRonda()` en `BlackJackGame`.
- Conectar el menú con el flujo de juego.
- Implementar dividir, seguro y rebarajado del zapato.
