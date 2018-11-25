#ifndef SIMPLEX_H
#define SIMPLEX_H
#include "FuncaoObjetivo.h"
#include "Simbolo.h"
#include "Folga.h"
#include "Restricao.h"
#include "Variavel.h"
#include "VariavelArtificial.h"
#include "../include/Problema.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <locale>
#include <vector>
using namespace std;

class Simplex
{
    public:
        Problema & problema;
        Simplex(Problema & p);
        void fim(double**,int);
        void simplexSimples();
        void simplexBigM();
        //

};

#endif // SIMPLEX_H
