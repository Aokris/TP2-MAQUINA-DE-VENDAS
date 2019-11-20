#include "maqshow.h"

using namespace std;

void MaquinaShow::MaquinaDeVendas(){
    
    cout << " Digite o ID do Show Desejado " << std::endl;
}


void MaquinaShow::VendasShow(vector<Show> show,Adulto adulto){
   
    int quant = 0, q = 0,n = 0,count = 0;

    vector<Show>::iterator it;

    cout<<"VENDA DE INGRESSO: SHOW"<<std::endl<<std::endl;
    cout<<"Favor escolher uma das opções abaixo:"<<std::endl<<std::endl;

    for(it = show.begin(); it!=show.end(); it++){//Imprime as informações 
        std::cout<< "ID: " << it->get_id() << " - Evento: " << it->get_nome() << std::endl;
        std::cout << "Abertura dos Portoes: " << it->get_aberturaPortoes() << "h" << std::endl;
        
        vector<string> art;
        art = it->get_artistas();
        
        cout << "Lista dos Artistas:" << endl;
        for (int i = 0; i < art.size();i++){//Imprime os artistas
            cout << " - " << ". " << art[i] << endl;    // Tem algum problema aqui, tá imprimindo um 6
        }
    }

    cout<<endl<<endl;

    cout<<"Opcao: ";

    cin>>n;

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
            
            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < capacidade.size()){
                    q++;
                }else if (q == capacidade.size()){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != capacidade.size());

            if(adulto.get_categoria() == "idoso"){
                if(!(adulto.set_saldo(quant * preco[q]))){
                    return;
                }
                capacidade[q] = capacidade[q] - quant;
                
            }else if(adulto.get_categoria() == "adulto"){
                if(!(adulto.set_saldo(quant * preco[q]))){
                    return;
                }
                capacidade[q] = capacidade[q] - quant;
            }

            std::cout << "Compra Realizada com Sucesso" << std::endl;
            std::cout << it->get_id()<< " " << it->get_nome()<< " - Abertura - ";
            std::cout << it->get_aberturaPortoes() << std::endl<< std::endl;
            std::cout << adulto.get_id() << " " << adulto.get_nome();
            std::cout << " Saldo Atual: " << adulto.get_saldo() << std::endl << std::endl;
            
            return;

        }
    }
}