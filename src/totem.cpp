#include <iostream>
#include <string>

#include "totem.h"

using namespace std;

Totem::Totem(){

}

void Totem::Menu(){

    int n = 0;

    while(n != 4){
        cout<<"SISTEMA DE VENDAS DE INGRESSO"<<endl<<endl;
        cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;
        cout<<"1. Carregar usuarios e eventos"<<endl;
        cout<<"2. Exibir usuarios cadastrados"<<endl;
        cout<<"3. Comprar ingressos"<<endl;
        cout<<"4. Sair"<<endl<<endl;

        cout<<"Opcao: ";
        cin>>n;
        system("cls || clear");

        if(n == 1){
            InicializarEstruturas();//executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
        }else if(n==2){
            ListarUsuarios();//exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
        }else if(n==3){
            ComprarIngresso();//solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
        }
    }
}

void Totem::InicializarEstruturas(){
    //leitura de dados e inicialização das estruturas do tp1
}

void Totem::ListarUsuarios(){
    //listar todos os usuarios cadastrados
}

void Totem::ComprarIngresso(){

    int iduser;

    cout<<"Digite o ID do usuario: ";
    cin>>iduser;
    //procura se o id do usuario existe
        //se nao existe volta pro menu
    
}