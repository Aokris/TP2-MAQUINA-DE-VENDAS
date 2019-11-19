#include "boate.h"
#include <iostream>
#include <string>
#include <vector>

Boate::Boate(int quota_idoso, int horaInicio, int horaFim, int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos):
    EventoAdulto(id, nome, id_dono, capacidade, precos, quota_idoso){
    _horaInicio = horaInicio;
    _horaFim = horaFim;
}

int Boate::get_horaInicio(){
    return _horaInicio;
}

int Boate::get_horaFim(){
    return _horaFim;
}
