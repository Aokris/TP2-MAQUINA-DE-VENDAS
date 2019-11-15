#ifndef MAQUINA_CINEMA_H
#define MAQUINA_CINEMA_H

#include "totem.h"
#include "cinema.h"

class MaquinaCinema : public Totem{
    private:
        vector<Cinema> _cine;
    public:
        void MaquinaDeVendas(vector<Cinema> _cine);
        void get_dados();

};

#endif