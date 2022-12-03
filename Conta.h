//
// Created by pedro on 29/11/22.
//

#ifndef TP_2_ARQUIVO_CONTA_H
#define TP_2_ARQUIVO_CONTA_H
#include "GerenciamentoDeArquivos.h"
#include "Residuo.h"
#include <string>
#include <vector>


class Conta
{
private:
    GerenciamentoDeArquivos* auxArquivo;
    Conta* novaConta;
    std::string arquivoContas = "contas";
    std::vector<std::string> todasContas;
    bool entregue = false;
public:
    Conta();
    void registrarConta();
    void deletarConta();
    void perguntaResiduo(GerenciamentoDeArquivos* auxConta,std::string doaRecolhe, std::string nome);
};


#endif //TP_2_ARQUIVO_CONTA_H
