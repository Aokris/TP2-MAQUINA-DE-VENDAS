#ifndef TOTEM_H
#define TOTEM_H

#include <iostream>
#include <string>
#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
#include <vector>
#include "funcoes.h"
#include "crianca.h"
#include "adulto.h"
#include "idoso.h"

using namespace std;

class Totem{
    private:
        static vector<Crianca> _crianca;
        static vector<Adulto> _adulto;
        static vector<Idoso> _idoso;

        static vector<Show> _show;
        static vector<Cinema> _cinema;
        static vector<TeatroFantoche> _fantoche;
        static vector<Boate> _boate;
    public:
        virtual void MaquinaDeVendas();
        static void Vendas();
        static void InicializarEstruturasUsuario(vector<Crianca> crianca, vector<Adulto> adulto,  vector<Idoso> idoso);
        static void InicializarEstruturasEvento(vector<Show> show, vector<Cinema> cinema, vector<TeatroFantoche> fantoche, vector<Boate> boate);
        static void ListarUsuarios ();
        static int ComprarIngresso();
};

#endif