
# Inception-42
Guia de ayuda en el proyecto para poder entender la administracion de sistemas con Docker.

## La configuración de la Maquina Virtual
Puedes usar cualquier sistema operativo yo he decido por Debian10 puedes usar el que tu prefieras.
Configuracion:
- CPU 4 nucleos / 4098 RAM / 128MB en la tarjeta de video / 30GB.
- La red conectado a: Adaptador puente.
- sudo apt install vim / ssh /make, instalar en el sistema programas para trabajar en la maquina, tambien puedes instalar el git para subir el trabajo desde la maquina o cualquier otro programa que te facilite tu tabajo.
- [Instalar docker](https://docs.docker.com/engine/install/debian/)
- Instalar el docker-compose: sudo apt intall docker-compose

### Usar el SSH para trabajar desde la terminal
- Conexion por SSH: sudo networkctl status (obtener ip) y desde la terminal: ssh jdasilva@10.xx.xxx.xx
- Copiar ficheros entre las maquinas: scp [opciones] origen destino. ejemplo: spc -r /Users/jdasilva/42/Inception jdasilva@10.xx.xxx.xx:/home/jdasilva

## Comandos Docker
**`docker run`**: Crea y ejecuta un contenedor a partir de una imagen.

**`docker ps`**: Muestra la lista de todos los contenedores que estan en ejecución.

**`docker ps -a`**: Muestra las lista de todos los contenedores, incluidos los detenidos.

**`docker logs`**: Muestra  los registros de un contenedor en ejecución.

**`docker rm`**: Elimina el contendor.

**`docker rmi`**: Elimina una imagen local.

**`docker volume rm`**: Elimina un volumen.

**`docker network rm`**: Elimina la red.

**`docker exec`**: Ejecuta un comando en un contenedor en ejecución

## Docker file
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

**`restart: always`**: Configura el servicio para que siempre se reinicie si se detiene.

**`expose`**: Expone el puerto que seran expuesto en la red interna de los servicios dentro de la red del contenedor.

**`volumes`**: Esto permite que los datos sean persistentes incluso si el contenedor se detiene o se elimina.

**`networks`**: Asigna el servicio a una red.

**`env_file`**: Perminte cargar variables de entorno desde un archivo .env

# [Nginx](https://hub.docker.com/_/nginx)
- Nginx puede actuar como un servidor web que maneja solicitudes HTTP y HTTPS.

- Nginx con TLS (Transport Layer Security) es una configuración que permite habilitar conexiones seguras a través de HTTPS en el servidor web Nginx.

- Instalar tanto nginx como openssl para trabajar certificados SSL/TLS
 
- Los parámetros utilizados en el comando para generar el certificado autofirmado son:

	- x509: indica que se generará un certificado X.509 (certificado digital).

	- nodes: indica que el certificado no estará encriptado con contraseña.

	- days 365: establece la validez del certificado en 365 días.

	- newkey rsa:2048: genera un nuevo par de claves RSA de 2048 bits.

	- keyout /etc/nginx/ssl/jdasilva.key: especifica la ubicación y el nombre del archivo de clave privada generada.

	- out /etc/nginx/ssl/jdasilva.crt: especifica la ubicación y el nombre del archivo de certificado generado.

	- subj "/CN=": establece el nombre común (CN) del certificado.

### Archivo de conf de Nginx
Este bloque de configuración de Nginx se utiliza para configurar un servidor web que escucha en el puerto 443 (HTTPS) y proporciona una configuración básica para alojar un sitio web con un contenedor de WordPress y PHP-FPM.

**`server{...}`**: Define un bloque de servidor de configuración.

**`listen 443 ssl`**: Indica que este servidor debe escuchar en el puerto 443 (HTTPS) y habilita SSL.

**`server_name`**: Define el nombre del host.

**`ssl_certificate_key`**: Especifica la ubicación de la clave privada del certificado SSL que se utilizará para cifrar las comunicaciones HTTPS.

**`ssl_certificate`**: Especifica la ubicación del certificado SSL que se proporcionará al cliente durante el proceso de establecimiento de la conexión segura.

**`ssl_protocols TLSv1.3`**: Define el protocolo SSL/TLS que se utilizará. En este caso, se utiliza TLS versión 1.3 para asegurar las conexiones.

**`index`**: Define el archivo de índice que se utilizará cuando se acceda al sitio web.

**`root`**: Indica la ubicación de la raíz del sitio web, donde se encontrarán los archivos del sitio web.

**`location ~[^/]\\.php(/|$){ ... }`**: Configura cómo manejar las solicitudes que terminan en archivos PHP.
- `~[^/]\\.php(/|$)`: es una expresión regular que coincide con las solicitudes que terminan en ".php" o tienen "/php" seguido de una barra diagonal (que puede ser la ruta completa a un archivo PHP).

- `fastcgi_pass wordpress:9000`: dirige las solicitudes de archivos PHP al contenedor de WordPress a través del puerto 9000 donde se encuentra PHP-FPM.

- Las líneas siguientes (`fastcgi_index`, `fastcgi_param`, `include fastcgi_params`) son configuraciones específicas de PHP-FPM para el procesamiento de archivos PHP.

