//
// Created by pedro on 29/11/22.
//

#ifndef TP_2_ARQUIVO_RESIDUO_H
#define TP_2_ARQUIVO_RESIDUO_H
#include <string>
#include "Conta.h"

class Residuo {
private:
public:
    Residuo();
    static void registrarNovoLiquido(GerenciamentoDeArquivos* auxConta, std::string nome);
    static void registrarNovoSolido(GerenciamentoDeArquivos* auxConta, std::string nome);
};


#endif //TP_2_ARQUIVO_RESIDUO_H
