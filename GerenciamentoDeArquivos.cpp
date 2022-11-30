//
// Created by pedro on 29/11/22.
//

#include "GerenciamentoDeArquivos.h"
#include <fstream>
#include <vector>
#include <string>

GerenciamentoDeArquivos::GerenciamentoDeArquivos() {};

void GerenciamentoDeArquivos::writeOnFile(std::string nome,std::string palavra)
{
    std::ofstream  arquivo(nome+".txt",std::ios::app);
    palavra = palavra+"\n";
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