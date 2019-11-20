#include "funcoes.h"
#include "maqshow.h"
#include "maqfantoche.h"
#include "maqcinema.h"
#include "maqboate.h"
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "funcoes.h"
#include "crianca.h"
#include "idoso.h"
#include "totem.h"

int le_usuarios(int &j, int &qcria, int &qadult, int &qidos, std::string file_usuarios, int *depend, int *idad, vector<Crianca> &crianca, vector<Adulto> &adulto, vector<Idoso> &idoso){
    // Definindo auxiliares
    int id = 0;
    float saldo = 0.0;
    string nome, categoria;

    // Abrindo arquivo
    std::ifstream file_a(file_usuarios);

    if(file_a.is_open()){
        // Separar em uma função
        std::string linha, linha_aux;
        std::vector<string> tratamento;
        
        while(getline(file_a, linha)){
            stringstream X(linha);
            while(getline(X, linha_aux, ',')){
                tratamento.push_back(linha_aux);
            }
            int i = 0;
            id = stoi(tratamento[i]); i++;
            categoria = (tratamento[i]); i++;
            nome = (tratamento[i]); i++;
            idad[j] = stoi(tratamento[i]); i++;
            saldo = stof(tratamento[i]); i++;

            if(categoria == "crianca"){
                depend[qcria] = stoi(tratamento[i]); i++;
                Crianca c(id, categoria, nome, idad[j], saldo, depend[qcria]);
                crianca.push_back(c);
                qcria++;;

            } else if(categoria == "adulto"){
                Adulto a(id, categoria, nome, idad[j], saldo);
                adulto.push_back(a);
                qadult++;

            } else if(categoria == "idoso"){
                Idoso ido(id, categoria, nome, idad[j], saldo);
                idoso.push_back(ido);
                qidos++;

            } else {
                cout << "Houve um erro na leitura do arquivo, garanta que as classes de usuários foram identificadas corretamente!" << endl;
                return EXIT_FAILURE;
            }


            j++;

            tratamento.clear();
        }

        
    } else {
        cout << "Erro, nao deu pra abrir!" << endl;
        return EXIT_FAILURE;
    }

}

