#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H

#include <iostream>
#include "evento.h"
#include<vector>

class EventoInfantil :public  Evento{
    public:
        EventoInfantil(int id, string nome, int id_responsavel, vector<int> capacidade, vector<int> precos);
};

#endif