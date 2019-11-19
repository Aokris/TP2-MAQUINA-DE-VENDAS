#ifndef TEATRO_FANTOCHE_H
#define TEATRO_FANTOCHE_H

#include <iostream>
#include "eventoinfantil.h"
#include <vector>

class TeatroFantoche : public  EventoInfantil{
    protected:
        vector<int> _horarios;
    public:
        TeatroFantoche(vector<int> horarios, int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos);
        vector<int> get_horarios();
};

#endif