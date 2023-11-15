# Pipex
El objetivo principal del ejercicio podría ser redirigir la salida de un comando ejecutado en un proceso hijo al proceso padre, y luego pasar esa salida como entrada a otro comando.
El programa sera ejecutado de la siguiente manera: `./pipex file1 cmd1 cmd2 file2`, que debe ser equivalente al comando shell `< file1 cmd1 | cmd2 > file2`.

## Su funcionamiento
- El programa debe crear dos procesos hijos.
- El primer hijo ejecuta el primer comando y redirige su salida al extremo de escritura de una tubería.
- El segundo hijo ejecuta el segundo comando y redirige su entrada al extremo de lectura de la misma tubería.
- El proceso padre lee de la tubería y realiza otras operaciones según sea necesario.

## Redireccion de archivos

- La entrada del primer comando se lee desde un archivo.
- La salida del segundo comando se escribe en un archivo.

## Pasos Generales:
1. Crear una tubería utilizando la función pipe.
2. Crear el primer proceso hijo (fork) y redirigir la salida al extremo de escritura de la tubería.
3. Crear el segundo proceso hijo (fork) y redirigir la entrada al extremo de lectura de la tubería.
4. En el proceso padre, cerrar los extremos no necesarios de la tubería y realizar operaciones adicionales si es necesario.
5. Esperar a que ambos procesos hijos terminen (waitpid).

