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
    int colunaTabela = quantRestricoes + problema.getFuncaoObjetivoPronto().getVariaveis().size();
    double tabela[quantLinhaTabela][colunaTabela];

    for (int j = 0; j < quantRestricoes+1; j++)
    {
        if(j >= quantRestricoes)
        {
            if(j == quantRestricoes)
            {
                colunaEsq[j]="Z";
            }
        }
        else
        {
            colunaEsq[j] = problema.getRestricao(j)->getFolga().getNome();
            //cout<<problema.getRestricao(j)->getFolga().getNome()<<endl;
        }
        //cout<<colunaEsq[j]<<endl;
    }

    linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)]="B";

    int l=0;
    for(int k=0; k < problema.getFuncaoObjetivoPronto().getVariaveis().size(); k++)
    {
        linhaTop[k] = problema.getFuncaoObjetivoPronto().getVariavel(k).getNome();
        l++;
    }


    for(int m=0; m< problema.getRestricoes().size(); m++)
    {
        linhaTop[l] = problema.getRestricao(m)->getFolga().getNome();
        l++;
    }

    for(int k=0; k < sizeof(linhaTop)/sizeof(int) ; k++)
    {
        //cout<<linhaTop[k]<<endl;
    }





    for(unsigned int i = 0; i<quantLinhaTabela; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            tabela[i][j] = 0;
            //cout<<tabela[i][j]<<" ";
        }
        //cout<<""<<endl;
    }
    cout<<sizeof(linhaTop)/sizeof(int)<<endl;

    for(unsigned int i = 0; i<quantLinhaTabela-1; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            if(j<problema.getRestricoes().size())
            {
                for(int k=0; k < problema.getRestricao(i)->getVariaveis().size(); k++)
                {
                    if(problema.getRestricao(i)->getVariavel(k)->getNome() ==  linhaTop[j])
                    {

                        tabela[i][j] = problema.getRestricao(i)->getVariavel(k)->getValor();
                    }
                    else
                    {

                        tabela[i][j] = 0;
                    }

                }

            }
            else
            {
                if(problema.getRestricao(i)->getFolga().getNome() == linhaTop[j])
                {

                    tabela[i][j] = problema.getRestricao(i)->getFolga().getValor();

                }
                else
                {
                    tabela[i][j] = 0;

                }
            }
        }
cout<<"oi"<<endl;
    }

    for(unsigned int i = 0; i<quantLinhaTabela; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            cout<<tabela[i][j]<<" ";
        }
        cout<<""<<endl;
    }

}

void Simplex::simplexBigM()
{
}

