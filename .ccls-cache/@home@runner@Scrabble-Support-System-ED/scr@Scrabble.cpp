#include "Scrabble.h"

/* Creadores de instancias de Letra */
Scrabble::Scrabble() {
  letters_list = list<Letra>();
  dictionary = Diccionario();
  inverse_dicc = Diccionario();
  tree = ArbolTrie();
  inverse_tree = ArbolTrie();
  graphDicc = GrafoDiccionario();
}

/* Función principal que inicializa la lista de letras a partir del archivo de
 * texto. */
bool Scrabble::fill_letter(string nameFile) {
  Letra letra;
  string line;

  // Se abre el archivo de texto con el nombre dado
  ifstream myfile("files/" + nameFile);
  if (myfile.is_open()) {
    int p;
    char a;
    // Se lee el archivo linea por linea
    while (getline(myfile, line)) {
      istringstream iss(line);
      // Se lee la letra y el puntaje de la linea
      iss >> a >> p;
      letra.setLetter(a);
      letra.setPoint(p);
      // Se agrega la letra  a la lista de letras
      letters_list.push_back(letra);
    }
    myfile.close();
    return true;
  } else {
    return false;
  }
}

/* Función encargada de inicializar el diccionario de palabras. */
bool Scrabble::inicializar_diccionario(string nameFile, bool inverse) {
  // Verificar si el diccionario ya ha sido inicializado
  if (!dictionary.palabras_is_empty() && !inverse) {
    cout << "El diccionario ya ha sido inicializado." << endl;
    return false;
  } else if (!inverse_dicc.palabras_is_empty() && inverse) {
    cout << "El diccionario inverso ya ha sido inicializado." << endl;
    return false;
  }

  string palabra;
  // Se abre el archivo de texto diccionario en modo lectura.
  ifstream fin("files/" + nameFile);
  if (!fin.is_open()) {
    cout << "El archivo " << nameFile << " no existe o no puede ser leído."
         << endl;
    return false;
  }
  bool invalido = false;
  // Bucle que lee linea por linea la información del archivo
  while (fin >> palabra) {
    // Se verifica que la palabra no contenga caracteres no alfabeticos y se
    // mutan a minuscula.
    if (check_words(palabra)) {
      Palabra p;
      // Se verifica si se está iniciando el diccionario normal o inverso
      if (inverse) {
        // Se invierte la palabra y se agrega al diccionario inverso.
        reverse(palabra.begin(), palabra.end());
        p.setWord(palabra);
        p.setLength(palabra.size());
        inverse_dicc.addWord(p);
      } else {
        // Solo se agrega al diccionario normal.
        p.setWord(palabra);
        p.setLength(palabra.size());
        dictionary.addWord(p);
      }
    } else
      invalido = true;
  }
  if (invalido)
    cout << endl
         << "Las anteriores palabras se han descartado por tener simbolos no "
            "válidos.\n"
         << endl;

  fin.close();
  // Se imprime mensaje
  string str = (!inverse) ? "diccionario" : "diccionario inverso";
  cout << endl << "El " << str << " se ha inicializado correctamente." << endl;
  return true;
}

/* Calcula el puntaje de una palabra dada segun el puntaje de sus letras */
Palabra *Scrabble::puntaje_palabra(string word, bool grafo) {
  // Se realiza una verificación de existencia de ambos diccionarios
  if (dictionary.palabras_is_empty()) {
    cout << "El Diccionario no ha sido inicializado." << endl;
    return nullptr;
  } else if (inverse_dicc.palabras_is_empty()) {
    cout << "El Diccionario Inverso no ha sido inicializado." << endl;
    return nullptr;
    // Se verifica que la palabra sea válida
  } else if (!check_words(word)) {
    cout << "La palabra " + word + "  contiene símbolos inválidos." << endl;
    return nullptr;
  }

  int puntaje = 0;
  string word_inv = word;
  reverse(word_inv.begin(), word_inv.end());

  // Verificar que la palabra esté en los diccionarios
  Palabra *pal = dictionary.searchWord(word);
  Palabra *pal2 = inverse_dicc.searchWord(word_inv);

  // Si no existe retorna error
  if (pal == nullptr || pal2 == nullptr) {
    if (!grafo)
      cout << "La palabra " + word + " no existe en los diccionarios." << endl;
    return nullptr;
  } else {
    // Si la palabra existe en el diccionario, se calcula su puntaje
    puntaje = calculate_score(word);
    // insertamos puntajes al diccionario
    pal->setPoints(puntaje);
    pal2->setPoints(puntaje);
  }
  if (!grafo)
    cout << "La palabra " + word + " tiene un puntaje de: " + to_string(puntaje)
         << endl;
  return pal;
}

/* Función que inicializa un arbol con las palabras del archivo de texto
 * diccionario. */
