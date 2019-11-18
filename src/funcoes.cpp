#include "funcoes.h"
#include <map>
#include <algorithm>

// 1. Função que imprime a idade dos usuarios segundo o especificado (vetor idades, quantidade de usuarios)
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

// 2. Numero de dependentes por adulto (vetor dependentes, quantidade criancas, quantidade adultos)
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
void menuvenda(Adulto adulto, vector<Show> show, vector<Cinema> cinema, vector<TeatroFantoche> fantoche, vector<Boate> boate){
    int n;
    cout << "SUBCATEGORIAS DE EVENTOS" << endl << endl;
    cout << "Favor escolher uma das opções abaixo:" << endl << endl;
    cout << "1. Cinema" << endl;
    cout << "2. Show" << endl;
    cout << "3. Boate" << endl;
    cout << "4. Fantoche" << endl << endl;

    cout <<"Opcao: ";
    cin >> n;

    //implementar o objeto das respectivas categorias
    switch(n)
    {
    case 1:
    //chamar a maquina de vendas de cinema
        break;
    case 2:
       //show.MaquinaDeVendas();
        break;
    case 3:
        //boate.MaquinaDeVendas();
        break;
    case 4:
        //fantoche.MaquinaDeVendas();
        break;
    default:
        break;
    }
}