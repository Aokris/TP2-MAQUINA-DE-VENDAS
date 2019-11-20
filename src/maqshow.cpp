#include "maqshow.h"

using namespace std;

void MaquinaShow::MaquinaDeVendas(){
    
    cout << " Digite o ID do Filme Desejado " << std::endl;
}


void MaquinaShow::VendasShow(vector<Show> show,Adulto adulto){
   
    int quant = 0, q = 0,n = 0,count = 0;

    vector<Show>::iterator it;

    cout<<"VENDA DE INGRESSO: SHOW"<<std::endl<<std::endl;
    cout<<"Favor escolher uma das opções abaixo:"<<std::endl<<std::endl;

    for(it = show.begin(); it!=show.end(); it++){//Imprime as informações 
        cout<<it->get_id()<<" "<<it->get_nome() << std::endl;
        std::cout << " - Abertura Portoes: " << it->get_aberturaPortoes();
        
        vector<string> art;
        art = it->get_artistas();
        
        cout << " - Artistas - " << std::endl;
        for (int i = 0; i < art.size();i++){//Imprime os artistas
            cout << art[i] << std::endl;    
        }
        art.clear();
    }
    std::cout <<std::endl<<std::endl;

    cout << "Opcao: ";
    cin >> n;
    for(it = show.begin(); it != show.end(); it++){
        if(n == it->get_id()){
            count++;
            break;
        }
    }
    if(count == 0){
        std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
        return;
    }

    if(n < 0){
        std::cout << ("Erro: show nao existente") << std::endl;
        return;
    }

    for(it = show.begin(); it!=show.end(); it++){//realização de compra
        if (it->get_id() == n){

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
            std::cout << it->get_id()<< " " << it->get_nome()<< " - Abertura - ";
            std::cout << it->get_aberturaPortoes() << std::endl<< std::endl;
            std::cout << adulto.get_id() << " " << adulto.get_nome();
            std::cout << " Saldo Atual: " << adulto.get_saldo() << std::endl << std::endl;
            
            return;

        }
    }
}