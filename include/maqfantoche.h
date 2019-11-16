#ifndef MAQUINA_FANTOCHE_H
#define MAQUINA_FANTOCHE_H

#include "totem.h"
#include "teatrodefantoches.h"
#include "usuario.h"

class MaquinaFantoche : public Totem{
    private:
        vector<TeatroFantoche> _fant;
        int id;
    public:
    void MaquinaDeVendas(vector<TeatroFantoche> fant,Usuario * Usuario);
    void MaquinaFantoche::get_dados();
};

#endif