#include "maqfantoche.h"

using namespace std;

void MaquinaFantoche::MaquinaDeVendas(){
    
     cout << endl<< "Digite o ID do Filme Desejado " << endl;
}

void MaquinaFantoche::VendasFantoche(vector<TeatroFantoche> &fant, Adulto &adulto){
    _fant = fant;

    vector<TeatroFantoche>::iterator itFant;

    int i = 0,count = 0,aux = 0;
    vector<int> preco;

    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){//Exibindo opções de show
        vector<int> horarios;

        std::cout << "ID: " << itFant->get_id();
        std::cout << " - Evento: " << itFant->get_nome() << std::endl;

        horarios = itFant->get_horarios();

        for(int j = 0; j != horarios.size(); j++){//Exibição de Horarios
            std::cout << horarios[j] << "h ";
        }
        
        std::cout << std::endl << std::endl;
    }
    std::cout << "Opcao: ";
    cin >> i;

//tratamento de erros
    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){
        if(i == itFant->get_id()){
            count++;
            break;
        }
    }

    if(count == 0){
        std::cout << ("Erro: impossivel encontrar o evento") << std::endl;
        return;
    }
    if(i < 0){
        std::cout << ("Erro: evento nao existente") << std::endl;
        return;
    }

    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){//Logica de Compra 
        if (i == itFant->get_id()){

            int k,q = 0,quant;
            vector<int> capacidade, horarios;
            horarios = itFant->get_horarios();
            
            std::cout <<endl << "Horarios: " << endl;

            for(int j = 0; j != horarios.size(); j++){//Imprimindo as opções de horarios
                std::cout << horarios[j] << "h ";
            }
            std::cout  << std::endl << std::endl << "Escolha o horario desejado: " << endl;
            cin >> k;

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
                    std::cout << ("Erro: evento nao existente") << std::endl;
                    return;
            }

            preco = itFant->get_preco();
            capacidade = itFant->get_capacidade();
            
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

            cout<<endl;
            do{//Realização de compra de ingressos

                std::cout << std::endl << "Digite a quantidade de ingressos que deseja comprar: " ;
                cin >> quant;
                cout << endl << std::endl;

                if(capacidade[q] == 0 && q < capacidade.size()){//dando problema aqui
                    q++;
                }else if (q == capacidade.size()){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                            
                    if(!(adulto.set_saldo(quant * preco[q]))){//dando problema aqui
                        return;
                    }
                    capacidade[q] = capacidade[q] - quant;
                    itFant->set_capacidade(capacidade);
                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != capacidade.size());
            
            std::cout << "Compra Realizada com Sucesso!!" << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
            std::cout << "RECIBO DA COMPRA" << std::endl;
            std::cout << "Evento: " << itFant->get_nome() << " (ID: " << itFant->get_id() << ")" << std::endl;
            std::cout << "Horario: " << k << "h" << std::endl;
            std::cout << "Comprador: " << adulto.get_nome() << " (ID: " << adulto.get_id() << ")" << std::endl;
            std::cout << "Saldo Atual: " << adulto.get_saldo() << std::endl;
            std::cout << "---------------" << std::endl << std::endl;
            
            return;
        }
    }
}