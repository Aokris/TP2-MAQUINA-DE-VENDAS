#include "maqcinema.h"
#include <vector>

using namespace std;

void MaquinaCinema::MaquinaDeVendas(){
    
     cout << endl << " Digite o ID do Filme Desejado " << endl <<endl;
}

void MaquinaCinema::VendasCinema(vector<Cinema> &_cine, Adulto &usuario){

    vector<Cinema>::iterator itCine;
    int i = 0 ,aux = 0;
    vector<int> preco;

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Exibindo opções de show
        
        vector<int> horarios;
        
        std::cout << "ID: " << itCine->get_id();
        std::cout << " - Evento: " << itCine->get_nome() << std::endl;
        horarios = itCine->get_horarios();

        std::cout << "Horarios: ";
        for(int j = 0; j < horarios.size();j++){
            //Exibição de Horarios        
            std::cout << horarios[j] << "h ";
        }

        std::cout << std::endl << "Duracao: " << itCine->get_duracao() << "h";
        std::cout << std::endl << std::endl;
    }

    std::cout << "Opcao: ";
    std::cin >> i;
    std::cout << endl;
    int count = 0;
//tratamento de erros
    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){
        if(i == itCine->get_id()){
            count++;
            break;
        }
    }
        if(count == 0){
            std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
            return;
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
            int q = 0,quant;//auxiliares

            horarios = itCine->get_horarios();
            
            std::cout << std::endl << "Horarios: " << std::endl;
            for(int j = 0; j < horarios.size();j++){
                //Exibição de Horarios        
                std::cout << horarios[j] << "h ";
            }

            std::cout << std::endl << std::endl << "Escolha o horario desejado: " << endl << endl;
            std::cin >> k;

            count = 0;
//Tratamento de erros
            for(int j = 0; j < horarios.size();j++){
                if(k == horarios[j]){
                    count++;
                }
            }
   
            if(count == 0){ 
                std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
                return;
            }  

            if(k < 0){
                std::cout << ("Erro: filme nao existente") << std::endl;
                return;
            }

            capacidade = itCine->get_capacidade();
            preco = itCine->get_preco();

            for(int t = 1; t < preco.size();t++){
                if( preco[t-1]> preco[t] ){
                    
                    aux = preco[t];
                    preco[t] = preco[t+1];
                    preco[t+1] = aux;

                    aux = capacidade[t];
                    capacidade[t] = capacidade[t+1];
                    capacidade[t+1] = aux;
                }
            }

            do{//Realização de compra de ingressos

                std::cout << endl << "Digite a quantidade de ingressos que deseja comprar: "<< std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < capacidade.size()){
                    q++;
                }else if (q == capacidade.size()){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    if(!(usuario.set_saldo(quant * preco[q]))){
                        return;
                    }
                    capacidade[q] = capacidade[q] - quant;
                    itCine->set_capacidade(capacidade);
                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a existente" <<std::endl;
                }

            }while(q != capacidade.size());

            std::cout << endl << "Compra Realizada com Sucesso!!" << std::endl << std::endl; 
            std::cout << "---------------" << std::endl;
            std::cout << "RECIBO DA COMPRA" << std::endl;
            std::cout << "Filme: " << itCine->get_nome() << " (ID: " << itCine->get_id() << ")" << std::endl;
            std::cout << "Horario: " << k << "h - Duracao: " << itCine->get_duracao() << "h" << std::endl;
            std::cout << "Comprador: " << usuario.get_nome() << " (ID: " << usuario.get_id() << ")" << std::endl;
            std::cout << "Saldo Atual: " << usuario.get_saldo() << std::endl;
            std::cout << "---------------" << std::endl << std::endl;
            
            return;
        }
    }
}
