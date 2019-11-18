#ifndef MAQUINA_SHOW_H
#define MAQUINA_SHOW_H

#include "totem.h"
#include "usuario.h"
#include "show.h"

class MaquinaShow : public Totem{
    private:
        vector<Show> _show;
    public:
    void MaquinaDeVendas(vector<Show> show,Usuario *Usuario);

};

#endif