//
// Created by pedro on 29/11/22.
//

#include "GerenciamentoDeArquivos.h"
#include <fstream>

GerenciamentoDeArquivos::GerenciamentoDeArquivos() {};

void GerenciamentoDeArquivos::writeOnFile(std::string nome,std::string palavra)
{
    std::ofstream  arquivo(nome+".txt",std::ios::app);
    palavra = palavra+"\n";
    arquivo << palavra;
    arquivo.close();
}