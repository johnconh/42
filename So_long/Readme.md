
# So_long
Se trata de programar el juego utilizando el lenguaje de programación C y la biblioteca gráfica [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx), que es específica de la escuela 42.

<p align="center">
  <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/hyrule.png" alt="hyrule" />
</p>

## Caracteristicas del proyecto.

- El juego se trata de que cuando el jugador recolecta todos los objetos de mapa poder salir de ella.
- El jugador se mueve en 4 direcciones: subir, bajar, izquierda o derecha.
- El numero de movimientos se muestra en la terminal.
- El jugador no puede atravesar las paredes.
- El mapa consta de 5 componentes representados con codigo ASCIII
	- 0 es el suelo <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/suelo.png" alt="suelo" />
	- 1 es pared  <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/roca.png" alt="roca" />
	- C es el objeto <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/rupia.png" alt="rupia" />
	- E salida del mapa <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/exit.png" alt="exit" />
	- P posicion del jugador <img src="https://github.com/johnconh/42/blob/main/So_long/sprites/link_down.png" alt="link" />
- Hay que verificar que el mapa es rectangular y que este rodeado de paredes. Ademas el jugador debe poder coger todos los coleccionables y terminar el juego.
- Es obligatorio que el mapa tenga al jugador, almenos un objeto y la salida.
- Se debe mostrar los graficos con una ventana nueva, en la que su gestion debe ser limpia(minimizar, moverla, etc..), con el boton x o pulsar la tecla ESC tiene que salirse del juego.
