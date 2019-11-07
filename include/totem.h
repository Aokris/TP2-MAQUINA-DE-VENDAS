#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>

using namespace std;

class Totem{
    public:
        Totem(); // Construtor
        ~Totem(); // Destrutor
        void Menu();
        void InicializarEstruturas();
        void ListarUsuarios();
        void ComprarIngresso();
};

#endif