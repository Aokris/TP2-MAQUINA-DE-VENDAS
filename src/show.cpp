#include "show.h"
#include <iostream>
#include <string>

Show::Show(int quota_idoso, int aberturaPortoes, vector<string> artistas,int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos):
    EventoAdulto(id, nome, id_dono, capacidade, precos, quota_idoso){
    _artistas = artistas;
    _aberturaPortoes = aberturaPortoes;
}

vector<string> Show::get_artistas(){
    return _artistas;
}

int Show::get_aberturaPortoes(){
    return _aberturaPortoes;
}