#ifndef MAQUINA_FANTOCHE_H
#define MAQUINA_FANTOCHE_H

#include "totem.h"

class MaquinaFantoche:public Totem{
    private:
        vector<TeatroFantoche> _fant;
        int id;
    public:
    void MaquinaDeVendas();
    void VendasFantoche(vector<TeatroFantoche> fant,Adulto adulto);
};

#endif