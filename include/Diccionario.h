#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

#include "Palabra.h"
#include <list>

using namespace std;

/* Definición del TAD Diccionario como una clase. */
class Diccionario {
    private:
        /* Datos mínimos */
        list<Palabra> list_words;

    public:
        /* Constructores */
        Diccionario();

        /* getters */
        list<Palabra> getListWords();
        void setListWords(list<Palabra> palabras);

        /* Busqueda y inserción */
        void addWord(Palabra palabra);
        Palabra* searchWord(const string& palabra);

        /* size() */
        
        /* empty() */
        bool palabras_is_empty();

};

#endif