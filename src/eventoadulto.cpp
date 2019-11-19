#include "eventoadulto.h"
#include <iostream>
#include <string>

EventoAdulto::EventoAdulto(int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos, int quota_idoso):
    Evento(id, nome, id_dono, capacidade, precos){
    _quota_idoso = quota_idoso;
}
int EventoAdulto::get_quota_Idoso(){
    return _quota_idoso;
}