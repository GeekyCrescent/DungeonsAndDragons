# Dungeon Explorer

Dungeon Explorer es un proyecto de estructuras de datos basado en el universo de **Dungeons and Dragons (D&D)**. Este sistema organiza, gestiona y recupera información clave para optimizar la experiencia de juego en partidas de D&D, tanto para los jugadores como para los Dungeon Masters.

## Descripción del Proyecto

**Dungeon Explorer** crea un soporte integral que permite a los jugadores diseñar y personalizar a sus personajes con clases únicas, acceder a un códice de criaturas, y avanzar en calabozos generados con nodos y aristas mediante grafos. La funcionalidad principal del sistema se centra en el manejo de hechizos, habilidades, combates y progresión del personaje.

## Características Clave

1. **Códice de Criaturas:**  
   Una lista ligada almacena criaturas del archivo `monsters_patched.csv`, cada una con atributos como nombre, nivel de desafío (cr), tipo, tamaño, clase de armadura (ac), puntos de golpe (hp), y alineamiento. El códice permite el acceso rápido a los Dungeon Masters para uso durante el juego.

2. **Creación y Personalización del Jugador:**  
   Los jugadores pueden crear un personaje personalizado con atributos específicos como nombre, raza y clase. Cada clase viene con un conjunto único de 15 hechizos y habilidades. Esto brinda flexibilidad en la personalización y un estilo de juego diferenciado para cada personaje.

3. **Repositorio de Libros de Hechizos y Habilidades:**  
   El repositorio de hechizos y habilidades se organiza en listas ligadas, específicas para cada clase del personaje. Cada clase (por ejemplo, Guerrero, Mago, Hechicero) tiene su propio conjunto de habilidades, que el jugador puede personalizar y gestionar de acuerdo a sus preferencias.

4. **Mapa de Calabozos y Seguimiento de Ubicación (Próximamente):**  
   Se utilizarán grafos para representar hasta 20 calabozos interconectados. Cada calabozo contendrá un monstruo del códice de criaturas asignado aleatoriamente. Los jugadores explorarán estos calabozos enfrentando monstruos y recolectando recompensas.

5. **Generador de Encuentros Aleatorios:**  
   Un algoritmo de encuentros aleatorios permite al jugador enfrentar monstruos mientras explora calabozos. La vida del jugador (hp) y los puntos de vida (lp) cambian según el combate y el uso de hechizos. Los encuentros son determinados mediante tiradas de dados y el sistema termina cuando el jugador queda sin vida.

---

## To-Do List

Aquí está la lista de pasos para implementar **Dungeon Explorer**.

### Paso 1: Códice de Criaturas
- [ ] Crear una estructura o clase `Monstruo` con atributos cargados del archivo `monsters_patched.csv`.
- [ ] Implementar una lista ligada para almacenar y organizar los monstruos.
- [ ] Añadir métodos para acceder y gestionar la información de las criaturas en la lista.

### Paso 2: Creación y Personalización del Jugador
- [ ] Crear una clase o estructura `Jugador` que permita al usuario ingresar su nombre, seleccionar su raza y elegir su clase (como Guerrero, Mago, Hechicero).
- [ ] Diseñar cada clase con un conjunto específico de 15 hechizos y habilidades, almacenadas en una lista ligada.
- [ ] Agregar métodos para gestionar atributos del jugador, incluyendo `hp`, `lp`, y una lista de monstruos derrotados.
- [ ] Implementar personalización para aumentar `hp` al ganar batallas y reducir `lp` al recibir ataques.

### Paso 3: Repositorio de Hechizos y Habilidades
- [ ] Crear una estructura o clase `HechizoHabilidad` con atributos como nombre, tipo, efecto, y costo de mana.
- [ ] Implementar listas ligadas específicas para almacenar los 15 hechizos y habilidades de cada clase.
- [ ] Desarrollar métodos de búsqueda y filtrado de hechizos para una selección rápida durante el juego.

### Paso 4: Generador de Encuentros Aleatorios
- [ ] Crear el generador de encuentros que permita al jugador moverse por los calabozos (simulado al principio sin grafos).
- [ ] Implementar un sistema de dados virtual para:
   - Tirar un dado de 10 caras para el daño del monstruo y del jugador.
   - Usar un dado de 8 caras para recuperar puntos de vida (lp) tras una victoria.
- [ ] Programar el flujo de combate:
   - Verificar si el monstruo en el calabozo está vivo antes de enfrentarlo.
   - Ejecutar ataques entre el jugador y el monstruo.
   - Añadir el monstruo a la lista de derrotados si el jugador sobrevive.

### Paso 5: Mapa de Calabozos y Seguimiento de Ubicación (Próximamente)
- [ ] Implementar una estructura de grafo para representar hasta 20 calabozos.
- [ ] Asignar aleatoriamente monstruos del códice en cada nodo del grafo.
- [ ] Implementar un sistema de aristas entre los nodos que permita al jugador navegar entre calabozos.

### Paso 6: Finalización del Juego y Reporte Final
- [ ] Implementar la condición de finalización cuando el jugador queda sin puntos de vida (hp).
- [ ] Crear un método que muestre un resumen al final del juego, incluyendo:
   - Lista de monstruos derrotados ordenados por nombre.
   - Nombre, raza y clase del jugador.
   - Número de calabozos conquistados.

### Paso 7: Documentación y Pruebas
- [ ] Documentar las clases, métodos y estructuras de datos utilizadas.
- [ ] Realizar pruebas en cada componente para garantizar la consistencia de las listas ligadas, hechizos y habilidades, y encuentros.
- [ ] Probar la personalización del personaje y el flujo del juego en diferentes escenarios.

---

## Contribución
Las contribuciones son bienvenidas. Puedes abrir una "issue" para reportar problemas o sugerir mejoras, o bien, enviar un "pull request" con nuevas características o correcciones.

## Licencia
Este proyecto se distribuye bajo la licencia MIT.

---

Este README brinda una visión detallada del proyecto **Dungeon Explorer** y una estructura organizada para su desarrollo en GitHub.
