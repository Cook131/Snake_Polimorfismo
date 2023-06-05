# Snake_Polimorfismo

Dentro de este proyecto hemos usado una serie de clases abstarctas que se heredan a otras con instancias concretas, dichos atributos que heredan usan apuntadores y ampersons direccionales para aplicar funciones (heredadas o no) de clase. Todo esto con el fin de crear un juego de serpientes y escaleras modular y parametrizable. Es decir, con la capacidad de cambiar los valores deseados para cada partida, así como funcinoar a base de grupos de funciones conectadas individualmente al juego. Como lo serían la randomización de casillas, dentro de un vector de apuntadores hacia tipos casillas; y la misma edición de dichas casillas en base a los deseos del jugador. 


Todo esto funcionando dentro de un sistema de clases compuestas, como casillas (una clase abstracta) que se itera en serpientes y escaleras (casillas especiales); o persona que se itera (o podría dicerse, se integra) al juego como jugador. El dado pertenece simplemente a cada juego como una pieza, así como el tablero y jugadores entrantes. Se manejan los últimos dos en vectores por cuestiones de fácil acceso y control ciclico por iteración (además que los apuntadores funcionan mejor en vectores).

Se añadió en la última versión la sobrecarga del operador "+" para el movimiento de jugador por dado o por casilla, así como del "<<" para impresión de turnos.