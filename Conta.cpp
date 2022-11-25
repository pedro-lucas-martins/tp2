//
// Created by pedro on 23/11/22.
//
#include <iostream>
#include "Conta.h"
#include "Recolhedor.h"
#include "Doador.h"
#include "Residuos.h"
#include "Solido.h"
#include "Liquido.h"

void Conta::tipoDePessoa()
{
    std::cin >> pessoaJuridica;
    while(pessoaJuridica != 1 && pessoaJuridica != 2)
    {
        std::cout << "O valor inserido nao e valido, tente novamente. ";
        std::cin >> pessoaJuridica;
    }
    if (pessoaJuridica == 1){
        pessoaS = "PESSOA FISICA";
    }
    else if (pessoaJuridica == 2){
        pessoaS = "PESSOA JURIDICA";
    }
}

bool Conta::checkIfUsed(std::string senha,std::vector<std::string>senhas)
{
    for (long unsigned int i = 0; i < senhas.size(); i++){
        if (senha == senhas[i])
            return false;
    }
return true;
}

void Conta::cadastrarConta(int isDoador)
{
    char continuar;
    std::cout << "Para realizar seu cadastro precisamos de algumas informacoes: \n";
    std::cout << "Voce e uma pessoa juridica ou fisica?\nDigite [1] para pessoa fisica ou [2] para pessoa juridica\n";
    tipoDePessoa();
    std::cout << "Como gostaria de ser chamado? \n";
    std::cin >> nome;
    do{
        if (isDoador == 1){std::cout << nome << ", quais tipos de residuos gostaria de descartar? [1] - SOLIDOS [2] - LIQUIDOS\n";}
        doador = "DOADOR";
        std::cin >> _tipoResiduo;
        if (_tipoResiduo == 1){
            currentResiduo = new Solido;
            currentResiduo->tipoSolido(); 
            residuo.push_back(currentResiduo);
            delete currentResiduo;
        }
        if (_tipoResiduo == 2){
            currentResiduo = new Liquido;
            currentResiduo->tipoLiquido();
            residuo.push_back(currentResiduo);
            delete currentResiduo;
        }
        std::cout << "Deseja adicionar mais algum residuo? [S] - SIM | [N] - NAO\n";
        std::cin >> continuar;
    }while(continuar != 'N' && continuar != 'n');
}

Conta::Conta()
{

}
Conta::~Conta()
{

}

const std::string &Conta::getNome() const {
    return nome;
}

const std::string &Conta::getPessoaS() const {
    return pessoaS;
}

const std::string &Conta::getDoador() const {
    return doador;
}

const std::vector<Residuos *> &Conta::getResiduo() const {
    return residuo;
}



