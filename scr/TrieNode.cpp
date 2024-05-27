#include "TrieNode.h"

/* Creadores de instancias de TrieNode */
TrieNode::TrieNode(){
    flagWord = false;
    letter = ' ';
}
TrieNode::TrieNode(char c){
    flagWord = false;
    letter = c;
}

/* Obtenedores de atributos */
bool TrieNode::getFlagWord(){
    return flagWord;
}
char TrieNode::getLetter(){
    return letter; 
}

/* Fijadores del valor de atributos*/
void TrieNode::setFlagWord(bool flag){
    flagWord = flag; 
}
void TrieNode::setLetter(char c){
    letter = c; 
} 

/* Función que inserta un nuevo nodo construido de un caracter dado. */
void TrieNode::insert_childNode(char c){
    // Se crea un nodo nuevo y se agrega
    TrieNode* newNode = new TrieNode(c);
    childNodes[c] = newNode;
}

/* Obtiene un nodo del mapa dado un caracter clave. */
TrieNode* TrieNode::get_nodo_key(char c){
    return childNodes[c];
}

/* Función que busca las palabras construidas a partir de un prefijo y nodo dado. */
void TrieNode::search_words_childNodes(set<string>& list_words, string wordAux, bool inverso){
    wordAux += this->getLetter();
    string ad = wordAux;
    // Se verifica si el nodo actual contiene una palabra.
    if (this->flagWord){
        // Si es así se verifica que sea inverso para invertir la palabra antes de agregar a lista
        if (inverso)
            reverse(ad.begin(), ad.end());
        // Se agrega a la lista de palabras
        list_words.insert(ad);
    }
    // Si el mapa de nodos hijos no está vacio entra a cada nodo.
    if (!this->childNodes_isEmpty()){
        // Se itera sobre cada elemento nodo del mapa.
        for (auto c : childNodes){
            TrieNode* nodeChild = c.second;
            nodeChild->search_words_childNodes(list_words, wordAux, inverso);
        }
    }
}

/* Función que verifica si el mapa de nodos hijos está vacio. */
bool TrieNode::childNodes_isEmpty(){
    if (childNodes.empty())
        return true;
    else
        return false;
}

/* Función que verifica si una llava dada está dentro del mapa de punteros de nodos hijos. */
bool TrieNode::key_exist(char c){
    auto iterador = childNodes.find(c);
    // Retorna verdadero si se encuentra.
    if (iterador != childNodes.end()){
        return true;
    } else {
        return false;
    }
}

