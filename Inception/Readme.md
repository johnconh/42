
# Inception-42
Este proyecto busca expandir tu conocimiento en la administración de sistemas con Docker. Deberás virtualizar varias imágenes de Docker, creándolas en tu nueva máquina virtual personal.

## ¿Qué son las Máquinas Virtuales?
Las Máquinas Virtuales permiten la virtualización completa de sistemas operativos y entornos, lo que brinda flexibilidad, aislamiento, independencia de plataforma y otras ventajas, especialmente útiles en entornos de servidores y desarrollo, aunque también en otros contextos.

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

## ¿Qué son los Contenedores?
Los contenedores en Docker son unidades de ejecución livianas y autónomas que encapsulan aplicaciones y todas sus dependencias, incluidas las bibliotecas, configuraciones y archivos necesarios para ejecutarse. Los contenedores proporcionan un entorno aislado y consistente para ejecutar aplicaciones, lo que facilita la implementación, el mantenimiento y la distribución de software

## ¿Qué es un docker file?
Docker puede crear imágenes automáticamente leyendo las instrucciones de un Dockerfile. Un Dockerfile es un documento de texto que contiene todos los comandos que un usuario podría llamar en la línea de comandos para ensamblar una imagen.

## ¿Qué es un docker-compose?
Docker-compose es una herramienta para definir y ejecutar aplicaciones Docker de varios contenedores. Con Compose, utiliza un archivo YAML para configurar los servicios de su aplicación. Luego, con un solo comando, crea e inicia todos los servicios desde su configuración.