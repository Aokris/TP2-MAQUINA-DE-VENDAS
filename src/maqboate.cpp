#include "maqboate.h"

using namespace std;

void MaquinaBoate::MaquinaDeVendas(){
    
    cout << " Digite o ID do Filme Desejado " << endl;
}

void MaquinaBoate::VendasBoate(vector<Boate> boate, Adulto adulto){
    _boate = boate;
    int quant = 0, q = 0;
    
    vector<Boate>::iterator it;

    cout<<"VENDA DE INGRESSO: BOATE"<<endl<<endl;
    cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;

    for(it = _boate.begin(); it!=_boate.end(); it++){
        cout<<it->get_id()<<" "<<it->get_nome()<<endl;
        cout<<"Duracao: Inicio"<<it->get_horaInicio()<<" - Fim: "<<it->get_horaFim()<<endl<<endl;
    }

    int n;
    cout<<"Opcao: ";
    cin>>n;

    if(n > _boate.size()){
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
            
            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < sizeof(capacidade)){
                    q++;
                }else if (q == sizeof(capacidade)){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    
                    if(adulto.get_categoria() == "idoso"){
                        capacidade[q] = capacidade[q] - quant;
                        adulto.set_saldo(quant * it->get_quota_Idoso());
                        
                    }else if(adulto.get_categoria() == "adulto"){
                        capacidade[q] = capacidade[q] - quant;
                        adulto.set_saldo(quant * preco[q]);
                    }
                    
                    capacidade[q] - quant;
                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != sizeof(capacidade));

            std::cout << "Compra Realizada com Sucesso" << std::endl;
            std::cout << it->get_id() << " " << it->get_nome()<< " - Duracao: Inicio - ";
            std::cout << it->get_horaInicio()<<" - Fim: " << it->get_horaFim()<<std::endl<< std::endl;
            std::cout << adulto.get_id() << " " << adulto.get_nome();
            std::cout << " Saldo Atual: " << adulto.get_saldo() << std::endl << std::endl;
            
            return;

        }
    }
}