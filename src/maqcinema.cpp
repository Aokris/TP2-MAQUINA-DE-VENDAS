#include "maqcinema.h"
#include <vector>

using namespace std;

void MaquinaCinema::MaquinaDeVendas(){
    
    cout << " Digite o ID do Filme Desejado " << endl;
}

void MaquinaCinema::VendasCinema(vector<Cinema> _cine, Adulto usuario){

    vector<Cinema>::iterator itCine;
    int i;
    vector<int> preco;

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Exibindo opções de show
        
        vector<int> horarios;
        
        std::cout << std::endl << itCine->get_id() << " ";
        std::cout << itCine->get_nome()<< " ";
        horarios = itCine->get_horarios();

        for(int j = 0; j < horarios.size();j++){
            //Exibição de Horarios        
            std::cout <<"Horarios: " <<" " << horarios[j];
        }

        std::cout <<"Duracao: "<< itCine->get_duracao();
        std::cout << std::endl << std::endl;
    }
    
    cin >> i;

//tratamento de erros
    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){
        if(i == itCine->get_id()){
        break;
        }else{
            std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
            return;
        }
    }

    if(i < 0){
        std::cout << ("Erro: filme nao existente") << std::endl;
        return;
    }
    int k;
    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Logica de Compra 
        if (i == itCine->get_id()){

            vector<int> horarios;
            
            vector<int> capacidade;
            int q,quant;//auxiliares

            horarios = itCine->get_horarios();
            
        for(int j = 0; j < horarios.size();j++){
            //Exibição de Horarios        
            std::cout <<"Horarios: " <<" " << horarios[j] ;
        }

            std::cout <<endl<< "Escolha o Horario " << endl;
            cin >> k;

//Tratamento de erros
    for(int j = 0; j < horarios.size();j++){
            if(k == horarios[j]){
                break;
            }else { 
                std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
                return;
            }
        }                
        if(k < 0){
            std::cout << ("Erro: filme nao existente") << std::endl;
            return;
        }

            capacidade = itCine->get_capacidade();
            preco = itCine->get_preco();

            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < capacidade.size()){
                    q++;
                }else if (q == capacidade.size()){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    capacidade[q] = capacidade[q] - quant;
                    usuario.set_saldo(quant * preco[q]);

                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != capacidade.size());

            std::cout << "Compra Realizada com Sucesso" << std::endl;
            std::cout << itCine->get_id() << " " << itCine->get_nome() << " ";
            std::cout << k << " " << itCine->get_duracao() << std::endl<< std::endl;
            std::cout << usuario.get_id() << " " << usuario.get_nome();
            std::cout << " Saldo Atual: " << usuario.get_saldo() << std::endl << std::endl;
            
            return;
        }
    }
}