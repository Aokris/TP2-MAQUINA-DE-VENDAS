#include "maqfantoche.h"

using namespace std;

void MaquinaFantoche::MaquinaDeVendas(){
    
    // cout << "Digite o ID do Filme Desejado " << endl;
}

void MaquinaFantoche::VendasFantoche(vector<TeatroFantoche> fant, Adulto adulto){
    _fant = fant;

    vector<TeatroFantoche>::iterator itFant;

    int i = 0,count = 0;
    vector<int> preco;
    cout << " Digite o ID do evento " << endl;

    for(itFant = _fant.begin(); itFant != _fant.end(); itFant++){//Exibindo opções de show
        vector<int> horarios;

        std::cout << std::endl << itFant->get_id() << " ";
        std::cout << itFant->get_nome() << " ";

        horarios = itFant->get_horarios();

        for(int j = 0; j != horarios.size(); j++){//Exibição de Horarios
            std::cout << " " << horarios[j];
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
            
            std::cout << "Escolha o Horario " << endl;

            for(int j = 0; j != horarios.size(); j++){//Imprimindo as opções de horarios
                std::cout << " - " << horarios[j] << endl;
            }
            std::cout << "Opcao: ";
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

            for(int j = 0; j<capacidade.size();j++){
                cout<<capacidade[j]<<endl;
            }
            cout<<endl;
            do{//Realização de compra de ingressos

                std::cout << std::endl << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

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
            

            std::cout << std::endl << "Compra Realizada com Sucesso" << std::endl;
            std::cout << itFant->get_id() << " " << itFant->get_nome() << " ";
            std::cout << k << std::endl<< std::endl;//horario
            std::cout << adulto.get_id() << " " << adulto.get_nome();
            std::cout << " Saldo Atual: " << adulto.get_saldo() << std::endl << std::endl;
            
            return;
        }
    }
}