#include "Problema.h"
#include "../include/FuncaoObjetivo.h"
#include "../include/Simbolo.h"
#include "../include/Folga.h"
#include "../include/Restricao.h"
#include "../include/Variavel.h"
#include "../include/VariavelArtificial.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

Problema::Problema()
{
    //ctor
}

vector<Restricao> Problema::getRestricoes()
{
    return restricoes;
}

FuncaoObjetivo Problema::getFuncaoObjetivoPronto()
{
    return funcaoObjetivoPronta;
}

void Problema::setRestricoes(Restricao a)
{
    restricoes.push_back(a);
}

void Problema::setFuncaoObjetivoPronto(FuncaoObjetivo funcao)
{
    funcaoObjetivoPronta = funcao;
}
void Problema::setTipo(string a)
{
    tipo = a;
}

string Problema::getTipo()
{
    return tipo;
}
Restricao *Problema::getRestricao(int i)
{

    return &restricoes[i];

}
