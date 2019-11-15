#include "evento.h"
#include <iostream>
#include <string>

Evento::Evento(int id, string nome, int id_dono, int *capacidade, int *precos){
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
void Evento::get_capacidade(int *capacidade){
    capacidade = _capacidade;
}
void Evento::set_capacidade(int *capacidade){
    _capacidade = capacidade;
}