bool Scrabble::inicializar_arbol(string nameFile, bool inverse) {
  // Se verifica que no exista el arbol diccionario correspondiente usando el
  // booleano invertir
  if (!tree.isEmpty() && !inverse) {
    cout << "El árbol del diccionario ya ha sido inicializado." << endl;
    return false;
  } else if (!inverse_tree.isEmpty() && inverse) {
    cout << "El árbol del diccionario inverso ya ha sido inicializado." << endl;
    return false;
  }

  string palabra;
  // Se abre el archivo en forma de lectura
  ifstream fin("files/" + nameFile);
  if (!fin.is_open()) {
    cout << "El archivo " << nameFile << " no existe o no puede ser leído.\n"
         << endl;
    return false;
  }
  bool invalido = false;

  // Se realiza la lectura de cada linea del archivo obteniendo la palabra
  // almacenada
  while (fin >> palabra) {
    // Se verifica que la palabra sea válida
    if (check_words(palabra)) {
      if (inverse) {
        // Se invierte la palabra y se agrega al arbol inverso.
        reverse(palabra.begin(), palabra.end());
        inverse_tree.insert_word(palabra);
      } else
        // Se agrega al arbol normal
        tree.insert_word(palabra);
    } else
      invalido = true;
  }
  if (invalido)
    cout << endl
         << "Las anteriores palabras se han descartado por tener simbolos no "
            "válidos.\n"
         << endl;
  // Se imprime mensaje de verificación
  fin.close();
  string str = (!inverse) ? "" : "inverso ";
  cout << "El árbol del diccionario " << str
       << "se ha inicializado correctamente." << endl;
  return true;
}

/* Algoritmo que busca la lista de palabras que inician con un prefijo o sufijo
 * dado. */
void Scrabble::buscar_palabras(string word, bool isPrefix) {
  if (tree.isEmpty() && !isPrefix) {
    cout << "El árbol del diccionario no ha sido inicializado." << endl;
  } else if (inverse_tree.isEmpty() && isPrefix) {
    cout << "El árbol del diccionario inverso no ha sido inicializado." << endl;
  } else {
    // Se inicializan variables
    set<string> listaAuxiliar;
    set<Palabra> lista_palabras;
    string preSuf = isPrefix ? "sufijo " : "prefijo ";
    // Se verifica si se requiere buscar palabras con prefijo o sufijo
    // determinado por la variable isPrefix
    if (!isPrefix) {
      listaAuxiliar = tree.search_words(
          word, isPrefix); // Si es prefijo se usa la función de busqueda de
                           // palabras en el arbol
    } else if (isPrefix) {
      reverse(word.begin(),
              word.end()); // Si es sufijo se usa la función en el arbol inverso
      listaAuxiliar = inverse_tree.search_words(word, isPrefix);
    }

    // Se verifica que la lista no esté vacia
    if (!listaAuxiliar.empty()) {
      // Recorre cada elemento de la lista de palabras y calcula cada atributo
      // para crear un dato Palabra
      for (string c : listaAuxiliar) {
        Palabra palabra = Palabra(c);

        int puntaje = calculate_score(c);
        palabra.setPoints(puntaje);
        // Se agrega el dato de tipo Palabra a la lista final.
        lista_palabras.insert(palabra);
      }
      // Se imprime en pantalla el resultado
      cout << endl
           << "Las palabras que inician con este " << preSuf
           << " son: " << endl;
      cout << left << setw(20) << "Palabra" << setw(10) << "Puntaje" << setw(10)
           << "Longitud" << endl;
      for (auto p : lista_palabras) {
        cout << left << setw(20) << p.getWord() << setw(10)
             << to_string(p.getPoints()) << setw(10) << to_string(p.getLength())
             << endl;
      }
    } else {
      // Si la lista está vacia se imprime mensaje de que el prefijo no se
      // encontró en el arbol.
      cout << "Prefijo " << word << " no pudo encontrarse en el diccionario."
           << endl;
    }
  }
}

/* Es posible sacar estas funciones en una clase Utils.*/

/* Función que verifia la validez de una palabra. */
bool Scrabble::check_words(string &word) {
  // Verificar que la palabra contenga solo letras
  if (!all_of(word.begin(), word.end(), ::isalpha)) {
    cout << endl << word;
    return false;
  } else {
    // Se mutan las letras a minuscula
    for (char &c : word)
      c = tolower(c);
  }
  return true;
}

/* Función encargada de calcular el puntaje de una palabra usando la lista de
 * letras. */
int Scrabble::calculate_score(string &word) {
  int puntaje = 0;
  deque<char> fila(word.begin(), word.end());
  // Se recorre la lista de letras
  for (auto &letra : letters_list) {
    // Se recorre cada caracter de la palabra.
    for (auto it = fila.begin(); it != fila.end();) {
      // Si son iguales se obtiene y suma el punto de la letra al puntaje
      if (letra.getLetter() == *it) {
        puntaje += letra.getPoint();
        it = fila.erase(it); // Se elimina ese caracter de la palabra
      } else
        it++; // Continua en siguiente palabra
    }
  }
  return puntaje;
}

