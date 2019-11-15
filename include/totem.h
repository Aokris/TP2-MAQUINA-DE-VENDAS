#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>
#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include <vector>

using namespace std;

class Totem{
    public:
        virtual void MaquinaDeVendas() = 0;
        static void Vendas();
        static void InicializarEstruturasUsuario();
        static void InicializarEstruturasEvento();
        static void ListarUsuarios (vector<Crianca> cria, vector<Adulto> adult, vector<Idoso> idos);
        static int ComprarIngresso();
};

#endif