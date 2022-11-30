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
};

void Conta::registrarConta() {
    int opt = 1;
    std::string nome;
    std::string resposta;
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
            auxArquivo->writeOnFile(nome, nome);
            std::cout << "Voce e uma pessoa fisica ou juridica? [1] - FISICA | [2] - JURIDICA\n";
            std::cin >> resposta;
            if(resposta == "1"){resposta = "FISICA"; auxArquivo->writeOnFile(nome,resposta);}
            if(resposta == "2"){resposta = "JURIDICA";auxArquivo->writeOnFile(nome,resposta);}
            std::cout << "Voce gostaria de doar ou recolher residuos? [1] - DOAR | [2] - COLETAR\n";
            std::cin >> resposta;
            if(resposta == "1"){
                resposta = "DOADOR";
                auxArquivo->writeOnFile(nome,resposta);
                novaConta = new Doador();
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, nome);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
            }
            if(resposta == "2"){
                resposta = "COLETOR";
                auxArquivo->writeOnFile(nome,resposta);
                novaConta = new Coletor();
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, nome);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
            }
        }
        if (opt == 4) {
            int aux;
            std::cout << "Tem certeza que deseja remover sua conta do sistema? [SIM] | [NAO]\n";
            std::cin >> resposta;
            if (resposta == "1"){
                std::cout << "Informe o nome da conta: ";
                while (getline(std::cin, nome)){
                    if (nome != "")
                    break;
                }
                nome = nome+".txt";
                const char* nomeConta = nome.c_str();
                std::remove(nomeConta);
                aux = std::remove(nomeConta);
                if (aux = 0){
                    std::cout << "Sua conta foi removida com sucesso.";
                }
                if (aux = 1){
                    std::cout << "Houve um problema ao remover sua conta.";
                }
            }
        }
    }
}


