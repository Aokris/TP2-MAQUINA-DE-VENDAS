#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>

#include "funcoes.h"
#include "crianca.h"
#include "idoso.h"
#include "totem.h"


int le_usuarios(int &j, int &qcria, int &qadult, int &qidos, std::string file_usuarios, int *depend, int *idad, vector<Crianca> &crianca, vector<Adulto> &adulto, vector<Idoso> &idoso){
    // Definindo auxiliares
    int id = 0;
    float saldo = 0.0;
    string nome, categoria;

    // Abrindo arquivo
    std::ifstream file_a(file_usuarios);

    if(file_a.is_open()){
        // Separar em uma função
        std::string linha, linha_aux;
        std::vector<string> tratamento;
        
        while(getline(file_a, linha)){
            stringstream X(linha);
            while(getline(X, linha_aux, ',')){
                tratamento.push_back(linha_aux);
            }

            int i = 0;
            id = stoi(tratamento[i]); i++;
            categoria = (tratamento[i]); i++;
            nome = (tratamento[i]); i++;
            idad[j] = stoi(tratamento[i]); i++;
            saldo = stof(tratamento[i]); i++;

            if(categoria == "crianca"){
                depend[qcria] = stoi(tratamento[i]); i++;

                Crianca c(id, categoria, nome, idad[j], saldo, depend[qcria]);
                crianca.push_back(c);
                qcria++;;

            } else if(categoria == "adulto"){
                
                Adulto a(id, categoria, nome, idad[j], saldo);
                adulto.push_back(a);
                qadult++;

            } else if(categoria == "idoso"){
                Idoso ido(id, categoria, nome, idad[j], saldo);
                idoso.push_back(ido);
                qidos++;

            } else {
                cout << "Houve um erro na leitura do arquivo, garanta que as classes de usuários foram identificadas corretamente!" << endl;
                return EXIT_FAILURE;
            }


            j++;

            tratamento.clear();
        }

        
    } else {
        cout << "Erro, nao deu pra abrir!" << endl;
        return EXIT_FAILURE;
    }

}

int le_eventos(int &contagem_donos, int &qBoate, int &qShow, int &qCine, int &qFanto, int *IdDono, int &maiorQuota, int &idMaiorQuota, std::string file_eventos, vector<Cinema> &cinema, vector<Show> &show, vector<Boate> &boate, vector<TeatroFantoche> &fantoche, map<double, int> &precos){
    // Definindo auxiliares
    int NumTipos = 0;
    int IdEven = 0;
    std::string categoriaEven;
    std::string subcategEven;
    std::string nomeEven;
    int quotaIdoso = 0;
    int duracao = 0;
    int horaIni = 0;
    int horaFim = 0;
    int abertura = 0;

    // Abrindo arquivo
    std::ifstream file_b(file_eventos);

    if(file_b.is_open()){
        // Separar em uma função
        std::string linha, linha_aux;
        std::vector<string> tratamento2;
        
        
        while(getline(file_b, linha)){
            stringstream Y(linha);
            while(getline(Y, linha_aux, ',')){
                tratamento2.push_back(linha_aux);
            }
            
            int i = 0;
            IdEven = stoi(tratamento2[i]); i++;

            categoriaEven = tratamento2[i]; i++;

            // Se evento for do tipo cinema, ele não tem subcategoria
            if(categoriaEven != "cinema"){
                subcategEven = tratamento2[i]; i++;
            }

            nomeEven = tratamento2[i]; i++;

            IdDono[contagem_donos] = stoi(tratamento2[i]); i++;

            NumTipos = stoi(tratamento2[i]); i++;

            int *ingEven = new int[NumTipos];
            int *ValorEven = new int[NumTipos];

            for(int aux_tipos = 0; aux_tipos < NumTipos; aux_tipos++){

                ingEven[aux_tipos] = stoi(tratamento2[i]); i++;

                ValorEven[aux_tipos] = stof(tratamento2[i]); i++;

                precos[ValorEven[aux_tipos]] += ingEven[aux_tipos];
            }

            int *horarios = new int[999];
            // Se o evento não for do tipo Adulto, a leitura dos horários é realizada
            if(categoriaEven == "infantil"){
                for(int aux_h = 0; aux_h < tratamento2.size() - i; aux_h++){
                    horarios[aux_h] = stoi(tratamento2[i]); i++;
                }

                TeatroFantoche fan(horarios, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                fantoche.push_back(fan);
                qFanto++;

            } else if(categoriaEven == "cinema"){
                for(int aux_h = 0; aux_h < tratamento2.size() - (i+1); aux_h++){
                    horarios[aux_h] = stoi(tratamento2[i]); i++;
                }
                
                duracao = stoi(tratamento2[i]); i++;

                Cinema cine(IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven, horarios, duracao);
                cinema.push_back(cine);
                qCine++;

            } else if(categoriaEven == "adulto"){
                quotaIdoso = stoi(tratamento2[i]); i++;

                if(quotaIdoso > maiorQuota){
                    maiorQuota = quotaIdoso;
                    idMaiorQuota = IdEven;
                }

                if(subcategEven == "boate"){
                    horaIni = stoi(tratamento2[i]); i++;
                    horaFim = stoi(tratamento2[i]); i++;

                    Boate boa(quotaIdoso, horaIni, horaFim, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                    boate.push_back(boa);
                    qBoate++;

                } else if(subcategEven == "show"){
                    abertura = stoi(tratamento2[i]); i++;
                    
                    string *artistas = new string[999];
                    int aux_arts = 0;
                    for(; i <= tratamento2.size(); i++){
                        artistas[aux_arts] = tratamento2[i];
                        aux_arts++;
                    }

                    Show sho(quotaIdoso, abertura, artistas, IdEven, nomeEven, IdDono[contagem_donos], ingEven, ValorEven);
                    show.push_back(sho);
                    qShow++;

                    delete [] artistas;
                }


            } else {
                cout << "Houve um erro na leitura do arquivo, garanta que as classes de usuários foram identificadas corretamente!" << endl;
                return EXIT_FAILURE;

            }

            delete [] horarios;
            delete [] ingEven;
            delete [] ValorEven;

            contagem_donos++;

            tratamento2.clear();
        }

    } else {
        cout << "Erro, nao deu pra abrir!" << endl;
        return EXIT_FAILURE;
    }

}


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
            /* ---------- Váriaveis Auxiliares - USUÁRIOS ---------- */
            int *depend = new int[999];                //vetor de id dependentes
            depend[0] = -1;                       // usado para caso extremo de nenhum dependente
            int *idad = new int[999];

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
            int *IdDono = new int[999];
            int maiorQuota = 0, idMaiorQuota = 0;
            // Contadores
            int qBoate = 0, qShow = 0, qCine = 0, qFanto = 0;

        /* ---------- Tratando Entrada - EVENTOS ---------- */
            string file_eventos;
            std::cout << "Digite o nome do arquivo de EVENTOS que voce quer abrir: ";
            std::cin >> file_eventos;

            int contagem_donos = 0;
            le_eventos(contagem_donos, qBoate, qShow, qCine, qFanto, IdDono, maiorQuota, idMaiorQuota, file_eventos, cinema, show, boate, fantoche, precos);

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