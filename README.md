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

- **$ ayuda:** Muestra una lista de comandos disponibles.
  
- **$ ayuda *nombre_comando*:** Muestra la descripción de un comando específico.
  
- **$ salir:** Termina la ejecución del programa.
  
- **$ inicializar *diccionario.txt*:** inicia el diicionario en el idiama del diccionario.txt **(necesario para comandos: _puntaje, grafo_palabras y posibles_palabras_)**
  
- **$ inicializar_inverso *diccionario.txt*:** inicia un ddicionario pero con lñas palabras invertidas. **(necesario para comandos: _puntaje, grafo_palabras y posibles_palabras_)**
  
- **$ puntaje palabra *palabra*:** conocer el puntaje de la palbra ingresada.
  
- **$ iniciar_arbol _diccionario.txt_:** Inicializa el árbol trie con las palabras del diccionario. **(necesario para comandos: _palabras_por_prefijo y palabras_por_subfijo_)**
  
- **$ iniciar_arbol_inverso _diccionario.txt_:** Inicializa el árbol trie inverso con las palabras del diccionario. **(necesario para comandos:  _palabras_por_prefijo y palabras_por_subfijo_)**
  
- **$ palabras_por_prefijo _prefijo_:** Encuentra palabras que tengan el prefijo ingresado por el usuario.
  
- **$ palabras_por_sufijo _sufijo_:** Encuentra palabras que tengan el sufijo ingresado por el usuario.
  
- **$ grafo_de_palabras:** inicia un grafo que contiene palabras (nodos). Las palabras se conectan si tienen un caracter de diferencia. **(necesario para comandos: _posibles_plabras_)**
  
- **$ posibles_palabras _letras_:** encuentra las posibles palabras que puedan armarse con las fichas (caracteres) que ingrese el jugador. Admite un maximo de un comodin (?).

## Funcionalidades
- **Buscar Palabras:** Busca palabras que comienzan con un prefijo o terminan con un sufijo.
  
- **Calcular Puntaje:** Calcula el puntaje de una palabra basada en las letras y sus valores.
  
- **Posibles palabras:** Encuantra las posibles palabras o combinaciones que se puedan armar con las fichas (cadena de caracteres) ingresada por el usuario.

## Diagrama de TADs
El proyecto incluye diagramas de Tipos Abstractos de Datos (TADs) para proporcionar una visión general de las clases y sus relaciones en el sistema.

1. Letra
Descripción: Almacena información sobre una letra y su puntaje en el juego Scrabble.
- Atributos:
	-Letra: Carácter que representa letra de la palabra
  -Puntos: Un entero que representa el puntaje de cada letra
  
- Operaciones:
  -Letra(): Constructor que inicia la letra con carácter y el puntaje.
  -Letra (Caracter): Constructor que inicia la letra con un carácter específico y puntaje 0.
  -FijarLetra(caracter): Muestra el carácter que representa la letra.
  -ObtenerLetra(): Devuelve el carácter que representa la letra.
  -FijarPunto(Punto): Establece puntaje a la letra.
  -ObtenerPunto(punto): Devuelve Puntaje letra.
  -Operador(letra): Compara letra depende de su carácter.

