#include "Variavel.h"
#include <iostream>
#include <string>
using namespace std;

Variavel::Variavel()
{
    //ctor
}

string Variavel::getNome()
{
    return nome;
}

double Variavel::getValor()
{
    return valor;
}

void Variavel::setNome(string a)
{
    nome = a;
}

void Variavel::setValor(double b)
{
    valor = b;
}


