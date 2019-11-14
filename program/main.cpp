#include <iostream>
#include <string>
#include "totem.h"

int main(){

    string aux;   
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
            Totem::InicializarEstruturas();//executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
        }else if(n==2){
            Totem::ListarUsuarios();//exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
        }else if(n==3){
            //solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
            if(Totem::ComprarIngresso() == 1){

            }else{ 
                cout<<"Aperte qualquer tecla para continuar: ";
                cin>> aux;
                system("cls || clear");
            }
        }
    }
    
    return 0;
}