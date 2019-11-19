#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

#include <iostream>
#include "evento.h"
#include<vector>
class EventoAdulto : public  Evento{
    protected:
    int _quota_idoso;
    public:
        EventoAdulto(int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos, int quota_idoso);
        int get_quota_Idoso();
};

#endif