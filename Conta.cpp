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
#include <vector>
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
    std::string resposta;
    std::string nome;
    GerenciamentoDeArquivos* auxArquivo2 = new GerenciamentoDeArquivos;
    todasContas = auxArquivo2->readContas(arquivoContas);
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
        if (resposta == "1"){resposta = "DOADOR";}
        if (resposta == "2"){resposta = "COLETOR";}
        resposta += "-"; resposta += nome; resposta += ".txt";
        const char* nomeConta = resposta.c_str();
        std::remove(nomeConta);
        for (long unsigned int i = 0; i < todasContas.size(); i++){
            if (nomeConta == todasContas[i]){todasContas.erase(todasContas.begin() + i);}
        }
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
    std::string tipoPessoa;
    char continua;

    std::cout << "Ola, bem vindo ao programa de coleta seletiva da cidade.\n";
    std::cout << "Qual operacao gostaria de fazer? \n";

    while (opt != 0) {
        std::cout << "[1] - Cadastrar conta\n[2] - Ver dados da conta\n[3] - Atualizar dados da conta\n"
                     "[4] - Deletar uma conta\n[5] - Agendar/Confirmar Coleta\n[0] - Sair\n";
        std::cin >> opt;

        /*    AQUI SERA CADASTRADO A CONTA    */

        if (opt == 1) {
            auxArquivo = new GerenciamentoDeArquivos;
            std::cout << "Como gostaria de ser chamado?\n";

            /*    AQUI SERA PERGUNTADO O NOME DO USUARIO    */

            while (getline(std::cin, nome)){
                if (nome != "")
                break;
            }
            /*    AQUI SERA ESCRITO O TIPO DE PESSOA NO ARQUIVO    */

            std::cout << "Voce e uma pessoa fisica ou juridica? [1] - FISICA | [2] - JURIDICA\n";
            std::cin >> resposta;
            if(resposta == "1"){tipoPessoa = "FISICA";}
            if(resposta == "2"){tipoPessoa = "JURIDICA";}

            std::cout << "Voce gostaria de doar ou recolher residuos? [1] - DOAR | [2] - COLETAR\n";
            std::cin >> resposta;
            if(resposta == "1"){
                resposta = "DOADOR";
                auxResposta += resposta; auxResposta += "-"; auxResposta += nome;

                auxArquivo->writeOnFile(arquivoContas, auxResposta+".txt"+"\n");

                auxArquivo->writeOnFile(auxResposta,"NOME:");
                auxArquivo->writeOnFile(auxResposta,nome + "\n");

                auxArquivo->writeOnFile(auxResposta,"TIPO DE PESSOA:");
                auxArquivo->writeOnFile(auxResposta,tipoPessoa + "\n");

                novaConta = new Doador();
                auxArquivo->writeOnFile(auxResposta,"LISTA DE INTERESSE:");
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, auxResposta);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
            }
            if(resposta == "2"){
                resposta = "COLETOR";
                auxResposta += resposta; auxResposta += "-"; auxResposta += nome;

                auxArquivo->writeOnFile(auxResposta,"NOME:");
                auxArquivo->writeOnFile(auxResposta,nome + "\n");
                auxArquivo->writeOnFile(auxResposta,"TIPO DE PESSOA:");
                auxArquivo->writeOnFile(auxResposta,tipoPessoa + "\n");
                novaConta = new Coletor();
                auxArquivo->writeOnFile(auxResposta,"LISTA DE INTERESSE:");
                while (continua != 'n' && continua != 'N'){
                    novaConta->perguntaResiduo(auxArquivo, resposta, auxResposta);
                    std::cout << "Gostaria de adicionar mais? [SIM] | [NAO]\n";
                    std::cin >> continua;
                }
                std::cout << "Insira o endereco de coleta: \n";
                while (getline(std::cin, resposta)) {
                    if (resposta != "")
                        break;
                }
                auxArquivo->writeOnFile(auxResposta, "\nENDERECO:");
                auxArquivo->writeOnFile(auxResposta, resposta+"\n");

                std::cout << "Insira o horario de coleta: \n";
                while (getline(std::cin, resposta)) {
                    if (resposta != "")
                        break;
                }
                auxArquivo->writeOnFile(auxResposta, "HORARIO DE COLETA:");
                auxArquivo->writeOnFile(auxResposta, resposta+"\n");
            }
            delete auxArquivo;
        }

        /*    AQUI SERA VISUALIZADO DADOS DE UMA CONTA EXISTENTE    */

        if (opt == 2) {
            std::string nome;
            std::string resposta;
            auxArquivo = new GerenciamentoDeArquivos;
            std::cout << "Informe o nome da conta: ";
            while (getline(std::cin, nome)) {
                if (nome != "")
                    break;
            }

            std::cout << "Voce e DOADOR ou COLETOR? [1] - DOADOR | [2] - COLETOR\n";
            std::cin >> resposta;
            if (resposta == "1"){resposta = "DOADOR";}
            if (resposta == "2"){resposta = "COLETOR";}

            std::vector<std::string> todosDados;
            todosDados = auxArquivo->readOnFile(nome, resposta);
            for (int i = 0; i < todosDados.size(); i++){std::cout << todosDados[i] << "\n";}
            delete auxArquivo;

        }

        /*    AQUI SERAO ATUALIZADOS DADOS DE UMA CONTA    */

        if (opt == 3){

            deletarConta();
            registrarConta();

        }

        /*    AQUI UMA CONTA SERA DELETADA    */

        if (opt == 4) {
            deletarConta();
        }
    }
}


