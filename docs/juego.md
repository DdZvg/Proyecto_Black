# Cómo jugar Blackjack

## 1. Iniciar el juego

Ejecuta el programa (`Ctrl+F5` en Visual Studio).
<img width="777" height="133" alt="image" src="https://github.com/user-attachments/assets/60231f5e-4004-4d00-a036-925029daf51c" />


Primero aparece el menú principal; elige **Iniciar Nueva Partida** se pide la cantidad de jugadores (1-7), el nombre de cada uno y la cantidad de mazos. Cada jugador inicia con 1000 fichas.

## 2. Desarrollo de una ronda

Toda la ronda ocurre sobre una sola mesa que se actualiza en tiempo real, sin cambiar de pantalla:

- **Arriba** están siempre las cartas del dealer (la primera oculta).
- **En el centro** aparecen tus cartas, cada carta nueva se agrega en su lugar al pedirla, doblar o dividir.
- **Abajo** se ven, en línea compacta, las manos de los demás jugadores, y debajo los mensajes y el prompt de acción.
- Cuando llega el turno del dealer, su carta oculta **se voltea en su lugar** y sus robos aparecen uno a uno, con tus cartas todavía visibles.
- Los resultados se escriben sobre la mesa sin borrar las cartas del dealer.

1. **Apuesta**: cada jugador con fichas ingresa su apuesta entre **10 y 500 fichas** (sin superar su saldo). El máximo deja fichas libres para doblar, dividir o aplicar seguro. Con menos de 10 fichas no se puede apostar y el jugador pasa la ronda.
2. **Reparto**: las cartas se reparten una a una en vivo sobre la mesa.
3. **Seguro** (solo si el crupier muestra un As): puedes asegurar hasta la mitad de tu apuesta; paga 2:1 si el crupier tiene blackjack.
4. Si el crupier tiene blackjack natural, la ronda termina de inmediato y se muestran los resultados.
5. **Tu turno**: elige una acción por mano.

## 3. Acciones disponibles

| Tecla | Acción | Detalle |
|---|---|---|
| `p` | Pedir (Hit) | Recibes una carta adicional. |
| `s` | Plantarse (Stand) | Terminas tu turno con la puntuación actual. |
| `d` | Doblar (Double) | Duplicas tu apuesta y recibes una sola carta. |
| `v` | Dividir (Split) | Con un par: lo separas en dos manos con la misma apuesta. |

Las opciones se muestran solo cuando están disponibles (por ejemplo, doblar y dividir requieren exactamente dos cartas).

## 4. Turno del crupier

El crupier voltea su carta oculta sobre la mesa y roba, carta por carta, hasta alcanzar 17 o más, mientras sigues viendo tus cartas y las suyas. Si todos los jugadores se pasaron de 21, el crupier no necesita robar.

## 5. Resultados

- Victoria normal: pago 1:1.
- Blackjack natural (21 con dos cartas): pago 3:2.
- Empate (push): se devuelve la apuesta.
- Si te pasas de 21, pierdes la apuesta de esa mano.
- El seguro se cobra (2:1) o se pierde según el crupier tenga blackjack o no.

## 6. Siguiente ronda

Al final de cada ronda puedes jugar otra (`s`) o terminar (`n`). Si todos los jugadores se quedan sin fichas, la partida termina.
