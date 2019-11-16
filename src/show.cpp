#include "show.h"
#include <iostream>
#include <string>

Show::Show(int quota_idoso, int aberturaPortoes, string *artistas,int id, string nome, int id_dono, int *capacidade, int *precos):
    EventoAdulto(id, nome, id_dono, capacidade, precos,quota_idoso){
    _artistas = artistas;
    _aberturaPortoes = aberturaPortoes;
}

void Show::get_artistas(string *artista){
    artista = _artistas;
}

int Show::get_aberturaPortoes(){
    return _aberturaPortoes;
}