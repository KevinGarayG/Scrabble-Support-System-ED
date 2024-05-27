#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H_

#include "Scrabble.h"
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <list>

/* Definición del TAD ConsoleIO como una clase. */
class ConsoleIO {
    private:
        /* Datos mínimos */
        map<string, map<string, string>> ayuda;
        Scrabble scrabble;

    public:
        /* Constructores */
        ConsoleIO();
        /* Funciones principales. */
        void add_letters();
        void list_commands(string command);
        /* Funciones de procesamiento de comandos y componentes. */
        void process_command(string command);
        void process_components(string command);
};

#endif