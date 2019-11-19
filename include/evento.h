#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>
#include "usuario.h"

class Evento{
    protected:
        int _id;
        string _nome;
        int _id_dono;
        vector<int> _capacidade;
        vector<int> _precos;
    
    public:
        Evento(int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos);
        int get_id();
        string get_nome();
        vector<int> get_capacidade();
        void set_capacidade(vector<int> capacidade);
        void set_preco(vector<int> precos);
        vector<int> get_preco();
};
#endif