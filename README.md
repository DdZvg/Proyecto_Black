# BlackProject — Blackjack en C++

Aplicación de consola en C++ que reúne los componentes iniciales de un juego de Blackjack: cartas, mazos, manos, jugadores, crupier, validación de entradas y pantallas de menú. El proyecto está organizado como solución de Visual Studio y utiliza C++20.


Estado del proyecto: en desarrollo. Actualmente el ejecutable inicia una batería interactiva de pruebas del menú. La estructura del juego y varios componentes ya están definidos, pero el flujo integral de una partida todavía no está implementado.

Características implementadas

•
Representación de cartas con palo, valor, puntos, estado oculto y dibujo en consola.

•
Creación y barajado aleatorio de un mazo estándar de 52 cartas.

•
Cálculo de puntos de una mano, con ajuste del As de 11 a 1 cuando se supera 21.

•
Clases para participantes, jugador y crupier, incluida lógica básica de fichas y apuestas.

•
Menú de bienvenida, pantalla de reglas y captura validada de algunos datos.

•
Pruebas interactivas de las pantallas y solicitudes del menú.

Tecnologías

•
C++20

•
Visual Studio con herramientas de desarrollo para C++ de escritorio

•
Windows 10 SDK (según la configuración del proyecto)

El proyecto no declara dependencias externas de terceros. La solución utiliza configuraciones Debug y Release para Win32 y x64.

Requisitos

1.
Windows y Visual Studio con la carga de trabajo Desarrollo para el escritorio con C++.

2.
Un compilador compatible con C++20.

3.
El SDK de Windows requerido por la configuración local de Visual Studio.

Compilar y ejecutar

1.
Clona el repositorio:

Bash


git clone https://github.com/DdZvg/Proyecto_Black.git
cd Proyecto_Black





2.
Abre Proyecto_Black.slnx en Visual Studio.

3.
Selecciona la configuración Debug o Release y la plataforma x64 (recomendado).

4.
Compila la solución con Compilar > Compilar solución (Ctrl+Shift+B).

5.
Ejecuta el proyecto de inicio con F5 o Ctrl+F5.



Proyecto_Black/
├── Proyecto_Black.slnx              # Solución de Visual Studio
└── Proyecto_Black/
    ├── main.cpp                     # Punto de entrada y selección de modo de pruebas
    ├── Menu.h / Menu.cpp            # Bienvenida, menú, reglas y solicitudes
    ├── Validador.h / Validador.cpp  # Validación de entradas de consola
    ├── Carta.h / Carta.cpp          # Modelo y representación visual de una carta
    ├── Mazo.h / Mazo.cpp            # Creación, barajado y extracción de cartas
    ├── Mano.h / Mano.cpp            # Cartas de una mano y cálculo de puntos
    ├── Participante.h / .cpp        # Clase base de participantes
    ├── Jugador.h / Jugador.cpp      # Fichas y apuestas del jugador
    ├── Dealer.h / Dealer.cpp        # Comportamiento básico del crupier
    ├── blackJackGame.h / .cpp       # Esqueleto del flujo de juego
    ├── testMenu.h / testMenu.cpp    # Pruebas interactivas del menú
    └── testCarta.h / testCarta.cpp  # Prueba visual de cartas



Reglas representadas en la interfaz

La pantalla informativa del menú describe reglas típicas de Blackjack, entre ellas los valores de las cartas, el objetivo de llegar a 21 sin excederlo, y las acciones de pedir, plantarse, doblar, dividir y contratar seguro. También presenta pagos de referencia para victorias y Blackjack natural.

Importante: esa pantalla es informativa y no implica que todas esas acciones o pagos estén implementados en el motor. En el estado actual, varios métodos de BlackJackGame son únicamente esqueletos; por ejemplo, la ejecución de rondas, los turnos, la determinación del ganador y el reinicio aún no tienen lógica funcional.

Pruebas disponibles

Las pruebas del menú se ejecutan desde el programa al iniciar, mientras MODO_TEST_MENU permanezca en true. Incluyen la bienvenida, la selección del menú, la visualización de reglas y la captura de cantidad de jugadores, nombre y cantidad de mazos.

Existe además una prueba visual de cartas en testCarta.cpp, accesible mediante ejecutarPruebasCarta(). No está seleccionada por el main actual. El repositorio no incluye por ahora un framework de pruebas automatizadas.

Notas de implementación

•
Mazo representa un único mazo estándar de 52 cartas. Aunque la pantalla de reglas menciona un calzado de seis barajas, esa funcionalidad no está conectada actualmente al motor.

•
BlackJackGame crea un mazo en su constructor; la inicialización de varias barajas debe completarse si se requiere esa modalidad.

•
La interfaz usa caracteres Unicode y control de consola para mostrar cartas y arte ASCII. La apariencia puede variar según la terminal y su configuración de codificación.

