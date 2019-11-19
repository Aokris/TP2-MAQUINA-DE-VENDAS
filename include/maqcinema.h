#ifndef MAQUINA_CINEMA_H
#define MAQUINA_CINEMA_H

#include "totem.h"

class MaquinaCinema:public Totem{
    private:
        vector<Cinema> _cine;        
    public:
        virtual void MaquinaDeVendas();
        void VendasCinema(vector<Cinema> _cine, Adulto usuario);
       

};

#endif