#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <fstream>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <iomanip>

#include <deque>
#include <set>

#include "ArbolTrie.h"
#include "Diccionario.h"
#include "GrafoDiccionario.h"
#include "Letra.h"
#include "Palabra.h"

using namespace std;

/* Definición del TAD Scrabble como una clase. */
class Scrabble {
private:
  /* Datos mínimos */
  list<Letra> letters_list;

  Diccionario dictionary;
  Diccionario inverse_dicc;

  ArbolTrie tree;
  ArbolTrie inverse_tree;

  /* Nueva clase */
  GrafoDiccionario graphDicc;

public:
  /* Constructor */
  Scrabble();

  /* Operaciones de modulo Configuración del juego. */
  bool inicializar_diccionario(string nameFile, bool inverse);
  Palabra *puntaje_palabra(string word, bool grafo);

  /* Funciones adicionales útiles. */
  int calculate_score(string &word);
  bool fill_letter(string nameFile);
  bool check_words(string &word);
  int verificar_Posibles_Palabras(string &word);
  vector<string> combinaciones_posibles_palabras(string word);

  /* Operaciones de modulo Búsqueda de palabras. */
  bool inicializar_arbol(string nameFile, bool inverse);
  void buscar_palabras(string word, bool isPrefix);

  /* Funciones asociadas al grafo de diccionario. */
  void grafo_de_palabras();
  bool posibles_palabras(string word);
};

#endif