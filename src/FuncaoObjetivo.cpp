#include "FuncaoObjetivo.h"
#include "../include/Variavel.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

FuncaoObjetivo::FuncaoObjetivo()
{
    //ctor
}
vector <Variavel> FuncaoObjetivo::getVariaveis()
{
    return variaveis;
}

void FuncaoObjetivo::setVariaveis(Variavel a)
{
    variaveis.push_back(a);
}
Variavel FuncaoObjetivo::getVariavel(int i)
{
    return variaveis[i];
}


