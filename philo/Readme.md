# Philosophers
La idea básica del problema es modelar a un grupo de filósofos sentados alrededor de una mesa, cada uno de ellos alternando entre domir, pensar y comer. Entre cada par de filósofos hay un tenedor, y para comer, un filósofo debe tener en sus manos dos tenedores adyacentes.

Los desafíos en este problema incluyen prevenir los deadlocks (situaciones en las que los filósofos quedan bloqueados esperando tenedores que nunca se liberan), y garantizar la exclusión mutua (dos filósofos no pueden usar el mismo tenedor al mismo tiempo).

La solución a este problema generalmente implica el uso de mutex (semaforos binarios) para garantizar la exclusión mutua y sincronizar los eventos de muerte y comer de los filósofos.

### Descripcion
1. Cada filósofo es un hilo separado que puede estar en uno de tres estados: pensando, durmiendo o comiendo.
2. Se utiliza el mutex para controlar el acceso a los tenedores.
3. Un filósofo intenta adquirir los tenedores antes de comer. Si no puede obtener ambos tenedores, espera hasta obtenerlos o se muere.
4. Cuando un filósofo tiene ambos tenedores, come durante un tiempo y luego libera los tenedores.
5. Se implementan mecanismos para garantizar que los filósofos no entren en deadlock y que todos tengan la oportunidad de comer.

