#include "ConsoleIO.h"

/* Creadores de instancias de ConsoleIO */
ConsoleIO::ConsoleIO() {
  // Definición de los comandos y componentes
  ayuda = {
      {"1. Configuración del juego",
       {{"inicializar diccionario.txt",
         "Inicializa el sistema a partir del archivo diccionario.txt"},
        {"iniciar_inverso diccionario.txt",
         "Inicializa el sistema a partir del archivo y almacena las palabras "
         "en sentido inverso"},
        {"puntaje palabra", "El comando permite conocer la puntuación que "
                            "puede obtenerse con una palabra dada."},
        {"salir", "Termina la ejecución de la aplicación."}}},

      {"2. Búsqueda de palabras",
       {{"inicializar_arbol diccionario.txt",
         "Inicializa el sistema desde un archivo diccionario.txt y almacena "
         "las palabras en un árbol."},
        {"iniciar_arbol_inverso diccionario.txt",
         "Inicializa el sistema a partir del archivo y almacena las palabras "
         "en sentido inverso en un árbol."},
        {"palabras_por_prefijo prefijo",
         "Dado un prefijo, se recorre el árbol de letras para ubicar todas "
         "las palabras posibles a construir."},
        {"palabras_por_sufijo sufijo",
         "Dado un sufijo, se recorre el árbol de letras para ubicar todas "
         "las palabras posibles a construir."}}},

      {"3. Combinaciones de palabras",
       {{"grafo_de_palabras",
         "Construye un grafo de palabras, cada palabra se conecta a las "
         "demas solo si difieren en un unica letra."},
        {"posibles_palabras letras",
         "Dadas ciertas letras el comando debe presentar en pantalla todas las "
         "posibles palabras válidas a construir, indicando la longitud de "
         "cada una y la puntuación que se puede obtener con cada una."}}}};
};

/* Función encargada de agregar las letras de un archivo a la lista de letras.
 */
void ConsoleIO::add_letters() {
  bool init = scrabble.fill_letter("letras.txt");
  if (!init) {
    // Si no existe el archivo se para el programa.
    cout << endl << "El archivo letras.txt no existe." << endl;
    cout
        << "Es necesario revisar los archivos de texto en la carpeta 'files'.\n"
        << endl;
    exit(0);
  }
}

/* Función encargada de procesar los comandos principales de ayuda y salir. */
void ConsoleIO::process_command(string command) {
  if (command == "ayuda") {
    list_commands(command);
  } else if (command.substr(0, 6) == "ayuda ") {
    string specificCommand = command.substr(6);
    bool encontrado = false;
    for (const auto &section : ayuda) {
      for (const auto &entrada : section.second) {
        if (entrada.first.compare(specificCommand) == 0) {
          cout << "     " << left << setw(40) << entrada.first << entrada.second
               << endl;
          encontrado = true;
          break;
        }
      }
    }
    if (!encontrado) {
      cout << "Comando no encontrado." << endl;
    }
  } else if (command == "salir") {
    exit(0);
  } else {
    process_components(command);
  }
}

/* Función encargada de listar los comandos correspondientes disponibles. */
void ConsoleIO::list_commands(string command) {
  cout << endl;
  // Recorre el mapa de componentes.
  for (auto &componente : ayuda) {
    cout << componente.first << ":" << endl;
    // Recorre cada uno de los comandos por componente y los imprime
    for (auto &comando : componente.second) {
      cout << "     " << left << setw(40) << comando.first << comando.second
           << endl;
    }
    cout << endl;
  }
}

/* Procesa el comando ingresado y llama las funciones del objeto scrabble
 * correspondientes. */
void ConsoleIO::process_components(string command) {
  if (command.substr(0, 12) == "inicializar ") {
    scrabble.inicializar_diccionario(command.substr(12), false);

  } else if (command.substr(0, 16) == "iniciar_inverso ") {
    scrabble.inicializar_diccionario(command.substr(16), true);

  } else if (command.substr(0, 8) == "puntaje ") {
    scrabble.puntaje_palabra(command.substr(8), false);

  } else if (command.substr(0, 14) == "iniciar_arbol ") {
    scrabble.inicializar_arbol(command.substr(14), false);

  } else if (command.substr(0, 22) == "iniciar_arbol_inverso ") {
    scrabble.inicializar_arbol(command.substr(22), true);

  } else if (command.substr(0, 21) == "palabras_por_prefijo ") {
    scrabble.buscar_palabras(command.substr(21), false);

  } else if (command.substr(0, 20) == "palabras_por_sufijo ") {
    scrabble.buscar_palabras(command.substr(20), true);

  } else if (command.substr(0, 18) == "grafo_de_palabras") {
    scrabble.grafo_de_palabras();

  } else if (command.substr(0, 18) == "posibles_palabras ") {
    scrabble.posibles_palabras(command.substr(18));

  } else {
    cout << "Comando no reconocido" << endl;
  }
}