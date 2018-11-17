#include "Simplex.h"
#include "../include/FuncaoObjetivo.h"
#include "../include/Simbolo.h"
#include "../include/Folga.h"
#include "../include/Restricao.h"
#include "../include/Variavel.h"
#include "../include/VariavelArtificial.h"
#include "../include/Problema.h"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <locale>
#include <vector>
#define M 99999
using namespace std;

Simplex::Simplex(Problema &p) : problema(p)
{

}

void Simplex::simplexSimples()
{

    //numero de restrições +Z + bigM
    int quantRestricoes = problema.getRestricoes().size();
    string colunaEsq[quantRestricoes+1];

    //numero de variaveis + numero de folgas + coluna resultado;
    string linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)+1];

    double colunaResult[quantRestricoes+1];
    int quantLinhaTabela = problema.getFuncaoObjetivoPronto().getVariaveis().size();
    double tabela[quantLinhaTabela][quantRestricoes*2];

    for (int j = 0; j < quantRestricoes+1; j++)
    {
        if(j >= quantRestricoes){
            if(j == quantRestricoes){
                colunaEsq[j]="Z";
            }else if(j == quantRestricoes+1){
                //colunaEsq[j]="BigM";
            }
        }else{
            colunaEsq[j] = problema.getRestricao(j)->getFolga().getNome();
            //cout<<problema.getRestricao(j)->getFolga().getNome()<<endl;
        }
        //cout<<colunaEsq[j]<<endl;
    }
    int controle=0;
    for(int k = 0; k < problema.getFuncaoObjetivoPronto().getVariaveis().size(); k++){
        linhaTop[k]= problema.getFuncaoObjetivoPronto().getVariavel(k).getNome();
        //cout<<linhaTop[k];
        controle++;
    }
    for(int l=0; l < problema.getFuncaoObjetivoPronto().getVariaveis().size(); l++){
       linhaTop[controle] = problema.getRestricao(l)->getFolga().getNome();
       //cout<<linhaTop[controle];

       controle++;
    }
    //linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)+1]="B";
    //cout<<"oi"<<endl;

    linhaTop[problema.getFuncaoObjetivoPronto().getVariaveis().size()*2]="B";
    for(int i=0; i< (problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)+1;i++){

        //cout<<linhaTop[i]<<endl;
    }

   for(int l = 0; l<quantLinhaTabela; l++){
        for(int c = 0; c<quantRestricoes*2; c++){
            while(c < problema.getRestricao(l)->getVariaveis().size()){
                if(problema.getRestricao(l)->getVariavel(c)!= NULL){
                   tabela[l][c] = problema.getRestricao(l)->getVariavel(c)->getValor();
                   cout<<tabela[l][c]<<".."<<l<<c<<endl;
                }
                break;
            }
            while(){

            }
        }
   }

}

void Simplex::simplexBigM()
{
}

