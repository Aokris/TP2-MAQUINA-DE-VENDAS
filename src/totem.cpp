#include <iostream>
#include <string>


#include "totem.h"

using namespace std;



void Totem::InicializarEstruturasUsuario(){
    //leitura de dados e inicialização das estruturas de usuario
}

void Totem::InicializarEstruturasEvento(){
    //inicializa as estruturas de eventos
}

//listar todos os usuarios cadastrados
void Totem::ListarUsuarios (vector<Crianca> cria, vector<Adulto> adult, vector<Idoso> idos){
    vector<Crianca>::iterator itCria;
    vector<Adulto>::iterator itAdul;
    vector<Idoso>::iterator itIdos;

    for (itCria = cria.begin(); itCria != cria.end();itCria++){//Impressão de todas as crianças
        std::cout << endl << itCria->get_id() << " ";
        std::cout << itCria->get_nome() << " ";
        std::cout << itCria->get_idade() << " ";
        std::cout << itCria->get_id_responsavel() << " ";
        std::cout << itCria->get_saldo() << " ";
        std::cout << itCria->get_categoria() << std::endl;
    }

    for (itAdul = adult.begin(); itAdul != adult.end();itAdul++){// Imprime todos os adultos 
        std::cout << endl << itAdul->get_id() << " ";
        std::cout << itAdul->get_nome() << " ";
        std::cout << itAdul->get_idade() << " ";
        std::cout << itAdul->get_saldo() << " ";
        std::cout << itAdul->get_categoria() << std::endl;
    }

    for (itIdos = idos.begin(); itIdos != idos.end();itIdos++){//Imprime todos os idosos
        std::cout << endl << itIdos->get_id() << " ";
        std::cout << itIdos->get_nome() << " ";
        std::cout << itIdos->get_idade() << " ";
        std::cout << itIdos->get_saldo() << " ";
        std::cout << itIdos->get_categoria() << std::endl;
    }
}

//procura se o id do usuario existe
int Totem::ComprarIngresso(){
    int iduser;
    cout<<"Digite o ID do usuario: ";
    cin>>iduser;
    /*if(iduser == /*id do usuario){
        return 1;
    }else*/ return 0;
        
}