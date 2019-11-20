#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario{
    protected:
        int _id;
        string _categoria;
        string _nome;
        int _idade;
        float _saldo;
    
    public:
        Usuario(int id,string categoria, string nome, int idade, float saldo);
        int get_id();
        string get_categoria();
        string get_nome();
        int get_idade();
        float get_saldo();
        int set_saldo(int quant);
};
    
#endif
