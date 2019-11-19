#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include "eventoadulto.h"
#include <vector>
#include <string>

class Show : public  EventoAdulto{
    protected:
    int _aberturaPortoes;
    vector<string> _artistas;
    public:
        Show(int quota_idoso, int aberturaPortoes, vector<string> artistas, int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos);
        vector<string> get_artistas();
        int get_aberturaPortoes();
};

#endif