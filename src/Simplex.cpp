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

    if (classificar())
    {
        preparar(classificar());
        simplexSimples();
    }
    else
    {
        simplexBigM();
    }
}
bool Simplex::classificar()
{

    for (int i = 0; i < problema.getRestricoes().size(); i++)
    {
        if (problema.getRestricao(i).getSimbolo().getNome() == "=")
        {
            return 0;
        }
        else if (problema.getRestricao(i).getSimbolo().getNome() == "=>")
        {
            return 0;
        }
        else if (problema.getTipo() == "Minimizar")
        {
            return 0;
        }
    }
    return 1;
}

void Simplex::simplexSimples()
{

    //numero de restrições +Z + bigM
    int quantRestricoes = problema.getRestricoes().size();
    string colunaEsq[quantRestricoes+2];
    //numero de variaveis + numero de folgas + coluna resultado;

    string linhaTop[(problema.getFuncaoObjetivoPronto().getVariaveis().size()*2)+1];

    double colunaResult[quantRestricoes+2];
    int quantLinhaTabela = problema.getFuncaoObjetivoPronto().getVariaveis().size()*2;
    double tabela[quantLinhaTabela][quantRestricoes+2];

    for (int j = 0; j < quantRestricoes+2; j++)
    {
        if(j >= quantRestricoes){
            if(j == quantRestricoes){
                colunaEsq[j]="Z";
            }else if(j == quantRestricoes+1){
                colunaEsq[j]="BigM";
            }
        }else{
            colunaEsq[j] = problema.getRestricao(j).getFolga().getNome();
            //cout<<problema.getRestricao(j).getFolga().getNome()<<endl;
        }
       // cout<<colunaEsq[j]<<endl;
    }
}

void Simplex::simplexBigM()
{
}

void Simplex::preparar(bool i)
{
    if (i)
    {

        //Cria o nome das variaveis de folga no simplex simples
        for (int i = 0; i < problema.getRestricoes().size(); i++)
        {
                Folga folgas;
                string nomeFolga = "f";
                stringstream ss;
                ss << i+1;
                string str = nomeFolga;
                str += ss.str();
                folgas.setNome(str);
                folgas.setValor(0);

                //problema.getRestricao(i).setFolga(folgas);

                //string nome = problema.getRestricao(i).getFolga().getNome();
                cout<<problema.getRestricao(i).getSimbolo().getNome()<<endl;
                //cout<<restr.getFolga().getNome()<<endl;

        }
    }
}
