#include "GrafoDiccionario.h"

GrafoDiccionario::GrafoDiccionario() {}

void GrafoDiccionario::addNodo(Palabra &palabra) {
  string palabraStr = palabra.getWord();
  if (nodos.find(palabraStr) == nodos.end()) {
    nodos[palabraStr] = new NodoGrafo(palabra);
  }
}

void GrafoDiccionario::deleteNodo(const string &palabra) {
  auto it = nodos.find(palabra);
  if (it != nodos.end()) {
    // Eliminar aristas que apuntan al nodo a eliminar
    for (auto &pair : nodos) {
      pair.second->deleteAdyacente(it->second);
    }
    // Eliminar el nodo del grafo
    delete it->second;
    nodos.erase(it);
  }
}

void GrafoDiccionario::addAristas() {
  // Crear mapa con clave longitud y valor lista de palabras
  unordered_map<int, vector<decltype(nodos.begin())>> length_map;
  for (auto it = nodos.begin(); it != nodos.end(); ++it) {
    length_map[it->first.size()].push_back(it);
  }
  // Conectar nodos
  for (const auto &entry : length_map) {
    const auto &vec = entry.second;
    for (size_t i = 0; i < vec.size(); ++i) {
      for (size_t j = i + 1; j < vec.size(); ++j) {
        if (diferenciaUnaLetra(vec[i]->first, vec[j]->first)) {
          vec[i]->second->addAdyacente(vec[j]->second);
          vec[j]->second->addAdyacente(vec[i]->second);
        }
      }
    }
  }
}

void GrafoDiccionario::eliminarArista(const string &palabra1,
                                      const string &palabra2) {
  auto nodo1 = getNodo(palabra1);
  auto nodo2 = getNodo(palabra2);
  if (nodo1 && nodo2) {
    nodo1->deleteAdyacente(nodo2);
    nodo2->deleteAdyacente(nodo1);
  }
}

NodoGrafo *GrafoDiccionario::getNodo(const string &palabra) {
  auto it = nodos.find(palabra);
  if (it != nodos.end()) {
    return it->second;
  }
  return nullptr;
}

unordered_map<string, NodoGrafo *> GrafoDiccionario::getNodos() {
  return nodos;
}

void GrafoDiccionario::modificarNodo(const string &palabra,
                                     const Palabra &nuevaPalabra) {
  auto it = nodos.find(palabra);
  if (it != nodos.end()) {
    // Modificar la palabra del nodo
    it->second->setPalabra(nuevaPalabra);
    // Actualizar la palabra en las aristas
    for (auto &pair : nodos) {
      if (pair.second != it->second) {
        pair.second->modificarAdyacente(it->second, nuevaPalabra);
      }
    }
  }
}

vector<string> GrafoDiccionario::obtenerVecinos(const string &palabra) {
  auto it = nodos.find(palabra);
  vector<string> vecinos;
  if (it != nodos.end()) {
    for (const auto &vecino : it->second->getAdyacentes()) {
      vecinos.push_back(vecino->getPalabra().getWord());
    }
  }
  return vecinos;
}

bool GrafoDiccionario::diferenciaUnaLetra(const string &palabra1,
                                          const string &palabra2) {
  if (palabra1.length() != palabra2.length()) {
    return false;
  }

  int diferencias = 0;
  for (size_t i = 0; i < palabra1.length(); ++i) {
    if (palabra1[i] != palabra2[i]) {
      ++diferencias;
      if (diferencias > 1) {
        return false;
      }
    }
  }
  return diferencias == 1;
}
