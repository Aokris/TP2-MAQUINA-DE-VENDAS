#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>

#include "funcoes.h"
#include "crianca.h"
#include "idoso.h"
#include "totem.h"

int main(){
/* ---------- Criação de Objetos - USUÁRIOS ---------- */

    vector<Crianca> crianca; //iniciar o vetor de crianças
    vector<Crianca>::iterator itc;

    vector<Adulto> adulto; //iniciar o vetor de adultos
    vector<Adulto>::iterator ita;

    vector<Idoso> idoso; //iniciar o vetor de idosos
    vector<Idoso>::iterator itd;


    /* ---------- Criação de Objetos - EVENTOS ---------- */
    vector<Cinema> cinema;
    vector<Cinema>::iterator itcine;

    vector<Show> show;
    vector<Show>::iterator itshow;

    vector<Boate> boate;
    vector<Boate>::iterator itboate;

    vector<TeatroFantoche> fantoche;
    vector<TeatroFantoche>::iterator itfan;

    string aux;   
    int n = 0;

    while(n != 4){

        cout << "SISTEMA DE VENDAS DE INGRESSO" <<endl << endl;
        cout << "Favor escolher uma das opções abaixo:" << endl << endl;
        cout << "1. Carregar usuarios e eventos" << endl;
        cout << "2. Exibir usuarios cadastrados" << endl;
        cout << "3. Comprar ingressos" << endl;
        cout << "4. Sair" << endl << endl;

        cout << "Opcao: ";
        cin >> n;

        if(n == 1){
            
            //executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
            Totem::InicializarEstruturasUsuario(crianca, adulto, idoso);
            Totem::InicializarEstruturasEvento(show, cinema, fantoche, boate);
        
        
        } else if(n == 2){
            //exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
            Totem::ListarUsuarios();
        
        
        } else if(n == 3){            
            //solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
            int iduser = Totem::ComprarIngresso();
            
            if(iduser >= 0){
                //procura o usuario dono da id do comprador
                for(ita == adulto.begin(); ita!= adulto.end();ita++){
                    if(iduser == ita->get_id()){
                    Adulto comprador1 = *ita;
                    //envia o comprador e os objetos de evento para a maquina de vendas
                    menuvenda(comprador1, show, cinema, fantoche, boate);
                    }
                }

                for(itd == idoso.begin(); itd!= idoso.end();itd++){
                    if(iduser == itd->get_id()){
                        Idoso comprador2 = *itd;
                        //envia o comprador e os objetos de evento para a maquina de vendas
                        menuvenda(comprador2, show, cinema, fantoche, boate);
                        }
                }
            }else{ 
                cout<<"Erro: não foi possível identificar o usuario ou usuario é uma criança;"<<endl<<"Aperte qualquer tecla para continuar: ";
                cin>> aux;                
            }
        }
    }
    
    return 0;
}