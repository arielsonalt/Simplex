#ifndef FUNCAOOBJETIVO_H
#define FUNCAOOBJETIVO_H
#include "../include/Variavel.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FuncaoObjetivo
{
    private:
        vector <Variavel> variaveis;
    public:
        FuncaoObjetivo();
        vector <Variavel> getVariaveis();
        void setVariaveis(Variavel);
};


#endif // FUNCAOOBJETIVO_H
