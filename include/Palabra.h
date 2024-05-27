#ifndef PALABRA_H_
#define PALABRA_H_

#include <iostream>
#include <string>

using namespace std;

/* Definición del TAD Palabra como una clase. */
class Palabra {
    private:
        /* Datos mínimos */
        string word;
        int points;
        int length;

    public:
        /* Constructores */
        Palabra();
        Palabra(string word);

        /* getters */
        string getWord();
        int getPoints();
        int getLength();
        /* setters */
        void setWord(string palabra);
        void setPoints(int puntos);
        void setLength(int longitud);

        /* operator< */
        bool operator<(const Palabra& otra) const;
};

#endif