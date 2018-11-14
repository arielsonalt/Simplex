#ifndef RESTRICAO_H
#define RESTRICAO_H
#include "../include/Variavel.h"
#include "../include/Folga.h"
#include "../include/VariavelArtificial.h"
#include "../include/Simbolo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restricao
{
    private:
        vector <Variavel> variaveis;
        Folga folga;
        vector <VariavelArtificial> variaveisArtificiais;
        Simbolo simbolo;
        double numeroLimitante;
    public:
        Restricao();
        vector <Variavel> getVariaveis();
        Folga getFolga();
        vector <VariavelArtificial> getVariaveisArtificiais();
        Simbolo getSimbolo();
        double getNumeroLimitante();
        void setVariaveis(Variavel);
        void setFolga(Folga);
        void setVariaveisArtificiais(VariavelArtificial);
        void setSimbolo(Simbolo);
        void setNumeroLimitante(double);


};

#endif // RESTRICAO_H
