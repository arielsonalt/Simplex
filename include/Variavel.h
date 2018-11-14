#ifndef VARIAVEL_H
#define VARIAVEL_H
#include <iostream>
#include <string>
using namespace std;

class Variavel
{
    private:
        string nome;
        double valor;
    public:
        Variavel();
        string getNome();
        double getValor();
        void setNome(string);
        void setValor(double);
};

#endif // VARIAVEL_H
