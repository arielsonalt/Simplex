#ifndef VARIAVELARTIFICIAL_H
#define VARIAVELARTIFICIAL_H
#include <iostream>
#include <string>
using namespace std;

class VariavelArtificial
{
    private:
        string nome;
        double valor;
    public:
        VariavelArtificial();
        string getNome();
        double getValor();
        void setNome(string);
        void setValor(double);
};

#endif // VARIAVELARTIFICIAL_H
