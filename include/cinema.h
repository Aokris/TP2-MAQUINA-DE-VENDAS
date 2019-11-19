#ifndef CINEMA_H
#define CINEMA_H

#include "evento.h"
#include <iostream>
#include <vector>

class Cinema : public  Evento{
    protected:
        vector<int> _horarios;
        int _duracao;
    public:
        Cinema(int id, string nome, int id_dono, int *capacidade, int *precos, vector<int> horarios, int duracao);
        vector<int> get_horarios();
        int get_duracao();
};

#endif