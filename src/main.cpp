#include <iostream>
#include <string>
#include "cadastro.hpp"
#include "jogos.hpp"
#include "partida.hpp"

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

    // while(0 == 0) {
    //     std::cin >> comando;
    //     if (comando == "CJ") {
    //         std::cin >> inputNome;
    //         std::cin >> inputApelido;
    //         Jogador novoJogador(inputNome, inputApelido);
    //         jogadores->adicionarJogador(novoJogador);
    //         break;
    //     }
    // }
    Cadastro cadastro;
        Jogador jogador("João", "john", 10, 5, 8, 4, 12, 6);
        cadastro.adicionarJogador(jogador);
        cadastro.mostrarJogadores();
    
    
    return 0;
}