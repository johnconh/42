
#Inceptio-42
Esta es una guía completa del proyecto de inicio en esta página, aprenderá qué es el contenedor docker y para qué se usa y por qué lo necesitamos y también aprenderá cómo usar imágenes docker y también creará su propia imagen docker desde cero.

##¿Qué son los Contenedores?
Los contenedores son una abstracción en la capa de la aplicación que empaqueta el código y las dependencias juntos. Varios contenedores pueden ejecutarse en la misma máquina y compartir el kernel del sistema operativo con otros contenedores, cada uno ejecutándose como procesos aislados en el espacio del usuario. Los contenedores ocupan menos espacio que las máquinas virtuales (las imágenes de contenedores suelen tener un tamaño de decenas de MB), pueden manejar más aplicaciones y requieren menos máquinas virtuales y sistemas operativos.

¿Qué son las Máquinas Virtuales?
Las máquinas virtuales (VM) son una abstracción del hardware físico que convierte un servidor en muchos servidores. El hipervisor permite que varias máquinas virtuales se ejecuten en una sola máquina. Cada máquina virtual incluye una copia completa de un sistema operativo, la aplicación, los archivos binarios y las bibliotecas necesarios, lo que ocupa decenas de GB. Las máquinas virtuales también tardan en arrancar.

¿Por qué Docker y cuál es el problema que está resolviendo?
así que imaginemos un escenario anterior a la era de la ventana acoplable, tenemos probador, desarrollador y el desarrollador
solo tiene el código y funciona perfectamente bien en el sistema, pero cuando el probador toma el código y lo prueba en su máquina, simplemente no funciona y la razón podría ser muchas cosas, podría ser que el probador necesite algunas dependencias. instalarse para que el código funcione correctamente o se necesitaron agregar algunas variables de entorno, pero no existen en la máquina de prueba. eso significa que encontramos el problema ¿cómo podemos resolverlo?

Aquí cuando Docker entra en su lugar.
pero puede preguntarse por qué no usar una máquina virtual; podría ser una buena idea, pero tiene muchas desventajas, así que echemos un vistazo a las diferencias entre Docker y VM.