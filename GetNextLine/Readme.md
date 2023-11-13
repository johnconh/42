# [Get Next Line]( https://harm-smits.github.io/42docs/projects/get_next_line)
Escribe una función que almacenará, en el parámetro "line", una línea que ha sido leída desde el descriptor de fichero dado.

## Requisitos
- La función debe tener el siguiente prototipo: int get_next_line(int fd, char **line);
- La función no debe tener fugas de memoria.
- Lo que llamamos "línea leída" es una sucesión de 0 a n caracteres que terminan con '\n' (código ascii 0x0a) o con End Of File (EOF).
- La cadena almacenada en el parámetro "línea" no debe contener ningún '\n'.
- El parámetro es la dirección de un puntero a un carácter que se utilizará para almacenar la línea leída.

## Valores de retorno
El valor de retorno puede ser 1, 0 o -1 dependiendo de si se ha leído una línea, cuando se ha completado la lectura (lo que significa que read ha devuelto 0), o si se ha producido un error respectivamente.

- Cuando ha llegado al final del fichero, debe almacenar el buffer actual en "línea". Si el búfer está vacío, debe almacenar una cadena vacía en "línea".
- Cuando hayas alcanzado el Fin de Fichero, tu función debe mantener 0 memoria asignada con malloc excepto el último buffer que deberías haber almacenado en "línea".
- Lo que hayas almacenado en "línea" debe ser liberable.

Llamar a su función get_next_line en un bucle le permitirá, por tanto, leer el texto disponible en un descriptor de fichero línea a línea hasta el final del texto, sin importar el tamaño del texto o de una de sus líneas. Por lo tanto, asegúrese de que su función se comporta bien cuando lee de un fichero, de la salida estándar, de una redirección, etc. Para la parte obligatoria, no se hará ninguna llamada a otra función en el descriptor de fichero entre 2 llamadas de get_next_line.

Finalmente consideramos que get_next_line tiene un comportamiento indefinido cuando se lee de un fichero binario. Usted puede hacer que esto funcione como corresponde, pero no es parte de la bonificación ni es obligatorio.