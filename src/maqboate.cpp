#include "maqboate.h"

using namespace std;

void MaquinaBoate::MaquinaDeVendas(){
    
     cout << endl<< "Digite o ID da Boate Desejada:" << endl;
}

void MaquinaBoate::VendasBoate(vector<Boate> &boate, Adulto &adulto){
    _boate = boate;
    int quant = 0, q = 0,aux = 0;
    
    vector<Boate>::iterator it;

    cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;

    for(it = _boate.begin(); it!=_boate.end(); it++){
        cout<< "ID: " << it->get_id() <<" - Evento: "<<it->get_nome()<<endl;
        cout<<"Horario:\n  Inicio - " << it->get_horaInicio() <<"h\n  Fim - " << it->get_horaFim() << "h" << endl << endl;
    }

    int n;
    cout<<"Opcao: ";
    cin>>n;

    int count = 0;

    for(it = _boate.begin(); it!=_boate.end(); it++){
        if(n == it ->get_id()){
            count++;
        }
    }
    if(count == 0){
        std::cout << ("Erro: impossivel encontrar o evento") << std::endl;
        return;
    }

    if(n < 0){
        std::cout << ("Erro: evento nao existente") << std::endl;
        return;
    }

    for(it = _boate.begin(); it!=_boate.end(); it++){
        if(n == it->get_id()){

            vector<int> capacidade,preco;
            capacidade = it->get_capacidade();
            preco = it->get_preco();
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

                std::cout << endl<< "Digite a quantidade de ingressos que deseja comprar: ";
                cin >> quant;
                cout << endl << std::endl;

                if(capacidade[q] == 0 && q < capacidade.size()){
                    q++;
                }else if (q == capacidade.size()){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    
                    if(adulto.get_categoria() == "idoso"){

                        if(!(adulto.set_saldo(quant * preco[q]))){
                            return;
                        }
                        capacidade[q] = capacidade[q] - quant;
                        it->set_capacidade(capacidade);

                    }else if(adulto.get_categoria() == "adulto"){

                        if(!(adulto.set_saldo(quant * preco[q]))){
                            return;
                        }
                        capacidade[q] = capacidade[q] - quant;
                        it->set_capacidade(capacidade);
                    }
                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a existente" <<std::endl;
                }

            }while(q != capacidade.size());

            std::cout << endl << "Compra Realizada com Sucesso!!" << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
            std::cout << "RECIBO DA COMPRA" << std::endl;
            std::cout << "Evento: " << it->get_nome() << " (ID: " << it->get_id() << ")" << std::endl;
            std::cout << "Inicio: " << it->get_horaInicio()<<"h - Fim: " << it->get_horaFim() << "h" << std::endl;
            std::cout << "Comprador: " << adulto.get_nome() << " (ID: " << adulto.get_id() << ")" << std::endl;
            std::cout << "Saldo Atual: " << adulto.get_saldo() << std::endl;
            std::cout << "---------------" << std::endl << std::endl;
            
            return;

        }
    }
}