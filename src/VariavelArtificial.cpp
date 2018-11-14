#include "VariavelArtificial.h"
#include <iostream>
#include <string>
using namespace std;

VariavelArtificial::VariavelArtificial()
{
    //ctor
}


string VariavelArtificial::getNome()
{
    return nome;
}

double VariavelArtificial::getValor()
{
    return valor;
}

void VariavelArtificial::setNome(string a)
{
    nome = a;
}

void VariavelArtificial::setValor(double b)
{
    valor = b;
}

