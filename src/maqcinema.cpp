#include "maqcinema.h"

using namespace std;

void MaquinaCinema::MaquinaDeVendas(){
    
    cout << " Digite o ID do Filme Desejado " << endl;
}

void MaquinaCinema::VendasCinema(vector<Cinema> _cine, Adulto usuario){
    
    //-----------ERRO NA FUNÇÃO CINEMA, SEGMENTATION FAULT------------
    vector<Cinema>::iterator itCine;

    int i,*preco;

    for(itCine = _cine.begin(); itCine != _cine.end(); itCine++){//Exibindo opções de show
        int *horarios;

        std::cout << std::endl << itCine->get_id() << " ";
        std::cout << itCine->get_nome() << " ";
        itCine->get_horarios(horarios);

        for(int j = 0; j != sizeof(horarios); j++){//Exibição de Horarios
            std::cout << " " << horarios[j] ;
        }
        std::cout << itCine->get_duracao();
        std::cout << std::endl << std::endl;
    }
    //--------O ERRO ESTA NA FUNÇÃO ACIMA-----------
    cin >> i;


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

            int *horarios,k,*capacidade,q,quant;//auxiliares

            itCine->get_horarios(horarios);
            
            std::cout << "Escolha o Horario " << endl;

            for(int j = 0; j != sizeof(horarios); j++){//Imprimindo as opções de horarios
                std::cout << j << " " << horarios[j] << std::endl;
            }

            cin >> k;

//Tratamento de erros
            if(k > sizeof(horarios)){
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