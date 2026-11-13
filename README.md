# BlackProject - Grupo #2


Juego de Blackjack para consola desarrollado en C++ como proyecto final del curso Programación 1 en la Universidad Nacional de Costa Rica (Sede Regional Chorotega, Campus Nicoya).

El programa corre en la terminal y reproduce las reglas de una mesa de casino: admite de 1 a 7 jugadores simultáneos, barajas configurables (zapato de N mazos), apuestas con fichas, reparto en vivo y decisiones individuales por turno.

---

## Qué incluye el juego

- **Mesa:** de 1 a 7 participantes por partida, cada uno con saldo inicial de 1000 fichas y registro de nombre.
- **Zapato configurable:** barajado de 1 a N mazos de 52 cartas (por ejemplo, 6 mazos para 312 cartas). Se mezcla automáticamente al inicio y se rebaraja cuando se agotan las cartas.
- **Acciones completas de Blackjack:**
  - *Pedir carta* (`p`) y *Plantarse* (`s`).
  - *Doblar apuesta* (`d`): disponible en la mano inicial de dos cartas si el jugador cuenta con saldo suficiente; recibe exactamente una carta adicional y se planta.
  - *Dividir pares* (`v`): si las dos primeras cartas tienen el mismo valor numérico, separa la jugada en dos manos independientes con apuestas iguales.
  - *Seguro*: ofrecido a los jugadores cuando la carta visible del dealer es un As. Paga 2:1 si el dealer completa Blackjack natural.
- **Lógica del dealer:** juega con una carta oculta hasta el final de la ronda y pide carta obligatoriamente mientras sume menos de 17 puntos.
- **Pagos de ronda:** victoria estándar 1:1, Blackjack natural 3:2 y devolución de la apuesta en empates.
- **Interfaz en consola:** dibujo de cartas en bloques con palos (♠, ♥, ♦, ♣), colores diferenciados por palo y refresco posicionado mediante códigos de escape ANSI.
- **Validación de entradas:** control de tipos y rangos en números y caracteres para evitar cierres abruptos por entradas no válidas.

---

## Tecnologías y requisitos

- **Lenguaje:** C++ (estándar C++17 / C++20).
- **Entorno de compilación:** Visual Studio 2022 con la carga de trabajo *Desarrollo para el escritorio con C++*.
- **Sistema operativo:** Windows (utiliza `SetConsoleOutputCP(CP_UTF8)` y `ENABLE_VIRTUAL_TERMINAL_PROCESSING` para caracteres y colores ANSI en la consola).
- **Control de versiones:** Git y GitHub.

No requiere librerías externas de terceros; se apoya únicamente en la biblioteca estándar de C++ (`<vector>`, `<string>`, `<algorithm>`, `<iostream>`, `<limits>`) y encabezados básicos del sistema para la consola.

---

## Estructura del código

Los archivos fuente se encuentran en el directorio `src/`:

| Archivo | Responsabilidad |
| :--- | :--- |
| `main.cpp` | Punto de entrada, inicialización de consola y bucle del menú principal. |
| `blackJackGame.h` / `.cpp` | Coordinador de la partida: administración de rondas, turnos, pagos y dibujo de la mesa. |
| `Participante.h` / `.cpp` | Clase base abstracta que gestiona el nombre y la colección de manos. |
| `Jugador.h` / `.cpp` | Hereda de `Participante`; gestiona la lógica de juego del usuario y la división de manos. |
| `Dealer.h` / `.cpp` | Hereda de `Participante`; administra la carta oculta y las reglas fijas de la banca (pedir con <17). |
| `Mano.h` / `.cpp` | Contiene las cartas de una jugada, calcula puntos (ajuste dinámico del As entre 11 y 1) y almacena apuestas. |
| `Mazo.h` / `.cpp` | Genera las barajas, las mezcla aleatoriamente y entrega cartas. |
| `Carta.h` / `.cpp` | Representa el palo, valor, puntos, visibilidad y el dibujo individual en bloques de texto. |
| `Menu.h` / `.cpp` | Muestra la bienvenida, pantalla de reglas y recopila la configuración inicial de la partida. |
| `Validador.h` / `.cpp` | Métodos estáticos para leer enteros, caracteres y cadenas con validación de rangos. |
| `Consola.h` | Control del cursor en pantalla, limpieza de zonas específicas y habilitación de secuencias ANSI. |
| `Colores.h` | Constantes de escape ANSI para colores de texto en terminal. |
| `ResultadoMano.h` | Enumeración con los estados de cierre de mano (`Pendiente`, `Gana`, `BlackJack`, `Empata`, `Pierde`). |

---

## Cómo compilar y ejecutar

---
Para compilar consulta **`docs/compilacion.md`**
Además Para una guía de como jugar consulta **`docs/juego.md`**
 


