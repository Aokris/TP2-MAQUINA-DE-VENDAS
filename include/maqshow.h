#ifndef MAQUINA_SHOW_H
#define MAQUINA_SHOW_H

#include "totem.h"
#include "usuario.h"

class MaquinaShow : public Totem{
    private:
        vector<Show> _show;
    public:
    void MaquinaShow::MaquinaDeVendas(vector<Show> show,Usuario * Usuario);

};

#endif