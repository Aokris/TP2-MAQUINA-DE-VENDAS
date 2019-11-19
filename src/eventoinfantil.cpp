#include "eventoinfantil.h"
#include <iostream>
#include <string>
#include <vector>

EventoInfantil::EventoInfantil(int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos):
    Evento(id, nome, id_dono, capacidade, precos){
}