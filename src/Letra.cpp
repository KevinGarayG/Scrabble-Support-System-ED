#include "Letra.h"

/* Creadores de instancias de Letra */
Letra::Letra(){}

Letra::Letra(char c){
    this->letter = c;
    this->point = 0;
}
/* Obtenedores de atributos */
char Letra::getLetter(){
    return letter;
}
int Letra::getPoint(){
    return point;
}

/* Fijadores del valor de atributos*/
void Letra::setLetter(char letra){
    letter = letra;
}
void Letra::setPoint(int punto){
    point = punto;
}

/* Ordenador de elementos de TAD Letra*/
bool Letra::operator<(const Letra& otra) const {
    return letter < otra.letter;
}