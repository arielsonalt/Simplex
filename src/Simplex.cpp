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
    int quantLinhaTabela = problema.getFuncaoObjetivoPronto().getVariaveis().size()+1;
    double tabela[quantLinhaTabela][quantRestricoes*2];

    for (int j = 0; j < quantRestricoes+1; j++)
        {
            if(j >= quantRestricoes){
                if(j == quantRestricoes){
                    colunaEsq[j]="Z";
                }
            }else{
                colunaEsq[j] = problema.getRestricao(j)->getFolga().getNome();
                //cout<<problema.getRestricao(j)->getFolga().getNome()<<endl;
            }
            //cout<<colunaEsq[j]<<endl;
        }

    linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)]="B";
    for(int k=0; k< sizeof(linhaTop)/sizeof(int);k++){

    }

    for(unsigned int i = 0; i<quantLinhaTabela; i++){
        for(unsigned int j = 0; j<quantRestricoes*2;j++){
            tabela[i][j] = 0;
            cout<<tabela[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    cout<<sizeof(linhaTop)/sizeof(int)<<endl;

    for(unsigned int i = 0; i<quantLinhaTabela; i++){
        for(unsigned int j = 0; j<quantRestricoes*2;j++){

        }

    }
    for(unsigned int i = 0; i<quantLinhaTabela; i++){
        for(unsigned int j = 0; j<quantRestricoes*2;j++){
            cout<<tabela[i][j]<<" ";
        }
        cout<<""<<endl;
    }

}

void Simplex::simplexBigM()
{
}

