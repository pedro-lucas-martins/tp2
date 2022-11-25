#include "Conta.h"
#include "Doador.h"
#include "Recolhedor.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Conta*> contas;
    std::vector<std::string> senhas;
    std::string senha;
    Conta* aux;
    int isDoador = 0;
    int opt = 10;
    std::cout << "Ola, bem vindo ao programa de coleta seletiva da cidade.\n";
    std::cout << "Qual operacao gostaria de fazer? \n";

    while (opt != 0)
    {
        std::cout << "[1] - Cadastrar conta\n[2] - Ver dados da conta\n[3] - Atualizar dados da conta\n[4] - Deletar uma conta\n[0] - Sair\n";
        std::cin >> opt;
            if(opt == 1)
            {
                std::cout << "Voce gostaria de doar ou recolher residuos? [1] - DOAR [2] - RECOLHER\n";
                std::cin >> isDoador;
                if (isDoador == 1){aux = new Doador();}
                if (isDoador == 2){aux = new Recolhedor();}
                aux->cadastrarConta(isDoador);
                contas.push_back(aux);
                std::cout << "Por fim, crie uma senha numerica: (Deve possuir 4 digitos)\n";
                std::cin >> senha;
                while(true){
                    if(!aux->checkIfUsed(senha, senhas)) {
                        std::cout << "Senha ja em uso, tente novamente: \n";
                        std::cin >> senha;
                    }
                    else{
                        senhas.push_back(senha);
                        break;
                    }
                }
                std::cout << "Conta criada com sucesso!\n";
            }
            if(opt == 2)
            {
                std::string auxSenha;
                long unsigned int pos;
                std::vector <Residuos*> auxResiduo;
                std::vector<std::string> auxListaDeInteresse;

                std::cout << "Insira a sua senha: ";
                std::cin >> auxSenha;
                for (long unsigned int i = 0; i < senhas.size(); i++){
                    if (auxSenha == senhas[i]){
                        pos = i;
                    }
                }
                std::cout << "NOME: " << contas[pos]->getNome() << '\n';
                std::cout << "PESSOA FISICA/JURIDICA: " << contas[pos]->getPessoaS() << '\n';
                std::cout << "DOADOR/COLETOR: " << contas[pos]->getDoador() << '\n';
                std::cout << "SENHA: " << senhas[pos] << '\n';
            }
    }
    std::cout << "Obrigado por contribuir com a coleta seletiva da cidade.\n";
}

/* PARA ACESSAR A CONTA FUTURAMENTE, SERA GERADA UMA SENHA PARA O USUARIO */
