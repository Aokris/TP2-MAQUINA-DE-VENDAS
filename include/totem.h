#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>

using namespace std;

class Totem{
    public:
        virtual void MaquinaDeVendas() = 0;
        static void InicializarEstruturas();
        static void ListarUsuarios();
        static int ComprarIngresso();
};

#endif