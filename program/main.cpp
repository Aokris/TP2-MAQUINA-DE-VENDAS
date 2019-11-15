#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include "totem.h"
#include "maqboate.h"
#include "maqcinema.h"
#include "maqfantoche.h"
#include "maqshow.h"

void maquinadevendas(){
    int n;
    cout<<"SUBCATEGORIAS DE EVENTOS"<<endl<<endl;
    cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;
    cout<<"1. Cinema"<<endl;
    cout<<"2. Show"<<endl;
    cout<<"3. Boate"<<endl;
    cout<<"4. Fantoche"<<endl<<endl;

    cout<<"Opcao: ";
    cin>>n;

    //implementar o objeto das respectivas categorias
    switch (n)
    {
    case 1:
        cinema.MaquinaDeVendas();
        break;
    case 2:
        show.MaquinaDeVendas();
        break;
    case 3:
        boate.MaquinaDeVendas();
        break;
    case 4:
        fantoche.MaquinaDeVendas();
        break;
    default:
        break;
    }
}

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

        if(n == 1){
            Totem::InicializarEstruturasUsuario();//executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
            Totem::InicializarEstruturasEvento();
        }else if(n==2){
            Totem::ListarUsuarios();//exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
        }else if(n==3){
            //solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
            if(Totem::ComprarIngresso() == 1){
                maquinadevendas();
            }else{ 
                cout<<"Erro: não foi possível identificar o usuario"<<endl<<"Aperte qualquer tecla para continuar: ";
                cin>> aux;
                
            }
        }
    }
    
    return 0;
}