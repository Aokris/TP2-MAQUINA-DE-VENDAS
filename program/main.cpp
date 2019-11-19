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

    /* ---------- Váriaveis Auxiliares ---------- */
    int *depend = new int[999];
    depend[0] = -1;
    int *idad = new int[999];
    int *IdDono = new int[999];

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
            // Contadores
            int qcria = 0, qadult = 0, qidos = 0;

        /* ---------- Tratando Entrada - USUÁRIOS ---------- */
            std::cout << "Para ler o arquivo, digite o nome de cada arquivo correspondente a seguir, no formato 'arquivo.csv'." << endl;
            std::cout << "O arquivo desejado preferencialmente deve se encontrar na mesma pasta do programa e *deve* usar ; como separador" << endl;
            string file_usuarios;
            std::cout << "Digite o nome do arquivo de USUARIOS que deseja abrir: ";
            std::cin >> file_usuarios;
            
            int contagem_users = 0;
            le_usuarios(contagem_users, qcria, qadult, qidos, file_usuarios, depend, idad, crianca, adulto, idoso);


        /* ---------- Váriaveis Auxiliares - EVENTOS ---------- */
            map<double, int> precos;
            map<double, int>::iterator itprecos;
            int maiorQuota = 0, idMaiorQuota = 0;
            // Contadores
            int qBoate = 0, qShow = 0, qCine = 0, qFanto = 0;

        /* ---------- Tratando Entrada - EVENTOS ---------- */
            string file_eventos;
            std::cout << "Digite o nome do arquivo de EVENTOS que voce quer abrir: ";
            std::cin >> file_eventos;

            int contagem_donos = 0;
            le_eventos(contagem_donos, qBoate, qShow, qCine, qFanto, IdDono, maiorQuota, idMaiorQuota, file_eventos, cinema, show, boate, fantoche, precos);
            /*vector<int> hr;
            hr = cinema.begin()->get_horarios();
            cout<<hr[0]<<endl<<endl;*/
            //executa as atividades de leitura de dados e inicialização de estruturas que você implementou na primeira parte do trabalho prático.
            Totem::InicializarEstruturasUsuario(crianca, adulto, idoso);
            Totem::InicializarEstruturasEvento(show, cinema, fantoche, boate);
        
        
        } else if(n == 2){
            //exibe uma listagem de todos os usuários cadastrados no sistema, incluindo seu ID, nome, saldo, categoria (criança, adulto ou idoso) e ID do responsável, caso seja uma criança.
            Totem::ListarUsuarios(crianca, adulto, idoso);
        
        
        } else if(n == 3){            
            //solicita o fornecimento do ID de um usuário. Se o ID fornecido não estiver cadastrado ou for de uma criança, o sistema imprime uma mensagem de erro e retorna ao menu inicial.
            int iduser = Totem::ComprarIngresso(adulto, idoso);
            
            cout <<endl << iduser << endl << endl;

            if(iduser >= 0){
                //procura o usuario dono da id do comprador
                for(ita = adulto.begin(); ita!= adulto.end();ita++){
                    if(iduser == ita->get_id()){
                    Adulto comprador1 = *ita;
                    //envia o comprador e os objetos de evento para a maquina de vendas
                    menuvenda(comprador1, show, cinema, fantoche, boate);
                    }
                }

                for(itd = idoso.begin(); itd!= idoso.end();itd++){
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
    
    delete [] IdDono;
    delete [] depend;
    delete [] idad;

    return 0;
}