#ifndef INSTANCIA_H
#define INSTANCIA_H
#include "../include/FuncaoObjetivo.h"
#include "../include/Simbolo.h"
#include "../include/Folga.h"
#include "../include/Restricao.h"
#include "../include/Variavel.h"
#include "../include/VariavelArtificial.h"
#include "../include/Problema.h"
#include "../include/Simplex.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Instancia
{
    private:

    public:
        Instancia();
        void ler();
        bool classificar(Problema&);
        void preparar(bool);
        void criarFuncaoObjetivo(string,string,FuncaoObjetivo*);
        Problema problema;
};

#endif // INSTANCIA_H
