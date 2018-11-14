#include "Simbolo.h"
#include <iostream>
#include <string>
using namespace std;

Simbolo::Simbolo()
{
    //ctor
}
string Simbolo::getNome()
{
    return nome;
}

void Simbolo::setNome(string a)
{
    nome = a;
}


