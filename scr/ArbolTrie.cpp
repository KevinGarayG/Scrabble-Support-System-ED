#include "ArbolTrie.h"

using namespace std;

/* Creadores de instancias de ArbolTrie */
ArbolTrie::ArbolTrie(){
    root = new TrieNode();
    cantWords = 0;
}
/* Obtenedores de atributos */
int ArbolTrie::getCantWords() {
    return cantWords; 
}
/* Fijadores del valor de atributos*/
void ArbolTrie::setCantWords(bool increase){
    if (increase)
        cantWords++;
    else 
        cantWords--;
}

/* Función responsable de insertar una palabra en el árbol diccionario. */
void ArbolTrie::insert_word(string &palabra){
    // Se inicia desde el nodo raiz
    TrieNode* currentNode = this->root;

    // Se recorre la palabra dada
    for (auto c : palabra){
        // Se busca cada caracter en el mapa de punteros de cada nodo
        if (!currentNode->key_exist(c)){
            currentNode->insert_childNode(c);   // Si no existe la clave y valor se crea
        }
        // Se obtiene el nodo de esa clave valor
        currentNode = currentNode->get_nodo_key(c);
    }
    // Se cambia la bandera de palabra existente y se aumenta la cantidad de palabras
    currentNode->setFlagWord(true);
    this->setCantWords(true);
}

/* Función encargada de buscar una palabra o prefijo y retornar el nodo final si está. */
TrieNode* ArbolTrie::search_prefix(string& prefix){
    TrieNode* currentNode = this->root;
    // Recorre cada caracter del prefijo
    for (auto c : prefix){
        if (currentNode->key_exist(c)){
            // Se obtiene el puntero
            currentNode = currentNode->get_nodo_key(c);
        } else 
        // Si no existe esa letra en el mapa del nodo dado se retorna null
            return nullptr;
    }
    return currentNode;
}

/* Verificación de vacio del arbol, se hace verificando que el mapa del nodo raiz no esté vacio. */
bool ArbolTrie::isEmpty(){
    return root->childNodes_isEmpty();
}

/* Busqueda de palabras dado un prefijo o sufijo, esto se determina por la variable booleana inverso*/
set<string> ArbolTrie::search_words(string& palabra, bool inverso){
    set<string> result;
    // Se usa la busqueda del prefijo o sufijo.
    TrieNode* currentNode = search_prefix(palabra);
    // Si es nullo se retorna la lista vacia.
    if (currentNode == nullptr){
        return result;
    } else
    // En caso contrario se quita la letra del nodo en la palabra y se llama la función de busqueda de palabras en cada nodo
        palabra.pop_back();
        // Esta función es recursiva
        currentNode->search_words_childNodes(result, palabra, inverso);
    
    return result;
}