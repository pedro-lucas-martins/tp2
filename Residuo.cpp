//
// Created by pedro on 29/11/22.
//

#include "Residuo.h"
#include <iostream>
#include <string>

Residuo::Residuo() = default;

void Residuo::registrarNovoSolido(GerenciamentoDeArquivos* auxArquivo, std::string nome)
{
    int residuo;
    std::cout << "Selecione um dos materias:\n[1] - METAL\n[2] - PAPEL\n[3] - VIDRO\n[4] - PLASTICO\n";
    std::cin >> residuo;
    switch (residuo){
        case 1: {
            auxArquivo->writeOnFile(nome, "METAL");
            break;
        };
        case 2: {
            auxArquivo->writeOnFile(nome, "PAPEL");
            break;
        };
        case 3: {
            auxArquivo->writeOnFile(nome, "VIDRO");
            break;
        };
        case 4: {
            auxArquivo->writeOnFile(nome, "PLASTICO");
            break;
        };
    }
};

void Residuo::registrarNovoLiquido(GerenciamentoDeArquivos* auxArquivo, std::string nome)
{
    int residuo;
    std::cout << "Selecione um dos materias:\n[1] - OLEO DE COZINHA\n[2] - QUEROSENE\n[3] - PESTICIDA\n[4] - PRODUTOS QUIMICOS\n";
    std::cin >> residuo;
    switch (residuo){
        case 1: {
            auxArquivo->writeOnFile(nome, "OLEO DE COZINHA");
            break;
        };
        case 2: {
            auxArquivo->writeOnFile(nome, "QUEROSENE");
            break;
        };
        case 3: {
            auxArquivo->writeOnFile(nome, "PESTICIDA");
            break;
        };
        case 4: {
            auxArquivo->writeOnFile(nome, "PRODUTOS QUIMICOS");
            break;
        };
    }
}


/*
            if(resposta == "1"){resposta = "DOADOR"; auxArquivo->writeOnFile(nome,resposta);}
            if(resposta == "2"){resposta = "RECOLHEDOR";auxArquivo->writeOnFile(nome,resposta);}
 */