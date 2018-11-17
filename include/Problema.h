#ifndef PROBLEMA_H
#define PROBLEMA_H
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

class Problema
{
    private:
        FuncaoObjetivo funcaoObjetivoPronta;
        vector <Restricao> restricoes;
        string tipo;
    public:
        Problema();
        vector <Restricao> getRestricoes();
        Restricao* getRestricao(int);
        FuncaoObjetivo getFuncaoObjetivoPronto();
        void setRestricoes(Restricao);
        void setFuncaoObjetivoPronto(FuncaoObjetivo);
        void setTipo(string);
        string getTipo();

};

#endif // PROBLEMA_H
