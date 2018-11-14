#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <iostream>
#include <string>
using namespace std;

class Simbolo
{
    private:
        string nome;
    public:
        Simbolo();
        string getNome();
        void setNome(string);
};

#endif // SIMBOLO_H
