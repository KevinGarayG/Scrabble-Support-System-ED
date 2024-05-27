#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

/* Definición del TAD TrieNode como una clase. */
class TrieNode {
    private:
        /* Datos mínimos */
        bool flagWord;
        char letter;
        map<char, TrieNode*> childNodes;
    
    public:
        /* Constructores */
        TrieNode();
        TrieNode(char c);

        /* getters */
        bool getFlagWord();
        char getLetter();

        /* getters */
        void setFlagWord(bool flag);
        void setLetter(char c);

        /* Manejo de los nodos hijos. */
        void insert_childNode(char c);
        TrieNode* get_nodo_key(char c);
        bool childNodes_isEmpty();
        bool key_exist(char c);

        /* Función principal. */
        void search_words_childNodes(set<string>& list_words, string wordAux, bool inverso);
};

#endif