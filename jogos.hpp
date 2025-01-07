#ifndef jogos_hpp
#define jogos_hpp
#include <iostream>
#include <vector>

class JogosDeTabuleiro{
    public:
        std::vector<std::vector<char>> Tabuleiro;
        int getLinhas() const;
        int getColunas() const;
        int setLinhasColunas(int linhas, int colunas);
    private:
        int linhas, colunas;
};
#endif