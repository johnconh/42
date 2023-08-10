
# Inception-42
Este proyecto busca expandir tu conocimiento en la administración de sistemas con Docker. Deberás virtualizar varias imágenes de Docker, creándolas en tu nueva máquina virtual personal.

## La configuración de la Maquina Virtual
Puedes usar cualquier sistema operativo yo he decido por Debian10 puedes usar el que tu prefieras.
La configuracion que tengo de mi maquina virtual es la siguiente:
- CPU 4 nucleos / 4098 RAM / 128MB en la tarjeta de video / 30GB.
- La red conectado a: Adaptador puente.
- sudo apt install vim / ssh /make, instalar en el sistema programas para trabajar en la maquina, tambien puedes instalar el git para subir el trabajo desde la maquina o cualquier otro programa que te facilite tu tabajo, yo opte por estos.
- [Instalar del docker compose](https://docs.docker.com/engine/install/debian/)
- Instalar el docker-compose: sudo apt intall docker-compose
### Usar el SSH para trabajar desde la terminal
- Conexion por SSH: sudo networkctl status (obtener ip) y desde la terminal: ssh jdasilva@10.xx.xxx.xx
- Copiar ficheros entre las maquinas: scp [opciones] origen destino. ejemplo: spc -r /Users/jdasilva/42/Inception jdasilva@10.xx.xxx.xx:/home/jdasilva

### Comandos Docker
**`docker run`**: Crea y ejecuta un contenedor a partir de una imagen.
**`docker ps`**: Muestra la lista de todos los contenedores que estan en ejecución.
**`docker ps -a`**: Muestra las lista de todos los contenedores, incluidos los detenidos 
**`docker logs`**: Muestra  los registros de un contenedor en ejecución.
**`docker rm`**: Elimina el contendor.
**`docker rmi`**: Elimina una imagen local.
**`docker volume rm`**: Elimina un volumen.
**`docker network rm`**: Elimina la red.
**`docker exec`**: Ejecuta un comando en un contenedor en ejecución

### Docker file
- Un Dockerfile es un documento de texto que contiene todos los comandos que un usuario podría llamar en la línea de comandos para ensamblar una imagen.

**`FROM`**: Este comando especifica la imagen base desde la cual se construirá la nueva imagen. Es el punto de partida para tu imagen.
**`RUN`**: Este comando ejecuta comandos dentro de la imagen mientras se está construyendo. Se utiliza para instalar paquetes, configurar software, o realizar otras acciones durante la construcción.
**`COPY o ADD`**: Estos comandos copian archivos desde el sistema de archivos local al sistema de archivos de la imagen. COPY se usa para copiar archivos locales, mientras que ADD puede también descargar archivos desde una URL o extraer archivos comprimidos.
**`EXPOSE`**: Este comando indica los puertos en los que la imagen estará escuchando en tiempo de ejecución.
**`CMD`**: Este comando define el comando predeterminado que se ejecutará cuando se inicie un contenedor basado en la imagen. Puede ser sobrescrito al iniciar el contenedor.

## Docker-compose
- Docker-compose es una herramienta para definir y ejecutar aplicaciones Docker de varios contenedores.

**`version:`**: Indica la versión de la sintaxis del archivo de composición de Docker.
**`services`**: Esta seccion define los servicios de contenedor que se ejecutarán.
**`container_name`**: Establece el nombre del contenedor.
**`build`**: Indica que la imagen de este servicio debe construirse a partir de un Dockerfile.
**`image`**: La imagen Docker que se utilizara para el servicio.
**`restart: always`**: Configura l servicio para que siempre se reinicie si se detiene.
**`expose`**: Expone el puerto que seran expuesto en la red interna de los servicios dentro de la red del contenedor.
**`volumes`**: Esto permite que los datos sean persistentes incluso si el contenedor se detiene o se elimina.
**`networks`**: Asigna el servicio a una red.
**`env_file`**: Perminte cargar variables de entorno desde un archivo .env

