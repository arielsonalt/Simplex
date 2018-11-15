#include "Folga.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
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

void Folga::setNome(string a)
{
    nome = a;

}

void Folga::setValor(double b)
{
    valor = b;
}

