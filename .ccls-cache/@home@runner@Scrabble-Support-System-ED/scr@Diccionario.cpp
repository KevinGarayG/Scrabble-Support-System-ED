#include "Diccionario.h"

/* Creadores de instancias de Diccionario */
Diccionario::Diccionario(){
    this->list_words = list<Palabra>();
}
/* Obtenedores de atributos */
list<Palabra> Diccionario::getListWords(){
    return list_words;
}
/* Fijadores del valor de atributos*/
void Diccionario::setListWords(list<Palabra> palabras){
    list_words = palabras;
}
/* Agregar una palabra a la lista de palabras */
void Diccionario::addWord(Palabra palabra){
    list_words.push_back(palabra);
}
/* Función que busca una palabra en una lista utilizando punteros */
Palabra* Diccionario::searchWord(const string& palabra) {
    for (Palabra& pal : list_words) {
        if (pal.getWord() == palabra) {
            return &pal; // Devuelve el puntero a la palabra si la encuentra
        }
    }
    return nullptr; // Devuelve nullptr si la palabra no está en la lista
}
/* Verificación de diccionario vacio */
bool Diccionario::palabras_is_empty(){
    return list_words.empty();
}