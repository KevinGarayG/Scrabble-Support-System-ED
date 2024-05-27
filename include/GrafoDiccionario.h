#ifndef GRAFODICCIONARIO_H_
#define GRAFODICCIONARIO_H_

#include "NodoGrafo.h"
#include "Palabra.h"
#include <string>
#include <unordered_map>

using namespace std;

class GrafoDiccionario {
private:
  unordered_map<string, NodoGrafo *> nodos;
  bool diferenciaUnaLetra(const string &palabra1, const string &palabra2);

public:
  GrafoDiccionario();

  void addNodo(Palabra &palabra);
  void deleteNodo(const string &palabra);

  void addAristas();
  void eliminarArista(const string &palabra1, const string &palabra2);

  NodoGrafo *getNodo(const string &palabra);
  unordered_map<string, NodoGrafo *> getNodos();
  void modificarNodo(const string &palabra, const Palabra &nuevaPalabra);

  void imprimirVecinos(const string &palabra);
  vector<string> obtenerVecinos(const string &palabra);
};

#endif