#ifndef JOGOS_HPP
#define JOGOS_HPP
#include <iostream>
#include <vector>
#include "cores.hpp"

class JogosDeTabuleiro {
public:
    JogosDeTabuleiro(int linhas = 0, int colunas = 0);
    virtual ~JogosDeTabuleiro() = default;  // Added virtual destructor
    
    int getLinhas() const;
    int getColunas() const;
    std::vector<std::vector<int>> get_tabuleiro() const;
    char get_casa(int linha, int coluna) const;
    void setLinhasColunas(int linha, int coluna);
    int imprimir_vetor() const;
    
    virtual int ler_jogada(int linha, int coluna, int jogador) = 0;
    virtual bool verificar_jogada(int linha, int coluna, int jogador) const = 0;
    virtual bool testar_condicao_de_vitoria() const = 0;

protected:  
    int linhas_, colunas_;
    std::vector<std::vector<int>> Tabuleiro_;
};

class Reversi : public JogosDeTabuleiro {
public:
    Reversi(int linhas = 8, int colunas = 8);
    int ler_jogada(int linha, int coluna, int jogador) override;
    bool verificar_jogada(int linha, int coluna, int jogador) const override;
    bool testar_condicao_de_vitoria() const override;
    std::vector<std::vector<bool>> atualizar_jogadas_validas(int jogador) const;

private:
    static const std::vector<std::pair<int, int>> direcoes;
    std::vector<std::vector<bool>> JogadasValidas_;
    bool verificar_direcao(int linha, int coluna, int dLinha, int dColuna, int jogador) const;
};

class JogoDaVelha : public JogosDeTabuleiro {
public:
    // Construtor padrão com tamanho 3x3
    JogoDaVelha(int linhas = 3, int colunas = 3);
    
    // Métodos herdados e sobrescritos da classe base
    int ler_jogada(int linha, int coluna, int jogador) override;
    bool verificar_jogada(int linha, int coluna, int jogador) const override;
    bool testar_condicao_de_vitoria() const override;
};
class Lig4 : public JogosDeTabuleiro{
public:

    Lig4(int linhas = 6, int colunas = 7);

    int ler_jogada(int coluna, int jogador) override;
    bool verificar_jogada(int coluna, int jogador) const override;
    bool testar_condicao_de_vitoria() const override;
};

#endif
