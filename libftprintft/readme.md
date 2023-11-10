## Requisitos del ejercicio
- No implementar la gestión del buffer del `printf()` original
- Hay que usar el comando `ar` para crear la librería. El uso de `libtool` está prohibido
- `libftprintf.a` deberá ser creado en la raíz de tu repositorio
- Especificadores a implementar: %c, %s, %p, %d, %i, %u, %x, %X, %%

## Descripción, Declaración y Valor de salida
`printf()` Es una función variádicas que envía la salida formateada a *stdout*. Su propotipo es:
```c
int printf(const char *format, ...)
```

Donde *format* es el string que contiene el texto que se escribirá en la salida estándar.
Opcionalmente, puede contener etiquetas de formato que se reemplazan por los valores especificados en argumentos adicionales posteriores y se formatean según lo solicitado. El prototipo de las etiquetas de formato es el especificador `%[flags][ancho][.precisión]especificador`.

## Parametros y formato
<table>
<thead>
  <tr>
    <th colspan="3"><h3>Especificadores y salida</h3></th>
  </tr>
  <tr>
    <th>Especificador</th>
    <th>Función</th>
    <th>Salida</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>%c</td>
    <td><a href=ft_putchar.c>ft_putchar.c</a></td>
    <td>Imprime un solo carácter</td>
  </tr>
  <tr>
    <td>%s</td>
    <td><a href=ft_putstr.c>ft_putstr.c</a></td>
    <td>Imprime un string </td>
  </tr>
  <tr>
    <td>%p</td>
    <td> <a href=ft_putstr.c>ft_puststr("0X")</a> + <a href=ft_puthex.c>ft_puthex.c</a></td>
    <td>La dirección del puntero `void *` dado como argumento se imprime en formato hexadecimal</td>
  </tr>
  <tr>
    <td>%d</td>
    <td><a href=ft_putnbr.c>ft_putnbr.c</a></td>
    <td>Imprime un número decimal</td>
  </tr>
  <tr>
    <td>%i</td>
    <td><a href=ft_putnbr.c>ft_putnbr.c</a></td>
    <td>Imprime un entero en base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td><a href=ft_putunbr.c>ft_putunbr.c</a></td>
    <td>Imprime un número decimal sin signo</td>
  </tr>
  <tr>
    <td>%x</td>
    <td><a href=ft_puthex.c>ft_puthex.c</a></td>
    <td>Imprime un número hexadecimal en minúsculas</td>
  </tr>
  <tr>
    <td>%X</td>
    <td><a href=ft_puthex.c>ft_puthex.cr</a></td>
    <td>Imprime un número hexadecimal en mayúsculas</td>
  </tr>
  <tr>
    <td>%%</td>
    <td><a href=ft_putchar.c>ft_putchar.c('%')</a></td>
    <td>Para imprimir el símbolo del porcentaje</td>
  </tr>
</tbody>
<thead>