## Push Swap
El objetivo es utilizar dos pilas, llamadas A y B, y ordenar los números en la pila A de manera ascendente utilizando un conjunto limitado de operaciones.

La pila A debe tener los numero ordenados y la pila B tiene q estar vacia, lo numeros no se repiten.

Para ordenar las pilas se utilizan los siguientes comandos:

| Comando | Descripcion 																									  |
|-----------------------------------------------------------------------------------------------------------------------------|
| sa	|	Swap a Intercambia los primelos elementos de la pila A.															  |
| sb	|	Swap b Intercambia los primelos elementos de la pila B.						|
| ss	|   sa y sb a la vez. |
| pa	|	Push a Toma el primer elemento de la pila B y lo coloca encima de la pila A. |
| pb	|	Push b Toma el primer elemento de la pila A y lo coloca encima de la pila B. |
| ra	|	Rotate a Desplaza hacia arriba todos los elementos de la pila A, el primer elemento se convierte en el ultimo. |
| rb    |	Rotate b Desplaza hacia arriba todos los elementos de la pila B, el primer elemento se convierte en el ultimo. |
| rr	|	ra y ra a la vez. |
| rra	|	Reverse rotate a Desplaza hacia abajo todos los  elementos de la pila A, el ultimo elemento es el primero. |
| rrb	|	Reverse rotate a Desplaza hacia abajo todos los  elementos de la pila B, el ultimo elemento es el primero. |
| rrr	|	rra y rrb a la vez. |

Yo elegido usar el metodo [Radix sort](https://www.geeksforgeeks.org/radix-sort/), es un metodo muy sencillo que en este proyecto sacas el numero de movimientos suficientes para aprovar el proyecto, no es un 100% pero si te ves capaz te dejo un [link](https://github.com/ampuEus/42School/blob/main/cursus/lvl2/push_swap/LEEME.md) de un compañero que tiene hasta el bonus(si tambien te interesa).