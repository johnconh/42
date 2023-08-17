
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

**`depends_on`**: Esta sección permite definir qué servicios deben iniciarse antes de que un servicio en particular pueda iniciarse.


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

 # [Mariadb](https://hub.docker.com/_/mariadb)
 - Mariadb será la base de datos para almacenar la información sibre nuestros usuarios y configuraciones de wordpress

 - Crea un script para cambiar lineas en el archivo /etc/mysql/mariadb.conf.d/50-server.cnf correspondientes, establece el puerto 3306 y ortogue el derecho de ejecutar mysql

 - Crea otro script para generar la base de datos y nuestro usuario, darle acceso a la base de datos y FLUSH PRIVILEGES que aplica todos lo cambios en los permisos sean efectivos de inmediato.

 - En el dockerfile ejecutar el script que modifica el archivo 50-server.cnf y con el CMD, usar el script de la base de datos para generar un archivo .sql que se iniciara con el comando myqlsd --init-file=

 # [Wordpress](https://hub.docker.com/_/wordpress)
 - WordPress es una plataforma de gestión de contenido basado en PHP y MySQL que te permite crear y administrar sitios web, bloqs y aplicaciones de manera fácil y rápida.

 - PHP-FPM (PHP FastCGI Process Manager) es una implementación del protocolo FastCGI para PHP, que permite manejar eficientemente las solicitudes de PHP en un servidor web. En el contexto de WordPress, PHP-FPM se utiliza para gestionar y ejecutar scripts PHP de manera más eficiente y escalable.

 - Instalar los paquetes curl wget netcat tar
	- `curl`: Es una herramienta de línea de comandos para transferir datos con URL. Puedes usarlo para descargar archivos desde la web, realizar solicitudes HTTP, realizar pruebas de conectividad y más.
	
	- `wget`: Es otra herramienta para descargar archivos desde la web. Es similar a cURL pero más especializado en descargas.

	- `netcat`: También conocido como nc, es una utilidad de red que puede utilizarse para leer o escribir datos a través de conexiones de red, como sockets TCP o UDP. Es muy versátil y se utiliza para pruebas de conectividad, transferencias de archivos, escaneo de puertos y más.

	- `tar`: Es una herramienta para crear, ver y extraer archivos comprimidos y archivados en formato tar. Se usa comúnmente para comprimir y descomprimir archivos y directorios.

 - Descarga el wp-cli.phar desde el repositorio de GitHub de WP-CLI. WP-CLI es una herramienta de línea de comandos para administrar instalaciones de WordPress. no olvides de darle los permiso para que sea ejecutable.

 - Crear un script para crear el directorio /var/www/html acceder a el, descargar el WP en español, configurar el WP para que trabaje con mariadb y usar WP-CLI para configurarlo. Que el script tenga los permisos paea que pueda ser ejecutado.

- Posiblemente en el archivo /etc/php/7.3/fpm/php-fpm.conf, tengas que cabiar la ruta del pid para poder reniciar el servicio por /var/run/php-fpm7.3.pid/ 

### www.conf
El archivo www.conf permite ajustar la configuración del servidor PHP-FPM para optimizar el rendimiento y la eficiencia en el procesamiento de solicitudes de PHP generadas por WordPress. Copiar el archivo www.conf en /etc/php/7.3/fpm/pool.d/

- Bajate algun tema de wordpress para poder ver si la pagina cambia de diseño, vendra bien para la correción, esto es optativo.

- En el dockerfile ejecutar el script y luego ejecutar el script, inicia el proceso `php-fpm7.3` en modo continuo (-F), lo que significa que el proceso se ejecutará en primer plano y no se desvinculará del terminal.