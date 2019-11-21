#include "maqshow.h"

using namespace std;

void MaquinaShow::MaquinaDeVendas(){
    
    cout << endl<< " Digite o ID do Show Desejado " << std::endl;
}


void MaquinaShow::VendasShow(vector<Show> &show,Adulto &adulto){
   
    int quant = 0, q = 0,n = 0,count = 0,aux = 0;

    vector<Show>::iterator it;

    cout<<"Favor escolher uma das opções abaixo:"<<std::endl<<std::endl;

    for(it = show.begin(); it!=show.end(); it++){//Imprime as informações 
        std::cout << "ID: " << it->get_id();
        std::cout << " - Evento: " << it->get_nome() << std::endl;
        std::cout << "Abertura dos Portoes: " << it->get_aberturaPortoes() << "h" << std::endl;
        
        vector<string> art;
        art = it->get_artistas();
        
        cout << endl << "Lista dos Artistas:" << endl << endl;
        for (int i = 0; i < art.size();i++){//Imprime os artistas
            cout << "* " << art[i] << endl;
        }
    }

    cout<<endl<<endl;

    cout<<"Opcao: ";

    cin>>n;

    cout << endl;

    for(it = show.begin(); it!=show.end(); it++){
        if(n == it->get_id()){
            count++;
            break;
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

    for(it = show.begin(); it!=show.end(); it++){//realização de compra
        if (it->get_id() == n){

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

                std::cout << "Digite a quantidade de ingressos que deseja comprar: " ;

                cin >> quant;
                cout << std::endl << std::endl;

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
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != capacidade.size());

            std::cout << endl << "Compra Realizada com Sucesso!!" << std::endl;
            std::cout << "---------------" << std::endl;
            std::cout << "RECIBO DA COMPRA" << std::endl;
            std::cout << "Show: "<< it->get_nome() << " (ID: " << it->get_id() << ")" << std:: endl;
            std::cout << "Horario de Abertura: " << it->get_aberturaPortoes() << std::endl;
            std::cout << "Comprador: " << adulto.get_nome() << " (ID: " << adulto.get_id() << ")" << std::endl;
            std::cout << "Saldo Atual: " << adulto.get_saldo() << std::endl;
            std::cout << "---------------" << std::endl << std::endl;
            
            return;

        }
    }
}