#ifndef MAQUINA_BOATE_H
#define MAQUINA_BOATE_H

#include "totem.h"

class MaquinaBoate:public Totem{
    private:
        vector<Boate> _boate;
    public:    
        void MaquinaDeVendas();
        void VendasBoate(vector<Boate> boate,Adulto adulto);
    
};

#endif