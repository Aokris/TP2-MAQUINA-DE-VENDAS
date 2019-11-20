#ifndef MAQUINA_SHOW_H
#define MAQUINA_SHOW_H

#include "totem.h"

class MaquinaShow : public Totem{
    private:
        vector<Show> _show;
    public:
        void MaquinaDeVendas();
        void VendasShow(vector<Show> &show,Adulto &adulto);
};

#endif