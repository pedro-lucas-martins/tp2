//
// Created by pedro on 29/11/22.
//

#ifndef TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
#define TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
#include <fstream>
#include <string>

class GerenciamentoDeArquivos
{
public:
    GerenciamentoDeArquivos();
    void writeOnFile(std::string nome, std::string palavra);
    void deleteOnFile();
    void readOnFile();
};


#endif //TP_2_ARQUIVO_GERENCIAMENTODEARQUIVOS_H
