//
// Created by pedro on 24/11/22.
//

#include "Conta.h"
#include "Residuos.h"
#include "Liquido.h"
#include "Solido.h"
#include <iostream>
#include <vector>


Residuos::Residuos(int tipoResiduo)
{

};

Residuos::Residuos(){};

void Residuos::tipoSolido()
{
    int residuo;
    std::cout << "Selecione um dos materias:\n[1] - METAL\n[2] - PAPEL\n[3] - VIDRO\n[4] - PLASTICO\n";
    std::cin >> residuo;
    switch(residuo){
        case 1: {
            this->nomeSolido = "METAL";
            listaDeInteresse.push_back(nomeSolido);
            break;
        };
        case 2: {
            this->nomeSolido= "PAPEL";
            listaDeInteresse.push_back(nomeSolido);
            break;
        };
        case 3: {
            this->nomeSolido= "PAPEL";
            listaDeInteresse.push_back(nomeSolido);
            break;
        };
        case 4: {
            this->nomeSolido= "PLASTICO";
            listaDeInteresse.push_back(nomeSolido);
            break;
        };
    }
}

void Residuos::tipoLiquido()
{
    int residuo;
    std::cout << "Selecione um dos materias:\n[1] - OLEO DE COZINHA\n[2] - QUEROSENE\n[3] - PESTICIDA\n[4] - PRODUTOS QUIMICOS\n";
    std::cin >> residuo;
    switch (residuo){
        case 1: {
            this->nomeLiquido = "OLEO DE COZINHA";
            listaDeInteresse.push_back(nomeLiquido);
            break;
        };
        case 2: {
            this->nomeLiquido = "QUEROSENE";
            listaDeInteresse.push_back(nomeLiquido);
            break;
        };
        case 3: {
            this->nomeLiquido = "PESTICIDA";
            listaDeInteresse.push_back(nomeLiquido);
            break;
        };
        case 4: {
            this->nomeLiquido = "PRODUTOS QUIMICOS";
            listaDeInteresse.push_back(nomeLiquido);
            break;
        };
    }
}

const std::vector<std::string> &Residuos::getListaDeInteresse() const {
    return listaDeInteresse;
}

