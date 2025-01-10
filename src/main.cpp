#include <iostream>
#include <string>
#include "cadastro.hpp"
#include "jogos.hpp"
#include "partida.hpp"

int main () {

    //inicializa o vetor de cadastro, carregando as informações do .txt
    Cadastro jogadores;
    
    //fazer cadastro
    //input cadastro
    std::string inputApelido;
    std::string inputNome;

    std::cin >> inputNome;
    std::cin >> inputApelido;
    

    //verifica se já está cadastrado. procura no vetor de cadastro

    //realiza o cadastro, ou seja, chama o construtor da classe Jogador, adiciona ao vetor de cadastro e atualiza o banco de dados (cadastro.txt)

    
    
    return 0;
}