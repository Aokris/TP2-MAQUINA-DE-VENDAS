#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "totem.h"


void Totem::InicializarEstruturasUsuario(std::vector<Crianca> crianca, std::vector<Adulto> adulto,  std::vector<Idoso> idoso){
    //leitura de dados e inicialização das estruturas de usuario
  /*  crianca = crianca;
    adulto = adulto;
    idoso = idoso;*/
}

void Totem::InicializarEstruturasEvento(std::vector<Show> show, std::vector<Cinema> cinema, std::vector<TeatroFantoche> fantoche, std::vector<Boate> boate){
    //inicializa as estruturas de eventos
    /*show = show;
    _cinema = cinema;
    _fantoche = fantoche;
    _boate = boate;*/
}

//listar todos os usuarios cadastrados
void Totem::ListarUsuarios(std::vector<Crianca> crianca, std::vector<Adulto> adulto,  std::vector<Idoso> idoso){
    std::vector<Crianca>::iterator itCria;
    std::vector<Adulto>::iterator itAdul;
    std::vector<Idoso>::iterator itIdos;

    for (itCria = crianca.begin(); itCria != crianca.end();itCria++){//Impressão de todas as crianças
        std::cout << endl << itCria->get_id() << " ";
        std::cout << itCria->get_nome() << " ";
        std::cout << itCria->get_idade() << " ";
        std::cout << itCria->get_id_responsavel() << " ";
        std::cout << itCria->get_saldo() << " ";
        std::cout << itCria->get_categoria() << std::endl;
    }

    for (itAdul = adulto.begin(); itAdul != adulto.end();itAdul++){// Imprime todos os adultos 
        std::cout << endl << itAdul->get_id() << " ";
        std::cout << itAdul->get_nome() << " ";
        std::cout << itAdul->get_idade() << " ";
        std::cout << itAdul->get_saldo() << " ";
        std::cout << itAdul->get_categoria() << std::endl;
    }

    for (itIdos = idoso.begin(); itIdos != idoso.end();itIdos++){//Imprime todos os idosos
        std::cout << endl << itIdos->get_id() << " ";
        std::cout << itIdos->get_nome() << " ";
        std::cout << itIdos->get_idade() << " ";
        std::cout << itIdos->get_saldo() << " ";
        std::cout << itIdos->get_categoria() << std::endl;
    }
}

//procura se o id do usuario existe
int Totem::ComprarIngresso(std::vector<Adulto> adulto,  std::vector<Idoso> idoso){

    std::vector<Adulto>::iterator itAdul;
    std::vector<Idoso>::iterator itIdos;

    int iduser;

    cout<<"Digite o ID do usuario: ";
    cin>>iduser;

    for(itAdul = adulto.begin(); itAdul!= adulto.end();itAdul++){
            //cout << itAdul->get_id() << endl << endl;
            if(iduser == itAdul->get_id()){
            return itAdul->get_id();
        }
    }

    for(itIdos = idoso.begin(); itIdos!= idoso.end();itIdos++){
       // cout << itIdos->get_id() << endl << endl;

        if(iduser == itIdos->get_id()){
        return itIdos->get_id();
        }
    }

     return -1;         
}