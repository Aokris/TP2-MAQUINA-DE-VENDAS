#include "maqcinema.h"

using namespace std;

void MaquinaCinema::MaquinaDeVendas(){
    
    cout << " Digite o ID do Filme Desejado " << endl;
}

void MaquinaCinema::VendasCinema(vector<Cinema> _cine, Adulto usuario){

    vector<Cinema>::iterator itCine;
    int j = 0;
    int i;
    int *preco = new int;

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Exibindo opções de show
        
        int *horarios = new int;

        
        std::cout << std::endl << itCine->get_id() << " ";
        std::cout << itCine->get_nome()<< " ";
        itCine->get_horarios(horarios);
        cout<<horarios[j];

        while(horarios[j] != 0){
            //Exibição de Horarios
        
            std::cout <<"Horarios: " <<" " << horarios[j] ;
            j++;

        }
        std::cout <<"Duracao: "<< itCine->get_duracao();
        std::cout << std::endl << std::endl;
    }
    
    cin >> i;
    j = 0;

//tratamento de erros
    if(i > _cine.size()){
        std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
        return;
    }

    if(i < 0){
        std::cout << ("Erro: filme nao existente") << std::endl;
        return;
    }

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Logica de Compra 
        if (i == itCine->get_id()){

            int *horarios = new int[100];
            int k;
            int *capacidade = new int[100];
            int q,quant;//auxiliares

            itCine->get_horarios(horarios);
            
            

            while(horarios[j] != 0){
            //Exibição de Horarios
        
            std::cout << " " << horarios[j]<<endl ;
            j++;

        }
            std::cout <<endl<< "Escolha o Horario " << endl;
            cin >> k;

//Tratamento de erros
            if(k > j){
                std::cout << ("Erro: impossivel encontrar o filme") << std::endl;
                return;
            }
            if(k < 0){
                    std::cout << ("Erro: filme nao existente") << std::endl;
                    return;
            }

            itCine->get_capacidade(capacidade);
            itCine->get_preco(preco);

            do{//Realização de compra de ingressos

                std::cout << "Digite a quantidade de ingressos que deseja comprar" << std::endl;
                cin >> quant;

                if(capacidade[q] == 0 && q < sizeof(capacidade)){
                    q++;
                }else if (q == sizeof(capacidade)){
                    std::cout << "Quantidade de ingressos esgotada" << std::endl;
                }

                if(quant <= capacidade[q] && quant >= 0){
                    capacidade[q] = capacidade[q] - quant;
                    usuario.set_saldo(quant * preco[q]);

                    break;
                    
                }else{
                    std::cout << "Quantidade de ingressos maior que a exitente" <<std::endl;
                }

            }while(q != sizeof(capacidade));

            std::cout << "Compra Realizada com Sucesso" << std::endl;
            std::cout << itCine->get_id() << " " << itCine->get_nome() << " ";
            std::cout << horarios[k] << " " << itCine->get_duracao() << std::endl<< std::endl;
            std::cout << usuario.get_id() << " " << usuario.get_nome();
            std::cout << " Saldo Atual: " << usuario.get_saldo() << std::endl << std::endl;
            
            return;
        }
    }
}