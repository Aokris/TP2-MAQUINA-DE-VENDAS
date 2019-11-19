#include "evento.h"
#include <iostream>
#include <vector>
#include <string>

Evento::Evento(int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos){
    _id = id;
    _nome =  nome;
    _id_dono = id_dono;
    _capacidade = capacidade;
    _precos = precos;
}

int Evento::get_id(){
    return _id;
}

string Evento::get_nome(){
    return _nome;
}
vector<int> Evento::get_capacidade(){
    return _capacidade;
}
void Evento::set_capacidade(vector<int> capacidade){
    _capacidade = capacidade;
}
vector<int> Evento::get_preco(){
    return _precos;
}
void Evento::set_preco(vector<int> precos){
    _precos = precos;
}