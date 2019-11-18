#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>
#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include <vector>
#include "funcoes.h"

using namespace std;

class Totem{
    public:
        virtual void MaquinaDeVendas() = 0;
        static void Vendas();
        static void InicializarEstruturasUsuario(vector<Crianca> crianca, vector<Adulto> adulto,  vector<Idoso> idoso);
        static void InicializarEstruturasEvento(vector<Show> show, vector<Cinema> cinema, vector<TeatroFantoche> fantoche, vector<Boate> boate);
        static void ListarUsuarios (vector<Crianca> cria, vector<Adulto> adult, vector<Idoso> idos);
        static int ComprarIngresso(vector<Adulto> adult, vector<Idoso> idos);
};

#endif