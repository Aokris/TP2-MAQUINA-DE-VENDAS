#ifndef MAQUINA_BOATE_H
#define MAQUINA_BOATE_H

#include <iostream>
#include <string>
#include <vector>
#include "totem.h"
#include "boate.h"

class MaquinaBoate : public Totem{
    private:
    vector<Boate> _boate;
    public:    
    void MaquinaDeVendas(vector<Boate> boate, Usuario *Usuario);
    
};

#endif