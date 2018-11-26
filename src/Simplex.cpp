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
#define MODULO(x) ((x)>=0?(x):-(x))
using namespace std;

Simplex::Simplex(Problema &p) : problema(p)
{

}

void Simplex::simplexSimples()
{

    //numero de restri��es +Z + bigM
    int quantRestricoes = problema.getRestricoes().size();
    string colunaEsq[quantRestricoes+1];

    //numero de variaveis + numero de folgas + coluna resultado;
    string linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()+quantRestricoes)+1];

    double colunaResult[quantRestricoes+1];
    int quantLinhaTabela = quantRestricoes+1;
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

    linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()+ quantRestricoes)]="B";

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





    for(unsigned int i = 0; i<quantLinhaTabela-1; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            tabela[i][j] = 0;
            //cout<<tabela[i][j]<<" ";
        }
        //cout<<""<<endl;
    }
    //cout<<sizeof(linhaTop)/sizeof(int)<<endl;

    for(unsigned int i = 0; i<quantLinhaTabela; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            int encontrou =0;
            if(j<problema.getRestricoes().size())
            {

                for(int k=0; k < problema.getRestricao(i)->getVariaveis().size(); k++)
                {
                    if(problema.getRestricao(i)->getVariavel(k)->getNome() ==  linhaTop[j])
                    {
                        //cout<<problema.getRestricao(i)->getVariavel(k)->getValor();

                        tabela[i][j] = problema.getRestricao(i)->getVariavel(k)->getValor();
                        encontrou=1;
                    }

                }
                if(encontrou == 0)
                {
                    tabela[i][j] = 0;
                }
            }
            if( i != quantLinhaTabela-1)
            {

                if(problema.getRestricao(i)->getFolga().getNome() == linhaTop[j])
                {
                    encontrou = 1;
                    tabela[i][j] = problema.getRestricao(i)->getFolga().getValor();

                    //cout<<tabela[i][j]<<endl;

                }
                if(encontrou == 0)
                {
                    tabela[i][j] = 0;

                }
            }
        }
        if(i == quantLinhaTabela-1)
        {

            for(int v=0 ; v<colunaTabela; v++)
            {

                int encontrou =0;
                for(int k=0; k < problema.getFuncaoObjetivoPronto().getVariaveis().size(); k++)
                {

                    if(problema.getFuncaoObjetivoPronto().getVariavel(k).getNome() ==  linhaTop[v])
                    {
                        //cout<<problema.getFuncaoObjetivoPronto().getVariavel(k).getValor();

                        tabela[i][v] = problema.getFuncaoObjetivoPronto().getVariavel(k).getValor();
                        encontrou=1;
                    }

                }
                if(encontrou == 0)
                {
                    tabela[i][v] = 0;
                }
            }
        }
    }

    for(int t=0; t<quantRestricoes+1; t++)
    {
        if(t<quantRestricoes)
        {
            colunaResult[t] = problema.getRestricao(t)->getNumeroLimitante();

        }
        else
        {
            colunaResult[t]=0;

        }
        cout<<colunaResult[t]<<endl;
    }
    for(int s=0; s<colunaTabela; s++)
    {

        if(tabela[quantLinhaTabela-1][s] != 0)
        {
            tabela[quantLinhaTabela-1][s]= tabela[quantLinhaTabela-1][s] * -1;

        }

    }

    for(unsigned int i = 0; i<quantLinhaTabela; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            cout<<tabela[i][j]<<" ";
        }
        cout<<""<<endl;
    }


    //*********************************************************************************************
    //*********************************************************************************************
    //Intera��es
    cout<<"oi ***********"<<endl;
    int sair,cont=0;
        int colunaPivo,menorElementoLinha=0;
        double resultadoDivisao;
for(int q=0;q<4;q++){
        cont=0;
        // achar coluna pivo

        for(int y =0; y<colunaTabela; y++)
        {
            if(MODULO(tabela[quantLinhaTabela-1][y]) < 0){
                if(MODULO(tabela[quantLinhaTabela-1][y])>= menorElementoLinha)
                {
                    menorElementoLinha = MODULO(tabela[quantLinhaTabela-1][y]);
                    colunaPivo = y;
                    //cout<<colunaPivo;
                }
            }else{
                if(tabela[quantLinhaTabela-1][y] <= menorElementoLinha)
                {
                    menorElementoLinha = tabela[quantLinhaTabela-1][y];
                    colunaPivo = y;
                    //cout<<colunaPivo;
                }
            }

        }
       cout<<colunaPivo<<"colunaPivo"<<endl;

        //achar linha Pivo
        int linhaPivo;
        for(int y =0; y<quantLinhaTabela-1; y++)
        {
            if(y==0)
            {
                resultadoDivisao = colunaResult[y]/tabela[y][colunaPivo];

                linhaPivo = y;
                cout<<resultadoDivisao<<"divis�o"<<endl;
            }

            if((colunaResult[y]/tabela[y][colunaPivo]) < resultadoDivisao )
            {
                resultadoDivisao = colunaResult[y]/tabela[y][colunaPivo];
                cout<<resultadoDivisao<<"divis�o"<<endl;
                linhaPivo = y;
            }
        }

        cout<<linhaPivo<<endl;
        colunaEsq[linhaPivo] = linhaTop[colunaPivo];
        double divisor = tabela[linhaPivo][colunaPivo];
        for(int j=0; j < colunaTabela; j++)
        {
            tabela[linhaPivo][j] = tabela[linhaPivo][j]/divisor;

        }
         colunaResult[linhaPivo] = colunaResult[linhaPivo]/divisor;
        //Eliminar a nova vari�vel b�sica das outras equa��es

        for(unsigned int i = 0; i<quantLinhaTabela; i++)
        {

            if(i != linhaPivo)
            {
                if(tabela[i][colunaPivo] != 0)
                {
                    double multiplicador = tabela[i][colunaPivo];
                    colunaResult[i] = colunaResult[i] - (multiplicador* colunaResult[linhaPivo]);
                    for(int j=0; j<colunaTabela; j++)
                    {
                        tabela[i][j] = tabela[i][j] - (multiplicador* tabela[linhaPivo][j]);

                    }

                }
            }
        }

        // Verifica��es;
        for(int d=0; d<colunaTabela ; d++)
        {
            if(tabela[quantLinhaTabela][d] == 0)
            {
                cont++;
            }

        }
        if(cont == colunaTabela)
        {
            sair = 1;
        }
}

    for(unsigned int i = 0; i<quantLinhaTabela; i++)
    {
        for(unsigned int j = 0; j<colunaTabela; j++)
        {
            cout<<tabela[i][j]<<" ";
        }
        cout<<""<<endl;
    }

    for(int s=0; s<quantLinhaTabela; s++)
    {
        cout<<colunaEsq[s]<<" = "<<colunaResult[s]<<endl;
    }

}



void Simplex::simplexBigM()
{
}

