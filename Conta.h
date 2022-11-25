//
// Created by pedro on 23/11/22.
//

#ifndef TP_2_CONTA_H
#define TP_2_CONTA_H
#include <string>
#include <vector>
#include "Residuos.h"

class Conta {

private:
    std::vector<Residuos*> residuo;
    Residuos* currentResiduo;
    std::string nome;
    std::string pessoaS;
    std::string senha;
    int pessoaJuridica;
    std::string doador;
    int _tipoResiduo;
public:
    Conta();
    ~Conta();
    void cadastrarConta(int isDoador);
    void atualizarConta();
    void deletarConta();
    void tipoDePessoa();
    bool checkIfUsed(std::string senha, std::vector<std::string> senhas);

    const std::string &getNome() const;

    const std::string &getPessoaS() const;

    const std::string &getDoador() const;

    const std::vector<Residuos *> &getResiduo() const;

};


#endif //TP_2_CONTA_H
