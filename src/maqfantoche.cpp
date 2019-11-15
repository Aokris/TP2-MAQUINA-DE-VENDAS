#include "maqfantoche.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

void MaquinaFantoche::MaquinaDeVendas(vector<TeatroFantoche> fant){
    _fant = fant;
}

void MaquinaFantoche::get_dados(){
    vector<TeatroFantoche>::iterator itFant;

    int i;
    cout << " Digite o ID do evento " << endl;

    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){//Exibindo opções de show

        std::cout << std::endl << itFant->get_id() << " ";
        std::cout << itFant->get_nome() << " ";

        for(int j = 0; j != sizeof(itFant->get_horarios); j++){//Exibição de Horarios
            std::cout << " " << itFant->get_horarios[j] ;
        }
        std::cout << std::endl;
    }
    
    cin >> i;

//tratamento de erros
    if(i > _fant.size()){
        std::cout << ("Erro: impossivel encontrar o evento") << std::endl;
        return;
    }

    if(i < 0){
        std::cout << ("Erro: evento nao existente") << std::endl;
        return;
    }

    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){//Logica de Compra 
        if (i == itFant->get_id()){

            int *horarios,k,*capacidade,q,quant;
            itFant->get_horarios(horarios);
            
            std::cout << "Escolha o Horario " << endl;

            for(int j = 0; j != sizeof(horarios); j++){//Imprimindo as opções de horarios
                std::cout << j << " " << horarios[j] << std::endl;
            }

            cin >> k;

//Tratamento de erros
            if(k > sizeof(horarios)){
                std::cout << ("Erro: impossivel encontrar o evento") << std::endl;
                return;
            }
            if(k < 0){
                    std::cout << ("Erro: evento nao existente") << std::endl;
                    return;
            }

            itFant->get_capacidade(capacidade);

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
            std::cout << itFant->get_id << " " << itFant->get_nome << " ";
            std::cout << itFant->get_horarios[k] << std::endl;
            
            return;
        }
    }
}