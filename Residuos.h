//
// Created by pedro on 24/11/22.
//

#ifndef TP_2_RESIDUOS_H
#define TP_2_RESIDUOS_H
#include <vector>
#include <string>


class Residuos {
private:
    std::vector<std::string> listaDeInteresse;
public:
    Residuos();
    Residuos(int tipoResiduo);
    void tipoSolido();
    void tipoLiquido();
    std::string nomeSolido;
    std::string nomeLiquido;

    const std::vector<std::string> &getListaDeInteresse() const;
};


#endif //TP_2_RESIDUOS_H
