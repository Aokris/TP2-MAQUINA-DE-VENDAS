#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>

using namespace std;

class Totem{
    public:
        virtual void MaquinaDeVendas() = 0;
        static void Vendas();
        static void InicializarEstruturasUsuario();
        static void InicializarEstruturasEvento();
        static void ListarUsuarios();
        static int ComprarIngresso();
};

#endif