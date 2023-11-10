

## Descripción
La función [printf()](ft_printf.c) es una función de salida formateada en muchos lenguajes de programación, especialmente en C y C++. Su nombre significa "print formatted" (imprimir formateado), y se utiliza para imprimir datos en la consola o en otros flujos de salida de manera formateada. Es parte de la biblioteca estándar de entrada/salida en C y C++.

La sintaxis básica de printf() es la siguiente::
```c
int printf(const char *format, ...)
```

- format: Es una cadena de formato que especifica cómo se deben imprimir los datos. Puede contener texto normal y especificadores de formato que empiezan con el carácter %.

- ...: Indica que la función puede tomar un número variable de argumentos después de la cadena de formato. Estos argumentos son los valores que se imprimirán según las conversiones especificadas en la cadena de formato.

## Parametros
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