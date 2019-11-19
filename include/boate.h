#ifndef BOATE_H
#define BOATE_H

#include <iostream>
#include "eventoadulto.h"
#include <vector>
class Boate : public  EventoAdulto{
    protected:
    int _horaInicio;
    int _horaFim;

    public:
        Boate(int quota_idoso, int horaInicio, int horaFim, int id, string nome, int id_dono, vector<int> capacidade, vector<int> precos);
        int get_horaFim();
        int get_horaInicio();
};

#endif