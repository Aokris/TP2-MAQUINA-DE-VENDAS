#include "teatrodefantoches.h"
#include <iostream>
#include <string>

TeatroFantoche::TeatroFantoche(vector<int> horarios, int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos):
    EventoInfantil(id, nome, id_dono, capacidade, precos){
    _horarios = horarios;
}

vector<int> TeatroFantoche::get_horarios(){
    return _horarios;
}
