#include "NodoGrafo.h"

NodoGrafo::NodoGrafo() {}

NodoGrafo::NodoGrafo(const Palabra& palabra) : palabra(palabra) {}

Palabra NodoGrafo::getPalabra() const {
    return palabra;
}

void NodoGrafo::setPalabra(const Palabra& palabra) {
    this->palabra = palabra;
}

int NodoGrafo::getNum_vecinos() const {
    return num_vecinos;
}

void NodoGrafo::setNum_vecinos(const int vecinos) {
    this->num_vecinos = vecinos;
}

list<NodoGrafo*>& NodoGrafo::getAdyacentes() {
    return listaAdyacencia;
}

void NodoGrafo::addAdyacente(NodoGrafo* nodo) {
    listaAdyacencia.push_back(nodo);
}

void NodoGrafo::deleteAdyacente(NodoGrafo* nodo) {
    if (findAyacente(nodo)) {
        listaAdyacencia.remove(nodo);
    }
}

void NodoGrafo::modificarAdyacente(NodoGrafo* nodo, const Palabra& nuevaPalabra) {
    for (auto it = listaAdyacencia.begin(); it != listaAdyacencia.end(); ++it) {
        if (*it == nodo) {
            (*it)->setPalabra(nuevaPalabra);
            break;
        }
    }
}

bool NodoGrafo::findAyacente(NodoGrafo* nodoBuscado) {
    for (NodoGrafo* vecino : listaAdyacencia){
        if (vecino->getPalabra().getWord() == nodoBuscado->getPalabra().getWord()){
            return true;
        }
    }
    return false;
}