2. Scrabble
Descripción: Este ya representa el juego scrabble y gestiona las letras, el diccionario de palabras y realizar operaciones del juego (puntaje, buscar palabras).
- Atributos:
•	Letras: Lista que representa las letras con su respectivo puntaje.
•	Diccionario: Almacena las palabras del juego.
•	Diccinverso: diccionario inverso de las palabras.
•	Arbol: Almacena las palabras del diccionario en un árbol trie.
•	Arbolinverso: Almacena las palabras del diccionario inverso en un trie.
- Operaciones:
•	Scrabble(): Constructor que inicializa los atributos del scrabble.
•	InicializarDiccionario(nombreArchivo, invertir): Inicializa el diccionario.
•	PuntajePalabra(palabra): Calcula el puntaje de una palabra dada.
•	InicializarArbol(nombreArchivo, invertir): Inicializa el árbol con las palabras del diccionario.
•	BuscarPalabras(palabra, esPrefijo): Busca la lista de palabras que inician con un prefijo o sufijo.
•	Calculate_score(palabra): Calcula el puntaje de una palabra.
•	Fill_letter(nombreArchivo): Inicializa la lista de letras a partir de letras.txt.
•	Check_words(palabra): Verifica la validez de una palabra.
•	Grafo_de_palabras(): Construye un grafo de palabras según el diccionario.
•	Posibles_Palabras(word string): Encuentra las posibles palabras formadas con las letras de la cadena, utilizando el grafo
•	Verificar_posibles_palabras(String word): Verifica la validez de las letras q se ubican en word
•	Combinaciones_posibles_palabras(string word): Genera combinaciones posibles de letras en la palabra dada

3. Diccionario
Descripción: Este es el diccionario que se va a utilizar en el juego scrabble.
- Atributos:
•	ListaPalabras: Lista que almacena las palabras del diccionario.
- Operaciones:
•	Diccionario(): Constructorque inicia las listas de palabras vacía.
•	ObtenerListaPalabras(): Método que devuelve la lista de palabras almacenadas en el diccionario
•	FijarListaPalabras(palabras): Establece la lista de palabras.
•	AgregarPalabra(palabra): Agrega una palabra a la lista de palabras.
•	BuscarPalabras(prefijo): Busca palabras en el diccionario que coincidan con un prefijo.
•	PalabrasEsEmpty(): Verifica si el diccionario está vacío o no.

4. Console()
Descripción: Maneja la entrada y salida de la consola del juego, básicamente procesa los comandos.
- Atributos:
•	Ayuda: Mapa que almacena los comandos del juego.
•	Scrabble: Contiene el Juego scrabble.
- Operaciones:
•	ConsoleIO(): Constructor de los comandos disponibles.
•	AgregarLetras(): Agrega letras del archivo letrs.txt a la lista de letras.
•	ListarComandos(comanddo): Método que lista los comandos.
•	ProcesarComando(comando): Procesa comando ingresado por el usuario.
•	ProcesarComponentes(Comando): Método que procesa los componentes del comando ingresado y lo ejecuta.

5. Palabra
Descripción: Representa una palabra en el juego scrabble con su texto puntaje y longitud.
- Atributos:
•	Palabra: Cadena que representa el texto de la palabra.
•	Puntos: Un entero que representa el puntaje de la palabra.
•	Longitud: Un entero que representa la longitud de la palabra.
- Operaciones:
•	Palabra(): Constructor que inicia la palabra vacía.
•	Palabra(palabra): Constructor que inicia la palabra con la palabra dada y calcula longitud.
•	ObtenerPalabra(): Metodo que devuelve el texto de la palabra.
•	ObtenerPuntos(): Devuelve el puntaje de la palabra.
•	ObtenerLongitud(): Devuelve longitud de la palabra.
•	FijarPalabra(palabra): Establece el texto de la palabra.
•	FijarPuntos(puntos): Establece puntaje e la palabra.
•	FijarLongitud(longitud): Establece longitud de la palabra.

6. arbolTrie
Descripción: Esta clase representa árbol Trie, utilizado para almacenar y buscar palabras.
- Atributos:
•	Root: Puntero al nodo raíz del árbol.
•	CantidadPalabras: Entero que representa la cantidad de palabras en el árbol.
- Operaciones:
•	ObtenerCantidadPalabaras():  Devuelve la cantidad de palabras almacenadas en el árbol.
•	FijarCantidadPalabras(incrementar): Método que incrementa o disminuye la cantidad de palabras almacenadas.
•	InsertarPalabra(palabra): Inserta una palabra en el árbol.
•	Buscar_prefijo(prefijo): busca un prefijo en el árbol y devuelve si lo encuentra.
•	BuscarPalabras(prefijo, inverso): busca el prefijo en el árbol inverso y devuelve si lo encuentra.
•	EsEmpty(): Verifica si esta vacío el árbol.


