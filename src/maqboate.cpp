#include "maqboate.h"
#include <iostream>
#include <string>
#include "funcoes.h"

using namespace std;

void MaquinaBoate::MaquinaDeVendas(vector<Boate> boate){
    vector<Boate>::iterator it;

    cout<<"VENDA DE INGRESSO: BOATE"<<endl<<endl;
    cout<<"Favor escolher uma das opções abaixo:"<<endl<<endl;

    for(it = boate.begin(); it!=boate.end(); it++){
        cout<<it->get_id()<<" "<<it->get_nome()<<endl<<"Duração: Inicio"<<it->get_horaInicio()<<" - Fim: "<<it->get_horaFim()<<endl<<endl;
    }

    int n;
    cout<<"Opcao: ";
    cin>>n;

    for(it = boate.begin(); it!=boate.end(); it++){
        if(n == it->get_id()){
            //verifica se tem, ingresso disponivel
                //if tiver ingresso
        }
    }


}