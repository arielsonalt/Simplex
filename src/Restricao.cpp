#include "Restricao.h"
#include <iostream>
#include "../include/Variavel.h"
#include "../include/Folga.h"
#include <string>
#include <vector>
using namespace std;

Restricao::Restricao()
{
    //ctor
}
vector <Variavel> Restricao::getVariaveis()
{
    return variaveis;
}

Folga Restricao::getFolga()
{
    return folga;
}

vector <VariavelArtificial> Restricao::getVariaveisArtificiais()
{
    return variaveisArtificiais;
}

Simbolo Restricao::getSimbolo()
{
    return simbolo;
}

double Restricao::getNumeroLimitante()
{
    return numeroLimitante;
}

void Restricao::setVariaveis(Variavel a)
{
    variaveis.push_back(a);
}

void Restricao::setFolga(Folga &u)
{
    folga = u;
}

void Restricao::setVariaveisArtificiais(VariavelArtificial a)
{
    variaveisArtificiais.push_back(a);
}

void Restricao::setSimbolo(Simbolo a)
{
    simbolo = a;
}

void Restricao::setNumeroLimitante(double a)
{
    numeroLimitante = a;
}
Variavel* Restricao::getVariavel(int i)
{
    return &variaveis[i];
}

