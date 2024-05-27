#include "Palabra.h"

/* Creadores de instancias de Palabra */
Palabra::Palabra(){
    word = "";
    length = 0;
    points = 0;
}

Palabra::Palabra(string palabra){
    word = palabra;
    length = palabra.length();
    points = 0;
}
/* Obtenedores de atributos */
string Palabra::getWord(){
    return word;
}
int Palabra::getPoints(){
    return points;
}
int Palabra::getLength(){
    return length;
}
/* Fijadores del valor de atributos*/
void Palabra::setWord(string palabra){
    word = palabra;
}
void Palabra::setPoints(int puntos){
    points = puntos;
}
void Palabra::setLength(int longitud){
    this->length = longitud;
}

/* Ordenador de elementos de TAD Palabra*/
bool Palabra::operator<(const Palabra& otra) const {
    return word < otra.word;
}

