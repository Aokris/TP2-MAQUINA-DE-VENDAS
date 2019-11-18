#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>

#include "adulto.h"
#include "cinema.h"
#include "teatrodefantoches.h"
#include "show.h"
#include "boate.h"


using namespace std;

std::vector<std::string> splitLine(std::string line, char sep, int &cont);
std::vector<int> readCsv( std::vector<std::vector<std::string>> &resutlCsv, std::string nameFile, char sep);

void IdadeDosUsuarios(int *idad, int max);

void NumeroDependentes(int *depend, int qp, int np);

void menuvenda(Adulto adulto, vector<Show> show, vector<Cinema> cinema, vector<TeatroFantoche> fantoche, vector<Boate> boate);


#endif