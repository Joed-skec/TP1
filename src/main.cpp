#include <iostream>
#include <stdlib.h>
#include <string>
#include "cadastro.hpp"
#include "jogos.hpp"
#include "partida.hpp"

constexpr unsigned int hashString(const char* str, unsigned int hash = 0) {
    return *str ? hashString(str + 1, (hash * 31) + *str) : hash;
}
int main () {

    //inicializa o vetor de cadastro, carregando as informações do .txt
    Cadastro* jogadores;
    
    //fazer cadastro
   
    std::string inputApelido;
    std::string inputNome;
    

    //verifica se já está cadastrado. procura no vetor de cadastro. se estiver cadastrado, faz o login, 
    //instanciando o objeto Jogador 1 com as informações de login. análogo para Jogador 2.

    //realiza o cadastro, ou seja, chama o construtor da classe Jogador, adiciona ao vetor de cadastro e atualiza o banco de dados,
    //cadastro.txt.

    std::string comando;

    switch(hashString(comando.c_str())) {
        
    }

    return 0;
}