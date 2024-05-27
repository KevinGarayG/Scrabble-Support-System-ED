#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

#include "Palabra.h"
#include <list>
#include <vector>

using namespace std;

class NodoGrafo {
    private:
        Palabra palabra;
        int num_vecinos;
        list<NodoGrafo*> listaAdyacencia;

    public:
        NodoGrafo();
        NodoGrafo(const Palabra& palabra);

        Palabra getPalabra() const;
        void setPalabra(const Palabra& palabra);

        int getNum_vecinos() const;
        void setNum_vecinos(const int vecinos);

        list<NodoGrafo*>& getAdyacentes();
        
        void addAdyacente(NodoGrafo* nodo);
        void deleteAdyacente(NodoGrafo* nodo);

        bool findAyacente(NodoGrafo* nodoBuscado);
        void modificarAdyacente(NodoGrafo* nodo, const Palabra& nuevaPalabra);

};


#endif