#include "Instancia.h"
#include "../include/FuncaoObjetivo.h"
#include "../include/Simbolo.h"
#include "../include/Folga.h"
#include "../include/Restricao.h"
#include "../include/Variavel.h"
#include "../include/VariavelArtificial.h"
#include "../include/Problema.h"
#include "../include/Simplex.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <locale>
#include <vector>
using namespace std;

Instancia::Instancia()
{

}

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

void Instancia::ler()
{

    vector <string> lista;
    string linha;

    ifstream arquivo;
    arquivo.open("Modelagem.txt");

    while(arquivo.good())
    {
        getline(arquivo, linha);
        lista.push_back(linha);
    }

    //Problema problema;

    FuncaoObjetivo funcaoObjetivo;


    string tipo;
    tipo = lista[1];
    problema.setTipo(tipo);
    string funcao;
    funcao = lista[3];
    string variavelNome;
    string stringValorVariavel = "";


    for(int i=0;i<funcao.size();i++){
        if(funcao[i]>='a' && funcao[i]<='z'){
            variavelNome = funcao[i];
            if(funcao[i-1] == '-'){
                stringValorVariavel += "-1";
            }else if(funcao[i-1] == '+' || funcao[i-1] == -1){
                stringValorVariavel += "1";
            }
            if(funcao[i+1] == ' ' || funcao[i+1] == '\0'){
                criarFuncaoObjetivo(variavelNome,stringValorVariavel,&funcaoObjetivo);


                stringValorVariavel ="";
                variavelNome = "";


            }

        }else if(funcao[i]>='0' && funcao[i] <='9'){
            if(funcao[i-1] == '-'){
                 stringValorVariavel += "-";
            }
            stringValorVariavel += funcao[i];
        }
    }


        variavelNome = "";
        stringValorVariavel = "";
        string auxiliar = "";

        for(int k=7;k<lista.size();k++){
                Restricao restricao;
                Simbolo simbolo;
            funcao = lista[k];
            for(int i=0;i<funcao.size();i++){
                if(funcao[i]>='a' && funcao[i]<='z'){
                    variavelNome = funcao[i];
                    if(funcao[i-1] == '-'){
                        stringValorVariavel += "-1";
                    }else
                    if(funcao[i-1] == '+' || funcao[i-1] == -1){
                        stringValorVariavel += "1";
                    }
                    if(funcao[i+1] == ' ' || funcao[i+1] == '\0'){
                        //addVariavelEValor(variavel,stringValorVariavel,funcaoObjetivo);

                        //cout<<"-"<<endl;
                        Variavel variavel;
                        variavel.setNome(variavelNome);
                        double valorVariavel = atof(stringValorVariavel.c_str());
                        variavel.setValor(valorVariavel);
                        restricao.setVariaveis(variavel);
                        //cout<<variavel.getNome()<<endl;
                       // cout<<variavel.getValor()<<endl;
                        stringValorVariavel = "";
                        variavelNome ="";
                    }
                }else
                if(funcao[i]>='0' && funcao[i] <='9'){
                    if(funcao[i-2] >='<' && funcao[i-2] <='>' || funcao[i-3] >='<' && funcao[i-3] <='>'){
                        if(funcao[i-3] >='<' && funcao[i-3] <='>'){
                            for(int j=i-1; j<funcao.size();j++){
                            auxiliar += funcao[j];
                            i++;
                            }
                            restricao.setNumeroLimitante(atof(auxiliar.c_str()));
                            //cout<<"limite"<<restricao.getNumeroLimitante()<<endl;
                            auxiliar = "";
                        }else{
                        for(int j=i; j<funcao.size();j++){
                            auxiliar += funcao[j];
                            i++;
                        }
                        restricao.setNumeroLimitante(atof(auxiliar.c_str()));
                        //cout<<"limite"<<restricao.getNumeroLimitante()<<endl;
                        auxiliar = "";
                    }
                    }else{
                        if(funcao[i-1] == '-'){
                             stringValorVariavel += "-";
                        }
                        stringValorVariavel += funcao[i];
                    }
                }else
                if(funcao[i] >='<' && funcao[i] <='>'){
                    if(funcao[i+1] >='<' && funcao[i+1] <='>'){
                        auxiliar += funcao[i];
                    }else{
                        auxiliar += funcao[i];
                        simbolo.setNome(auxiliar);
                        restricao.setSimbolo(simbolo);

                        //cout<<" "<<restricao.getSimbolo().getNome();
                        auxiliar ="";
                    }
                }
            }
            problema.setRestricoes(restricao);
        }

        problema.setFuncaoObjetivoPronto(funcaoObjetivo);


    arquivo.close();



    if (classificar(problema))
    {
        preparar(classificar(problema));
        Simplex simplex(problema);
        simplex.simplexSimples();
    }
    else
    {
        Simplex simplex(problema);
        simplex.simplexBigM();
    }






}
void Instancia::criarFuncaoObjetivo(string nomeString, string valorString,FuncaoObjetivo *funcaoObjetivo)
{
    Variavel variavel;
    variavel.setNome(nomeString);

    double valorDouble;
    valorDouble = atof(valorString.c_str());
    FuncaoObjetivo funcAux;

    variavel.setValor(valorDouble);
    funcAux = *funcaoObjetivo;
    funcAux.setVariaveis(variavel);


   *funcaoObjetivo = funcAux;
}


bool Instancia::classificar(Problema &problema)
{
    for (int i = 0; i < problema.getRestricoes().size(); i++)
    {
        if (problema.getTipo() == "Minimizar" || problema.getTipo() == "minimizar" )
        {
            cout<<"Resultado = 0"<<endl;
            return 0;
        }
    }
    return 1;
}

void Instancia::preparar(bool i)
{
    if (i)
    {

        //Cria o nome das variaveis de folga no simplex simples
        int num = problema.getRestricoes().size();
        for (int i = 0; i < num; i++)
        {
                Folga folga;
                string nomeFolga = "f";
                stringstream ss;
                ss << i+1;
                string str = nomeFolga;
                str += ss.str();
                folga.setNome(str);
                int num = 1;
                folga.setValor(num);

                problema.getRestricao(i)->setFolga(folga);

                //string nome = problema.getRestricao(i).getFolga().getNome();
                //cout<<problema.getRestricao(i)->getFolga().getNome()<<"certo"<<endl;
                //cout<<problema.getRestricao(i)->getFolga().getValor()<<"certo"<<endl;
                //cout<<restr.getFolga().getNome()<<endl;

        }
    }
}

