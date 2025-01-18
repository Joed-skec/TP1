#include <iostream>
#include <stdlib.h>
#include <string>
#include "cadastro.hpp"
#include "jogos.hpp"
#include "partida.hpp"
#include <algorithm>

int main () {

    //inicializa o vetor de cadastro, carregando as informações do .txt
    Cadastro jogadores;
    jogadores.import("cadastro.txt");
    

    //verifica se já está cadastrado. procura no vetor de cadastro. se estiver cadastrado, faz o login, 
    //instanciando o objeto Jogador 1 com as informações de login. análogo para Jogador 2.

    //realiza o cadastro, ou seja, chama o construtor da classe Jogador, adiciona ao vetor de cadastro e atualiza o banco de dados,
    //cadastro.txt.

    //vetor de comandos
    std::vector<std::string> commands;
    std::string inputComando;

    //comandos usados nesse programa:
    commands.push_back("CJ");//0
    commands.push_back("RJ");//1
    commands.push_back("LJ");//2
    commands.push_back("F");//3
    //só colocar os comandos que quiserem aqui e adicionar o caso no switch :)




    while (true) {
        std::cin >> inputComando; //recebe a entrada do comando

        //procura o indice do comando no vetor de comandos
        auto it = std::find(commands.begin(), commands.end(), inputComando);
        int indexComando = std::distance(commands.begin(), it);

        //tratamento de erros de entrada
        if (it == commands.end()) {
            std::cout << "comando inválido" << std::endl;
        }

        switch(indexComando) {
            case 0 :

                break;
            case 1 :
                break;
            case 2 :
                jogadores.mostrarJogadores();
                break;
            case 3 : //finalizar programa
                return 0;
            default :
                std::cout << "erro inesperado" << std::endl;
                return 1;

        }


    }
   




    return 0;
}