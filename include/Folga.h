#ifndef FOLGA_H
#define FOLGA_H
#include <iostream>
#include <string>
using namespace std;

class Folga
{
    private:
        string nome;
        double valor;
    public:
        Folga();
        string getNome();
        double getValor();
        void setNome(string);
        void setValor(double);
};

#endif // FOLGA_H
