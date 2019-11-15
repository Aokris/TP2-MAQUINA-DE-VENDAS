#include "cinema.h"
#include <iostream>
#include <string>

Cinema::Cinema(int id, string nome, int id_dono, int *capacidade, int *precos, int *horario, int duracao):
    Evento(id, nome, id_dono, capacidade, precos){
    _duracao = duracao;
    _horarios = horario;
}

void Cinema::get_horarios(int *horarios){
    horarios = _horarios;
}
int Cinema::get_duracao(){
    return _duracao;
}
