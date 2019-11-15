#ifndef MAQUINA_BOATE_H
#define MAQUINA_BOATE_H

#include <iostream>
#include <string>
#include <vector>
#include "totem.h"
#include "boate.h"

class MaquinaBoate : public Totem{
    public:    
    void MaquinaDeVendas(vector<Boate> boate);
    
};

#endif