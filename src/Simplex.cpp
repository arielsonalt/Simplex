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

Simplex::Simplex(Problema & p) :
    problema(p)
{
    if(classificar()){
        preparar(classificar());
        simplexSimples();
    }else{
        simplexBigM();
    }
}
bool Simplex::classificar()
{

    for(int i =0;i < problema.getRestricoes().size();i++){
        if(problema.getRestricao(i).getSimbolo().getNome() == "="){
                return 0;
        }else if(problema.getRestricao(i).getSimbolo().getNome() == "=>"){
                return 0;
        }else if(problema.getTipo() == "Minimizar"){
                return 0;
        }
    }
    return 1;
}

void Simplex::simplexSimples()
{


    int tamanhoLinhas = problema.getRestricoes().size()+1;
    int tamanhoColunas = problema.getFuncaoObjetivoPronto().getVariaveis().size()
    + problema.getRestricoes().size()+1;

    double tabela[tamanhoLinhas][tamanhoColunas];

    string nomeLinha[tamanhoLinhas];
    string nomeColuna[tamanhoColunas];
    for(int j = 0; j < nomeLinha.size(); j++){

    }
}

void Simplex::simplexBigM()
{

}

void Simplex::preparar(int i)
{
    if(i){
        for(int i=0; i<problema.getRestricoes().size(); i++){
            string nomeFolga = "f";
            stringstream ss;
            ss << i;
            string str = ss.str();
            problema.getRestricao(i).getFolga().setNome(str);
            problema.getRestricao(i).getFolga().setValor(1);
        }
    }else{

    }
}






