#include "maqcinema.h"

#include <iostream>
#include <string>

using namespace std;

void MaquinaCinema::MaquinaDeVendas(vector<Cinema> cine){
    _cine = cine;
}


void MaquinaCinema::get_dados(){
    vector<Cinema>::iterator itCine;

    int i;
    cout << " Digite o ID do Filme Desejado " << endl;

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Exibindo opções de show

        std::cout << std::endl << itCine->get_id() << " ";
        std::cout << itCine->get_nome() << " ";

        for(int j = 0; j != sizeof(itCine->get_horarios); j++){//Exibição de Horarios
            std::cout << " " << itCine->get_horarios[j] ;
        }
        std::cout << itCine->get_duracao;
        std::cout << std::endl << std::endl;
    }
    
    cin >> i;

//tratamento de erros
    if(i > _cine.size()){
        std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
        return;
    }

    if(i < 0){
        std::cout << ("Erro: filme nao existente") << std::endl;
        return;
    }

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Logica de Compra 
        if (i == itCine->get_id()){

            int *horarios,k,*capacidade,q,quant;//auxiliares

            itCine->get_horarios(horarios);
            
            std::cout << "Escolha o Horario " << endl;

            for(int j = 0; j != sizeof(horarios); j++){//Imprimindo as opções de horarios
                std::cout << j << " " << horarios[j] << std::endl;
            }

            cin >> k;

//Tratamento de erros
            if(k > sizeof(horarios)){
                std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
                return;
            }
            if(k < 0){
                    std::cout << ("Erro: filme nao existente") << std::endl;
                    return;
            }

            itCine->get_capacidade(capacidade);

            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < sizeof(capacidade)){
                    q++;
                }else if (q == sizeof(capacidade)){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    capacidade[q] - quant;
                    break;
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != sizeof(capacidade));

            std::cout << "Compra Realizada com Sucesso" << std::endl;
            std::cout << itCine->get_id << " " << itCine->get_nome << " ";
            std::cout << itCine->get_horarios[k] << " " << itCine->get_duracao << std::endl;
            
            return;
        }
    }
}