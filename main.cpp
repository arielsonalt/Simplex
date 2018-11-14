#include "../include/Instancia.h"
#include <locale>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    Instancia inst;
    inst.ler();
}
