#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "adulto.h"
#include "crianca.h"
#include "idoso.h"

#include "show.h"
#include "cinema.h"
#include "teatrodefantoches.h"
#include "boate.h"

using namespace std;

class Totem {
    public:
        virtual void MaquinaDeVendas() = 0;
        static void Vendas();
        static void InicializarEstruturasUsuario(vector<Crianca> crianca, vector<Adulto> adulto,  vector<Idoso> idoso);
        static void InicializarEstruturasEvento(vector<Show> show, vector<Cinema> cinema, vector<TeatroFantoche> fantoche, vector<Boate> boate);
        static void ListarUsuarios(std::vector<Crianca> crianca, std::vector<Adulto> adulto,  std::vector<Idoso> idoso);
        static int ComprarIngresso(std::vector<Adulto> adulto,  std::vector<Idoso> idoso);
};

#endif