int le_eventos(int &contagem_donos, int &qBoate, int &qShow, int &qCine, int &qFanto, int *IdDono, int &maiorQuota, int &idMaiorQuota, std::string file_eventos, vector<Cinema> &cinema, vector<Show> &show, vector<Boate> &boate, vector<TeatroFantoche> &fantoche, map<double, int> &precos){
    // Definindo auxiliares
    int NumTipos = 0;
    int IdEven = 0;
    std::string categoriaEven;
    std::string subcategEven;
    std::string nomeEven;
    int quotaIdoso = 0;
    int duracao = 0;
    int horaIni = 0;
    int horaFim = 0;
    int abertura = 0;

    // Abrindo arquivo
    std::ifstream file_b(file_eventos);

    if(file_b.is_open()){
        // Separar em uma função
        std::string linha, linha_aux;
        std::vector<string> tratamento2;
        
        
        while(getline(file_b, linha)){
            stringstream Y(linha);
            while(getline(Y, linha_aux, ',')){
                tratamento2.push_back(linha_aux);
            }
            
            int i = 0;
            IdEven = stoi(tratamento2[i]); i++;

            categoriaEven = tratamento2[i]; i++;

            // Se evento for do tipo cinema, ele não tem subcategoria
            if(categoriaEven != "cinema"){
                subcategEven = tratamento2[i]; i++;
            }

            nomeEven = tratamento2[i]; i++;

            IdDono[contagem_donos] = stoi(tratamento2[i]); i++;

            NumTipos = stoi(tratamento2[i]); i++;

            //int *ingEven = new int[NumTipos];
            //int *ValorEven = new int[NumTipos];

            vector<int> ingEven;
            vector<int> ValorEven;

            for(int aux_tipos = 0; aux_tipos < NumTipos; aux_tipos++){

                ingEven.push_back(stoi(tratamento2[i])); i++;

                ValorEven.push_back(stof(tratamento2[i])); i++;

                precos[ValorEven[aux_tipos]] += ingEven[aux_tipos];
            }

            //int *horario = new int[999];
            vector<int> horario;
            // Se o evento não for do tipo Adulto, a leitura dos horários é realizada
            int aux_size = tratamento2.size() - i;
            if(categoriaEven == "infantil"){
                for(int aux_h = 0; aux_h < aux_size; aux_h++){
                    horario.push_back(stoi(tratamento2[i])); i++;
                }

                TeatroFantoche fan(horario, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                fantoche.push_back(fan);
                qFanto++;

            } else if(categoriaEven == "cinema"){
                for(int aux_h = 0; aux_h < aux_size - 1; aux_h++){
                    horario.push_back(stoi(tratamento2[i])); i++;
                }
                
                duracao = stoi(tratamento2[i]); i++;

                Cinema cine(IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven, horario, duracao);
                cinema.push_back(cine);
                qCine++;

            } else if(categoriaEven == "adulto"){
                quotaIdoso = stoi(tratamento2[i]); i++;

                if(quotaIdoso > maiorQuota){
                    maiorQuota = quotaIdoso;
                    idMaiorQuota = IdEven;
                }

                if(subcategEven == "boate"){
                    horaIni = stoi(tratamento2[i]); i++;
                    horaFim = stoi(tratamento2[i]); i++;

                    Boate boa(quotaIdoso, horaIni, horaFim, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                    boate.push_back(boa);
                    qBoate++;

                } else if(subcategEven == "show"){
                    abertura = stoi(tratamento2[i]); i++;
                    
                    vector<string> artistas;
                    int aux_arts = 0;
                    for(; i < tratamento2.size(); i++){
                        artistas.push_back(tratamento2[i]);
                        aux_arts++;
                    }

                    Show sho(quotaIdoso, abertura, artistas, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                    show.push_back(sho);
                    qShow++;
                }


            } else {
                cout << "Houve um erro na leitura do arquivo, garanta que as classes de usuários foram identificadas corretamente!" << endl;
                return EXIT_FAILURE;

            }

            //delete [] horario;
            //delete [] ingEven;
           // delete [] ValorEven;

            contagem_donos++;

            tratamento2.clear();
        }

    } else {
        cout << "Erro, nao deu pra abrir!" << endl;
        return EXIT_FAILURE;
    }

}

// 3. Função que imprime a idade dos usuarios segundo o especificado (vetor idades, quantidade de usuarios)
void IdadeDosUsuarios(int *idad, int max){
    int aux = 0, soma = 0;
    float resul = 0.0;

    for (int s = 0; s < max; s++) { 
        soma += idad[s];
    }

    std::sort(idad, idad + max);

    resul = (float)soma/max;

    // Impressao das idades minima, maxima e media
    std::cout << "Idade dos usuários:" << endl;
    std::cout << "Minima: "<< idad[0] << endl;
    std::cout << "Máxima: "<< idad[max-1] << endl;
    std::cout << "Média: "<< resul << endl << endl;
}

// 4. Numero de dependentes por adulto (vetor dependentes, quantidade criancas, quantidade adultos)
void NumeroDependentes(int *depend, int qp, int np){

    if(depend[0] == -1){
        std::cout << "Número de dependentes:" << endl;
        std::cout << "Minima: " << 0 << endl;
        std::cout << "Máxima: " << 0 << endl;
        std::cout << "Média: " << 0 << endl;
    } else {
        // Criação de map para armazenar numero de dependentes por adulto
        map<int, int> numdep;
        map<int, int>::iterator it;

        // Variaveis auxiliares
        int maior, menor, soma = 0;
        float resul;

        // Passagem para o Map
        for(int i = 0; i < qp; i++){
            numdep[depend[i]]++;
        }
        
        // Definindo o minimo e o maximo
        it = numdep.begin();
        maior = it->second;
        menor = it->second;

        for(it = numdep.begin(); it != numdep.end(); it++){
            if(maior < it->second){
                maior = it->second;
            }
            if(menor > it->second){
                menor = it->second;
            }
        }

        if(np > numdep.size()){ // Se quantidade de adultos total != quantidade de adultos com crianças
            menor = 0;
        }

        for(it = numdep.begin(); it != numdep.end(); it++){
            soma += it->second;
        }

        //Tirando a media
        resul = (float)soma/np;

        //Impressao
        std::cout << "Número de dependentes:" << endl;
        std::cout << "Minima: "<< menor << endl;
        std::cout << "Máxima: "<< maior << endl;
        std::cout << "Média: "<< resul << endl << endl;
    }
}

//Função maquina de vendas
void menuvenda(Adulto &adulto, vector<Show> &show, vector<Cinema> &cinema, vector<TeatroFantoche> &fantoche, vector<Boate> &boate){

    int n;

    MaquinaCinema cine;
    MaquinaBoate boat;
    MaquinaFantoche fant;
    MaquinaShow sshow;
    
    cout << "SUBCATEGORIAS DE EVENTOS" << endl << endl;
    cout << "Favor escolher uma das opções abaixo:" << endl << endl;
    cout << "1. Cinema" << endl;
    cout << "2. Show" << endl;
    cout << "3. Boate" << endl;
    cout << "4. Fantoche" << endl << endl;

    cout <<"Opcao: ";
    cin >> n;

    //implementar o objeto das respectivas categorias
    if(n == 1){       
        cine.MaquinaDeVendas();
        cine.VendasCinema(cinema,adulto);
    }else if (n == 2){
        sshow.MaquinaDeVendas();
        sshow.VendasShow(show,adulto);
    }else if( n == 3){
        boat.MaquinaDeVendas();
        boat.VendasBoate(boate,adulto);
    }else if(n == 4){
        fant.MaquinaDeVendas();
        fant.VendasFantoche(fantoche,adulto);
    }
}