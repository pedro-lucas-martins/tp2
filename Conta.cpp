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
    todasContas = auxArquivo2->readContas();
    std::cout << "Tem certeza que deseja remover sua conta do sistema? [1] - SIM | [2] - NAO\n";
    std::cin >> resposta;
    if (resposta == "1"){
        std::string auxAuxString;
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
        for (int i = 0; i < resposta.size(); i++){
            auxAuxString += toupper(resposta[i]);
        }
        resposta = auxAuxString;
        const char* nomeConta = resposta.c_str();
        std::remove(nomeConta);
        for (long unsigned int i = 0; i < todasContas.size(); i++){
            if (resposta == todasContas[i]){
                todasContas.erase(todasContas.begin() + i);
                auxArquivo2->rewriteContas(todasContas);
            }
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
                std::string auxAuxString;
                resposta = "DOADOR";
                auxResposta += resposta; auxResposta += "-"; auxResposta += nome;
                for (int i = 0; i < auxResposta.size(); i++){
                    auxAuxString += toupper(auxResposta[i]);
                }
                auxResposta = auxAuxString;
                auxArquivo->writeOnFile(arquivoContas, auxResposta+".txt");

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
                for (int i = 0; i < auxResposta.size(); i++){
                    auxResposta[i] = toupper(auxResposta[i]);
                }
                auxArquivo->writeOnFile(arquivoContas, auxResposta+".txt");

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

                auxArquivo->writeOnFile(auxResposta, "DOADORES: \n");
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

        /*    AQUI SERA AGENDADO E CONFIRMADO ENCONTROS ENTRE DOADORES E COLETORES    */

        if (opt == 5){
            std::string doadorColetor;
            std::string nome2;
            auxArquivo = new GerenciamentoDeArquivos;
            std::cout << "Voce e DOADOR ou COLETOR? [1] - DOADOR | [2] - COLETOR\n";
            std::cin >> doadorColetor;
            if (doadorColetor == "1"){
                std::string auxAuxString1;
                std::string auxAuxString;
                auxArquivo = new GerenciamentoDeArquivos;
                
                auxArquivo->mostraColetores(); 
                
                std::cout << "Insira o nome do COLETOR que voce gostaria de doar: \n";
                
                while (getline(std::cin, nome)){
                    if (nome != "")
                    break;
                }

                for (int i = 0; i < nome.size(); i++){
                    auxAuxString += toupper(nome[i]);
                }
                nome = auxAuxString;
                nome = "COLETOR-"+nome;

                std::cout << "Insira o seu nome: ";
                while (getline(std::cin, nome2)){
                    if (nome2 != "")
                    break;
                }

                for (int i = 0; i < nome2.size(); i++){
                    auxAuxString1 += toupper(nome2[i]);
                }

                nome2 = "~DOADOR-"+auxAuxString1;
                auxArquivo->writeOnFile(nome, nome2+"\n");
            }

            if (doadorColetor == "2"){
                std::string nomeArquivo;
                std::string auxString;
                std::string auxNome;
                std::string auxNome2;
                std::string nome2;
                std::vector<std::string> todosDados;
                auxArquivo = new GerenciamentoDeArquivos;

                std::cout << "Digite seu nome: ";

                while (getline(std::cin, nome)){
                    if (nome != "")
                break;
                }

                for (int i = 0; i < nome.size(); i++){
                    auxNome += toupper(nome[i]);
                }
                nome = "COLETOR-"+auxNome+".txt";

                std::cout << "Contas com DOACAO agendada: \n";
                std::ifstream arquivo(nome);
                while(arquivo.good()){
                    arquivo.ignore(1000,'~');
                    getline(arquivo, auxString);
                    std::cout << auxString << std::endl;
                }
                arquivo.close();
                std::cout << "ESCREVA O NOME DO USUARIO PARA CONFIRMAR A ENTREGA: \n";

                while (getline(std::cin, nome2)){
                    if (nome2 != "")
                break;
                }

                for (int i = 0; i < nome2.size(); i++){
                    auxNome2 += toupper(nome2[i]);
                }
                nome2 = "~DOADOR-"+auxNome2;
                std::cout << nome2 << std::endl;
                arquivo.open(nome);
                while(arquivo.good()){
                    getline(arquivo, auxString);
                    todosDados.push_back(auxString);
                }
                arquivo.close();
                for (long unsigned int i = 0; i < todosDados.size(); i++){
                    if (nome2 == todosDados[i])
                    todosDados.erase(todosDados.begin() + i);
                }
                std::ofstream arquivo2(nome);
                for (long unsigned int i = 0; i < todosDados.size(); i++){
                arquivo2 <<"\n" + todosDados[i];
                entregue = true;
                }
                arquivo2.close();
                if (entregue) std::cout << "Entrega Relizada com sucesso!" << std::endl;
                else std::cout << "Erro na entrega!" << std::endl;
            }
        }
    }
}
