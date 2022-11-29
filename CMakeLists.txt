cmake_minimum_required(VERSION 3.23)
project(tp_2_arquivo)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_2_arquivo main.cpp GerenciamentoDeArquivos.cpp GerenciamentoDeArquivos.h Conta.cpp Conta.h Residuo.cpp Residuo.h Solido.cpp Solido.h Liquido.cpp Liquido.h Doador.cpp Doador.h Coletor.cpp Coletor.h)
