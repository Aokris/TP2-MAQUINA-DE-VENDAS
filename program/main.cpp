#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <exception>

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
    bool vdd = false;

    /* ---------- Váriaveis Auxiliares ---------- */
    int *depend = new int[999];
    depend[0] = -1;
    int *idad = new int[999];
    int *IdDono = new int[999];
     /* ---------- Váriaveis Auxiliares - EVENTOS ---------- */
    map<double, int> precos;
    map<double, int>::iterator itprecos;
    int maiorQuota = 0, idMaiorQuota = 0;
    // Contadores
    int qBoate = 0, qShow = 0, qCine = 0, qFanto = 0;

    cout << "SISTEMA DE VENDAS DE INGRESSO" << endl;
    while(n != 4){
        cout << endl << "Favor escolher uma das opções abaixo:" << endl << endl;
        cout << "1. Carregar usuarios e eventos" << endl;
        cout << "2. Exibir usuarios cadastrados" << endl;
        cout << "3. Comprar ingressos" << endl;
        cout << "4. Sair" << endl << endl;

        cout << "Opcao: ";
        cin >> n;

        if(n == 1){
            // Contadores
            int qcria = 0, qadult = 0, qidos = 0;

        /* ---------- Tratando Entrada - USUÁRIOS ---------- */
            
            int contagem_users = 0;
            try{
                le_usuarios(contagem_users, qcria, qadult, qidos, "usuarios.csv", depend, idad, crianca, adulto, idoso);

        /* ---------- Tratando Entrada - EVENTOS ---------- */

                int contagem_donos = 0;
                le_eventos(contagem_donos, qBoate, qShow, qCine, qFanto, IdDono, maiorQuota, idMaiorQuota, "eventos.csv", cinema, show, boate, fantoche, precos);

            }catch(exception &e){
                cout << "\nOs dados no Arquivo são incompativeis. " << '\n';
            }

            //executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
            Totem::InicializarEstruturasUsuario(crianca, adulto, idoso);
            Totem::InicializarEstruturasEvento(show, cinema, fantoche, boate);
           
            if((qBoate + qShow + qCine + qFanto) == 0 || (qcria + qadult + qidos) == 0){
                vdd = false;
            }else{
                vdd = true;
            }
        
        } else if(n == 2){
            //exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
            if(vdd){
                Totem::ListarUsuarios(crianca, adulto, idoso);
            }else{
                cout << "Os arquivos não foram carregados" << endl;
            }
        
        
        } else if(n == 3){
            if(vdd){
                //solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
                int iduser = Totem::ComprarIngresso(adulto, idoso);

                if(iduser >= 0){
                    //procura o usuario dono da id do comprador
                    for(ita = adulto.begin(); ita!= adulto.end();ita++){
                        if(iduser == ita->get_id()){
                            //envia o comprador (*ita) e os objetos de evento para a maquina de vendas
                            menuvenda(*ita, show, cinema, fantoche, boate);
                        }
                    }

                    for(itd = idoso.begin(); itd!= idoso.end();itd++){
                        if(iduser == itd->get_id()){
                                //envia o comprador (*itd) e os objetos de evento para a maquina de vendas
                                menuvenda(*itd, show, cinema, fantoche, boate);
                            }
                    }
                }else{ 
                    cout<<"Erro: não foi possível identificar o usuario ou usuario é uma criança;"<<endl<<"Aperte qualquer tecla para continuar: ";
                    cin>> aux;                
                }
            }else{
                cout << "Os arquivos não foram carregados" << endl;
            }
        }
    }
    
    delete [] IdDono;
    delete [] depend;
    delete [] idad;

    return 0;
}