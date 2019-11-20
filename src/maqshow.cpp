#include "maqshow.h"

using namespace std;

void MaquinaShow::MaquinaDeVendas(){
    
    // cout << "Digite o ID do Filme Desejado " << endl;
}


void MaquinaShow::VendasShow(vector<Show> show,Adulto adulto){
    _show = show;
    int quant = 0, q = 0;

    vector<Show>::iterator it;

    cout<<"VENDA DE INGRESSO: SHOW"<<endl<<endl;
    cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;

    for(it = _show.begin(); it!=_show.end(); it++){//Imprime as informações 
        cout<< "ID: " << it->get_id() << " - Evento: " << it->get_nome() << endl;
        std::cout << "Abertura dos Portoes: " << it->get_aberturaPortoes() << "h" << endl;
        
        vector<string> art;
        art = it->get_artistas();
        
        cout << "Lista dos Artistas:" << endl;
        for (int i = 0; i < sizeof(art);i++){//Imprime os artistas
            cout << "  " << i << ". " << art[i] << endl;    // Tem algum problema aqui, tá imprimindo um 6
        }
        
    }
    std::cout <<endl<<endl;

    int n;
    cout<<"Opcao: ";
    cin>>n;
    int count = 0;

    for(it = _show.begin(); it!=_show.end(); it++){
        if(n == it->get_id()){
            count++;
        }
    }

    if(count == 0){
        std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
        return;
    }
    if(n < 0){
        std::cout << ("Erro: filme nao existente") << std::endl;
        return;
    }

    for(it = _show.begin(); it!=_show.end(); it++){//realização de compra
        if (it->get_id() == n){

            vector<int> capacidade,preco;
            capacidade = it->get_capacidade();
            preco = it->get_preco();
            
            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < capacidade.size()){
                    q++;
                }else if (q == capacidade.size()){
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
            std::cout << it->get_id()<< " " << it->get_nome()<< " - Abertura - ";
            std::cout << it->get_aberturaPortoes() << std::endl<< std::endl;
            std::cout << adulto.get_id() << " " << adulto.get_nome();
            std::cout << " Saldo Atual: " << adulto.get_saldo() << std::endl << std::endl;
            
            return;

        }
    }
}