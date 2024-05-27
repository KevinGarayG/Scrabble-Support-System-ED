# Scrabble-Support-System-ED
El objetivo del presente proyecto es construir un sistema de apoyo para el juego Scrabble. El sistema se implementará como una aplicación que recibe comandos textuales, agrupados en componentes con funcionalidades específicas.El sistema esta implementado en C++. El sistema proporciona funcionalidades para gestionar un diccionario, calcular puntajes y ayudar en la búsqueda de palabras válidas.

## Estructura del Proyecto

El proyecto está organizado de la siguiente manera:

- `main.cpp`: Archivo principal que inicia la ejecución del programa.
- `files/`: Carpeta que contiene archivos de texto necesarios para el funcionamiento del sistema.
  - `diccionario.txt`: Archivo con las palabras del diccionario.
  - `letras.txt`: Archivo con las letras del alfabeto y sus respectivos puntajes.
- `include/`: Carpeta con archivos de cabecera (.h) que contienen las declaraciones de métodos y atributos de las clases.
  - `ArbolTrie.h`, `ConsoleIO.h`, `Diccionario.h`, `Letra.h`, `Palabra.h`, `Scrabble.h`, `TrieNode.h`, `GrafoDiccionario.h`, `NodoGrafo.h`
- `src/`: Carpeta con archivos fuente (.cpp) que contienen las implementaciones de los métodos y atributos de las clases.
  - `ArbolTrie.cpp`, `ConsoleIO.cpp`, `Diccionario.cpp`, `Letra.cpp`, `Palabra.cpp`, `Scrabble.cpp`, `TrieNode.cpp`, `GrafoDiccionario.cpp`, `NodoGrafo.cpp`

## Compilación

Para compilar el proyecto, utiliza el siguiente comando:

```sh
g++ --std=c++11 -g -o Scrabble main.cpp src/ConsoleIO.cpp src/Diccionario.cpp src/Letra.cpp src/Palabra.cpp src/Scrabble.cpp src/ArbolTrie.cpp src/TrieNode.cpp src/NodoGrafo.cpp src/GrafoDiccionario.cpp -I./include
```
Este comando genera un ejecutable llamado Scrabble.

## Ejecución
Para ejecutar el programa, utiliza el siguiente comando:
```sh
./Scrabble
```

## Entradas y Salidas
### Archivos de Texto
El programa requiere dos archivos de texto para funcionar:

- letras.txt: Contiene las letras del alfabeto y sus puntajes.
- diccionario.txt: Contiene las palabras del diccionario.

### Comandos del Usuario
Los usuarios interactúan con el sistema a través de la terminal. Los comandos disponibles son:

- $ ayuda: Muestra una lista de comandos disponibles.
- $ ayuda nombre_comando: Muestra la descripción de un comando específico.
- $ salir: Termina la ejecución del programa.
- $ iniciar_arbol_inverso diccionario.txt: Inicializa el árbol trie inverso con las palabras del diccionario.

## Funcionalidades
- Inicializar Árbol: Inicializa un árbol trie con palabras del diccionario.
- Buscar Palabras: Busca palabras que comienzan con un prefijo o terminan con un sufijo.
 -Calcular Puntaje: Calcula el puntaje de una palabra basada en las letras y sus valores.

## Diagrama de TADs
El proyecto incluye diagramas de Tipos Abstractos de Datos (TADs) para proporcionar una visión general de las clases y sus relaciones en el sistema.

##Autores
Kevin Garay
Arley Bernal
Felipe Garrido
