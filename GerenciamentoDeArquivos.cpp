//
// Created by pedro on 29/11/22.
//

#include "GerenciamentoDeArquivos.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <istream>

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

void GerenciamentoDeArquivos::imprimeDadosColeta(std::string nomeArquivo)
{
    std::string auxString;
    std::ifstream arquivo(nomeArquivo);
    while(arquivo.good()){
        getline(arquivo, auxString);
        std::cout << auxString << "\n";
    }
    arquivo.close();
}

void GerenciamentoDeArquivos::mostraColetores()
{
    int contador = 1;
    int i = 0;
    char palavra[100];

    std::vector<std::string> todosDoadores;
    std::string auxString;
    std::ifstream arquivo("contas.txt");
    while(arquivo.good()){
        getline(arquivo, auxString);
        if (auxString[7] == '-'){
            todosDoadores.push_back(auxString);
        }
    }
    std::cout << "Locais disponiveis para recolhimento: \n";
    try{
        for (long unsigned int i = 0; i < todosDoadores.size(); i++){
            this->imprimeDadosColeta(todosDoadores[i]);
            std::cout << "\n";
            contador++;
        }
        if (todosDoadores.size() == 0){
            throw std::out_of_range("Nao existem contas para coletar.");
        }
    }
    catch (std::out_of_range &e) {std::cout << e.what();}
}