/*Función encargada de crear el arbol de palabras con las palabras alamacenadas
 * en el diccionario*/
void Scrabble::grafo_de_palabras() {
  if (dictionary.palabras_is_empty()) {
    cout << endl << "El Diccionario NO ha sido inicializado." << endl;
    return;
  } else {
    // Agregar Nodos
    for (auto &palabra : dictionary.getListWords()) {
      graphDicc.addNodo(palabra);
    }
    // Conectar nodos
    graphDicc.addAristas();
    cout << endl << "Grafo construido correctamente." << endl;
  }
}

//. Dada una cadena de caracteres: genera todas las combinaciones posibles de
// las letras, calcula los puntajes y muestra las palabras válidas con sus
// puntajes y longitudes.
bool Scrabble::posibles_palabras(string word) {
  vector<string> combinaciones, vecinos;
  GrafoDiccionario grafo = graphDicc;

  // Verifica que el grafo de palabras esté inicializado
  if (grafo.getNodos().empty()) {
    cout << endl << "El Grafo NO ha sido inicializado." << endl;
    return false;
  }

  // Verifica que no haya caracteres inválidos
  int verif = verificar_Posibles_Palabras(word);
  if (verif == 0) {
    return false;
  }

  // Busca todas las posibles combinaciones de los caracteres enviados
  combinaciones = combinaciones_posibles_palabras(word);
  if (combinaciones.empty()) {
    cout << "Error al encontrar combinaciones posibles" << endl;
    return false;
  }

  cout << endl
       << "Las posibles palabras a construir con las letras " << word
       << " son:" << endl;
  cout << setw(15) << left << "Palabra" << setw(12) << left << "Puntaje"
       << setw(8) << left << "Largo" << endl;

  // Procesa cada combinación
  for (auto &str : combinaciones) {
    if (str.find("?") != string::npos) {
      // Si se encuentra el carácter '?', añade la palabra al grafo y obtiene
      // los vecinos
      Palabra p = Palabra(str);
      grafo.addNodo(p);
      grafo.addAristas();
      vecinos = grafo.obtenerVecinos(str);
      grafo.deleteNodo(str);

      // Calcula el puntaje de los vecinos
      for (auto &vecino : vecinos) {
        Palabra *pal = puntaje_palabra(vecino, true);
        if (pal != nullptr) {
          cout << setw(15) << left << pal->getWord() << setw(12) << left
               << pal->getPoints() << setw(8) << left << pal->getLength()
               << endl;
        }
      }
    } else {
      // Calcula el puntaje directamente si no hay '?'
      Palabra *pal = puntaje_palabra(str, true);
      if (pal != nullptr) {
        cout << setw(15) << left << pal->getWord() << setw(12) << left
             << pal->getPoints() << setw(8) << left << pal->getLength() << endl;
      }
    }
  }
  return true;
}

/*Verifica que los caracteres de la palabra sean válidos y los convierte a
 * minúsculas. Asegura que no haya más de un comodín ('?')*/
int Scrabble::verificar_Posibles_Palabras(string &word) {

  int comodin = 0;
  // se verifica que la palabra sea valida
  for (char &c : word) {
    if (c == '?')
      comodin++;
    if (isalpha(c) || c == '?')
      // Se mutan las letras a minuscula
      c = tolower(c);
    else {
      cout << endl << "El caracter '" << c << "' es invalido" << endl;
      return 0;
    }
  }
  if (comodin == 2) {
    cout << endl << "El caracter '?' dos veces es invalido" << endl;
    return 0;
  }
  return 1;
}

/*Genera todas las combinaciones posibles de las letras de la palabra. Ordena
 * las letras, crea permutaciones de subcadenas, y coloca las combinaciones con
 * comodín ('?') al final*/
vector<string> Scrabble::combinaciones_posibles_palabras(string word) {

  vector<string> combinaciones;
  sort(word.begin(), word.end());

  // obtener las permutaciones de todas las subcadenas
  do {
    for (int len = 1; len <= word.size(); ++len) {
      string str;
      str = word.substr(0, len);
      auto it = find(combinaciones.begin(), combinaciones.end(), str);
      if (it == combinaciones.end())
        combinaciones.push_back(str);
    }
  } while (next_permutation(word.begin(), word.end()));

  // Reordenar para colocar las combinaciones con '?' al final
  sort(combinaciones.begin(), combinaciones.end(),
       [](const string &a, const string &b) {
         return a.find('?') != string::npos && b.find('?') == string::npos;
       });

  reverse(combinaciones.begin(), combinaciones.end());

  return combinaciones;
}
