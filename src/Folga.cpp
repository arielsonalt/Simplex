#include "Folga.h"
#include <iostream>
#include <string>
using namespace std;

Folga::Folga()
{
    //ctor
}

string Folga::getNome()
{
    return nome;
}

double Folga::getValor()
{
    return valor;
}

void Folga::setNome(string nome)
{
    nome = nome;
}

void Folga::setValor(double valor)
{
    valor = valor;
}