7. Trienode
Descripción: Representa un nodo de una estructura de datos de trie
- Atributos:
•	BanderaPlabra: Booleano que indica si el nodo representa final de la palabra.
•	Letra: Carácter que representa la letra con su respectivo nodo.
•	Nodoshijos: Mapa que almacena punteros a los nodos hijos.
- Operaciones:
•	Trienode(): Inicializa nodo con una letra dada y con la bandera en falso.
•	Trienode(caracter): Inicia el nodo con una letra y con la bandera en falso.
•	ObtenerBandderaPalabra(): Devuelve la bandera que inddica si el noddo representa el final de la palabra.
•	ObtenerLetra(): Devuelve la letra asociada al nodo.
•	FijarBanderaPlabra(bandera): Establece la bandera que indica si el nodo representa el final.
•	FijarLetra(caracter): Establece el carácter asociadda al nodo.
•	InsertarNodoHijo(caracter): Inserta un nuevo nodo hijo con la letra que se le da.
•	ObtenerNodoclave(caracter): Método que devuelve el noddo hijo.
•	Noddoshijosesemtpy(): Verifica si el mapa de nodods está vacío.
•	Llavexiste(caracter): Métoddo que verifica si una clave dad existe en el mapa de nodos hijos.
•	BusqueddaPalabrasNodosHijos(listaP, palabra, inverso): Método que busca palabras construidas a partir de un prefijo y nodo dado y lo mete a una lista.

8. GrafoDiccionario:
Descripcion: Representa un grafo construido a partir de un diccionario de palabras
Atributos:
•	Nodos: Mapa que almacena los nodos del grafo, donde el valor es un puntero al nodo correspondiente

- Operaciones:
•	GrafoDiccionario(): Constructor que inicia un nuevo grafo
•	AddNodo(palabra): Agrega un nuevo nodo al grafo con la palabra
•	DeleteNodo(string): Elimina un nodo ddel grafo junto con todas las aristas que lo conectan
•	AddAristas(): crea aristas entre nodos que tienen una diferencia de una letra en su palabra
•	EliminarAristas(): Elimina las aristas del grafo
•	GetNodo(string): Obtiene un puntero al nodo correspondiente a la palabra especificada.
•	ModificarNodo(string, palabra): Modifica el contenido de un nodo y actualiza las aristas conectadas
•	Imprimirvecinos(string): Imprime los vecinos de un nodo específico
•	DiferenciaUnaLetra(string, string): Verifica si dos palabras son diferentes en una letra.

9 NodoGrafo:
Descripcion: Representa un nodo de un grafo utilizando para almacenar palabras del diccionario
Atributos:
•	Palabra: Almacena la palabra asociada al nodo
•	Num_vecinos: Almacena el número de nodos adyacentes al nodo.
•	ListaAdyacencia: Almacena una lista de punteros a los nodos adyacentes.
Operaciones:
•	NodoGrafo(): Constructor por defecto que inicializa un nuevo nodo.
•	NodoGrafo(Palabra): Constructor que inicializa un nuevo nodo con una palabra específica.
•	GetPalabra(): Devuelve la palabra asociada al nodo.
•	SetPalabra(Palabra): Establece la palabra asociada al nodo.
•	GetNum_vencinos(): Devuelve el número de vecinos del nodo.
•	Setnum_vecinos(numero): Establece el número de vecinos del nodo.
•	GetAddyacentes(): Devuelve una lista de punteros a los nodos adyacentes.
•	AddAdyacente(nodo): Agrega un nodo adyacente a la lista de adyacencia del nodo.
•	DeleteAdyacente(nodo): Elimina un nodo adyacente de la lista de adyacencia del nodo.
•	FindAdyacente(nodo): Verifica si un nodo especificado es adyacente al nodo actual.
•	ModificarAdyacente(nodo, palabra): Modifica la palabra de un nodo adyacente especificado.


## Autores
Kevin Garay
Arley Bernal
Felipe Garrido
