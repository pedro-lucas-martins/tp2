//
// Created by pedro on 29/11/22.
//

#include "Conta.h"
#include "GerenciamentoDeArquivos.h"
#include <iostream>
#include "Doador.h"
#include "Coletor.h"
#include "Residuo.h"
#include "Solido.h"
#include "Liquido.h"
#include <cstring>
#include <istream>

Conta::Conta(){};

void Conta::perguntaResiduo(GerenciamentoDeArquivos* auxArquivo, std::string doaRecebe,std::string nome)
{
    Residuo* novoResiduo;
    std::string resposta;
    if (doaRecebe == "DOADOR"){
        std::cout << "Qual tipo de residuo gostaria de Doar? [1] - SOLIDO | [2] - LIQUIDO\n";
        std::cin >> resposta;
        if (resposta == "1"){
            novoResiduo = new Solido();
            Residuo::registrarNovoSolido(auxArquivo, nome);
            delete novoResiduo;
        }
        if (resposta == "2"){
            novoResiduo = new Liquido();
            Residuo::registrarNovoLiquido(auxArquivo, nome);
            delete novoResiduo;
        }
    }

    if (doaRecebe == "COLETOR"){
        std::cout << "Qual tipo de residuo gostaria de Coletar? [1] - SOLIDO | [2] - LIQUIDO\n";
        std::cin >> resposta;
        if (resposta == "1"){
            novoResiduo = new Solido();
            Residuo::registrarNovoSolido(auxArquivo, nome);
            delete novoResiduo;
        }
        if (resposta == "2"){
            novoResiduo = new Liquido();
            Residuo::registrarNovoLiquido(auxArquivo, nome);
            delete novoResiduo;
        }
    }
}

void Conta::deletarConta()
{
    int aux;
    std::string resposta;
    std::string nome;
    std::cout << "Tem certeza que deseja remover sua conta do sistema? [1] - SIM | [2] - NAO\n";
    std::cin >> resposta;
    if (resposta == "1"){
        std::cout << "Informe o nome da conta: ";
        while (getline(std::cin, nome)){
            if (nome != "")
                break;
        }
        std::cout << "Voce e DOADOR ou COLETOR? [1] - DOADOR | [2] - COLETOR\n";
        std::cin >> resposta;
        resposta += "-"; resposta += nome;
        const char* nomeConta = resposta.c_str();
        std::remove(nomeConta);
    }
    if (resposta == "2"){
        std::cout << "Operacao cancelada.\n";
    }
}

void Conta::registrarConta() {
    int opt = 1;
    std::string nome;
    std::string resposta;
    std::string auxResposta;
    char continua;

    std::cout << "Ola, bem vindo ao programa de coleta seletiva da cidade.\n";
    std::cout << "Qual operacao gostaria de fazer? \n";

    while (opt != 0) {
        std::cout << "[1] - Cadastrar conta\n[2] - Ver dados da conta\n[3] - Atualizar dados da conta\n[4] - Deletar uma conta\n[0] - Sair\n";
        std::cin >> opt;
        if (opt == 1) {
            std::cout << "Como gostaria de ser chamado?\n";
            while (getline(std::cin, nome)){
                if (nome != "")
                break;
            }
            std::cout << "Voce gostaria de doar ou recolher residuos? [1] - DOAR | [2] - COLETAR\n";
            std::cin >> resposta;
            if(resposta == "1"){
                resposta = "DOADOR";
                auxResposta += resposta; auxResposta += "-"; auxResposta += nome;
                auxArquivo->writeOnFile(auxResposta,nome);
                novaConta = new Doador();
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, auxResposta);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
            }
            if(resposta == "2"){
                resposta = "COLETOR";
                nome = resposta+"-"+nome;
                auxArquivo->writeOnFile(nome,resposta);
                novaConta = new Coletor();
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, nome);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
            }
            std::cout << "Voce e uma pessoa fisica ou juridica? [1] - FISICA | [2] - JURIDICA\n";
            std::cin >> resposta;
            if(resposta == "1"){resposta = "FISICA"; auxArquivo->writeOnFile(auxResposta,resposta);}
            if(resposta == "2"){resposta = "JURIDICA";auxArquivo->writeOnFile(auxResposta,resposta);}
        }
        if (opt == 4) {
            deletarConta();
        }
    }
}


