//
// Created by pedro on 29/11/22.
//

#include "GerenciamentoDeArquivos.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

GerenciamentoDeArquivos::GerenciamentoDeArquivos() {};

void GerenciamentoDeArquivos::writeOnFile(std::string nome,std::string palavra)
{
    std::ofstream  arquivo(nome+".txt",std::ios::app);
    palavra = "\n" + palavra;
    arquivo << palavra;
    arquivo.close();
}
std::vector<std::string> GerenciamentoDeArquivos::readOnFile(std::string nome, std::string doadorColetor)
{
    std::vector<std::string>todosDados;
    std::string fileName;
    std::string auxDado;

    if (doadorColetor == "1") doadorColetor = "DOADOR";
    if (doadorColetor == "2") doadorColetor = "COLETOR";

    std::ifstream arquivo(doadorColetor+"-"+nome+".txt");
    while(arquivo.good()){
        getline(arquivo,auxDado);
        todosDados.push_back(auxDado);
    }

    return todosDados;
}
std::vector<std::string> GerenciamentoDeArquivos::readContas()
{
    std::vector<std::string> auxVector;
    std::string auxString;
    std::ifstream arquivo("contas.txt");
    while(arquivo.good()){
        getline(arquivo,auxString);
        auxVector.push_back(auxString);
    }
    return auxVector;
}

void GerenciamentoDeArquivos::rewriteContas(std::vector<std::string> contas)
{
    std::ofstream arquivo("contas.txt");
    for (long unsigned int i = 0; i < contas.size(); i++){
        arquivo <<"\n" + contas[i];
    }
    arquivo.close();
}