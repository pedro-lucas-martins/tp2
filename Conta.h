//
// Created by pedro on 29/11/22.
//

#ifndef TP_2_ARQUIVO_CONTA_H
#define TP_2_ARQUIVO_CONTA_H
#include "GerenciamentoDeArquivos.h"
#include "Residuo.h"


class Conta
{
private:
    GerenciamentoDeArquivos* auxArquivo = new GerenciamentoDeArquivos;
    Conta* novaConta;
public:
    Conta();
    void registrarConta();
    void perguntaResiduo(GerenciamentoDeArquivos* auxConta,std::string doaRecolhe, std::string nome);
};


#endif //TP_2_ARQUIVO_CONTA_H
