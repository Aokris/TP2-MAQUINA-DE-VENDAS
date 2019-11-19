#include "cinema.h"
#include <iostream>
#include <string>
#include <vector>

Cinema::Cinema(int id, string nome, int id_dono, int *capacidade, int *precos, vector<int> horarios, int duracao):
    Evento(id, nome, id_dono, capacidade, precos){
    _duracao = duracao;
    _horarios = horarios;
}

vector<int> Cinema::get_horarios(){
    return _horarios;
}
int Cinema::get_duracao(){
    return _duracao;
}
