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
    <td><a href=ft_putchar.c>ft_print_c</a></td>
    <td>Imprime un solo carácter</td>
  </tr>
  <tr>
    <td>%s</td>
    <td><a href=ft_putstr.c>ft_print_s</a></td>
    <td>Imprime un string </td>
  </tr>
  <tr>
    <td>%i</td>
    <td><a href=ft_putnbr.c>ft_print_nbr</a></td>
    <td>Imprime un entero en base 10</td>
  </tr>
  <tr>
    <td>%u</td>
    <td><a href=ft_putunbr.c>ft_print_ulnbr</a></td>
    <td>Imprime un número en base 10 sin signo</td>
  </tr>
  <tr>
    <td>%x</td>
    <td><a href=ft_puthex.c>ft_putnbr</a></td>
    <td>Imprime un número hexadecimal en minúsculas y en mayusculas</td>
  </tr>
</tbody>
<thead>