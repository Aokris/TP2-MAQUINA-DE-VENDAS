#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include "eventoadulto.h"

class Show : public  EventoAdulto{
    protected:
    int _aberturaPortoes;
    string *_artistas;
    public:
        Show(int quota_idoso, int aberturaPortoes, string *artistas, int id, string nome, int id_dono, int *capacidade, int *precos);
};

#endif