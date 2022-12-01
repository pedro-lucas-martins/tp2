//
// Created by pedro on 29/11/22.
//

#ifndef TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
#define TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
#include <fstream>
#include <string>
#include <vector>

class GerenciamentoDeArquivos
{
public:
    GerenciamentoDeArquivos();
    void writeOnFile(std::string nome, std::string palavra);
    std::vector<std::string> readOnFile(std::string nome, std::string doadorColetor);
    std::vector<std::string> readContas(std::string nomeArquivo);
};


#endif //TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
