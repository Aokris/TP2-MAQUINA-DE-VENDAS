#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>

#include "funcoes.h"
#include "crianca.h"
#include "idoso.h"
#include "totem.h"

int le_usuarios(int &j, int &qcria, int &qadult, int &qidos, std::string file_usuarios, int *depend, int *idad, vector<Crianca> &crianca, vector<Adulto> &adulto, vector<Idoso> &idoso);

int le_eventos(int &contagem_donos, int &qBoate, int &qShow, int &qCine, int &qFanto, int *IdDono, int &maiorQuota, int &idMaiorQuota, std::string file_eventos, vector<Cinema> &cinema, vector<Show> &show, vector<Boate> &boate, vector<TeatroFantoche> &fantoche, map<double, int> &precos);

void IdadeDosUsuarios(int *idad, int max);

void NumeroDependentes(int *depend, int qp, int np);

void menuvenda(Adulto &adulto, vector<Show> &show, vector<Cinema> &cinema, vector<TeatroFantoche> &fantoche, vector<Boate> &boate);


#endif