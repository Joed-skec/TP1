#include "Jogos.hpp"


JogosDeTabuleiro::JogosDeTabuleiro(int linhas, int colunas) : linhas_(linhas), colunas_(colunas){
        //Caso o vetor seja inicializado com sem parametros, entao ele sera iniciado com tamanho zero
        //Caso ele for aumentado, essas novas "casas" serao prenchidas com ' '.
    Tabuleiro_.resize(linhas, std::vector<int>(colunas, 0));
}

int JogosDeTabuleiro::getLinhas() const { return this->linhas_; };
int JogosDeTabuleiro::getColunas() const { return colunas_; };
std::vector<std::vector<int>> JogosDeTabuleiro::get_tabuleiro() const { return Tabuleiro_; };
char JogosDeTabuleiro::get_casa(int linha, int coluna) const{
    if ((linha <= linhas_) && (coluna <= colunas_))
    {
        return Tabuleiro_[linha][coluna];
    }
    return 'F';
}

void JogosDeTabuleiro::setLinhasColunas(int linha, int coluna) { linhas_ = linha; colunas_ = coluna; };

int JogosDeTabuleiro::imprimir_vetor() const {
    int casa;
    for (int i = 0; i < this->getLinhas(); i++)
    {
        std::cout << FUNDO_VERDE << "|" << RESETAR; 
        for (int j = 0; j < this->getColunas(); j++)
        {
            casa = this->get_casa(i, j);
            if(casa == 0)
            {
                std::cout << FUNDO_VERDE << " " << RESETAR;
            }
            else if (casa == 1)
            {
                std::cout << "X";
            }
            else
            {
                std::cout << FUNDO_BRANCO << "O" << RESETAR;
            }
            std::cout << FUNDO_VERDE << "|" << RESETAR;
        }
        std::cout << std::endl;
    }
    return 0;
}


Reversi::Reversi(int linhas, int colunas) : JogosDeTabuleiro(linhas, colunas) {
    JogadasValidas_.resize(linhas, std::vector<bool>(colunas, false));
}

    
std::vector<std::vector<bool>> Reversi::atualizar_jogadas_validas(int jogador) const {
    //A ideia é gerar um tabuleiro booleano no qual 0 sao jogadas invalidas e 1 sao jogadas validas.
    int preta, branca;
    std::vector<std::vector<int>> Tabuleiro = this->get_tabuleiro(); //tabuleiro real
    std::vector<std::vector<bool>> JogadasValidas = JogadasValidas_; //tabuleiro booleano

    //AGORA IREMOS PROCURAR JOGADAS VALIDAS, PRA ISSO IREMOS FAZER UM LOOP QUE IRA PASSAR POR TODAS AS CASAS.
    for (int i = 0; i < this->getLinhas(); i++)
    {
        for (int j = 0; j < this->getColunas(); j++)
        {
            verificar_jogada(i, j, jogador)
        }
    }
    //PRIMEIRAMENTE TEMOS QUE VER SE A PECA TEM ALGUMA PECA DO ADVERSARIO EM VOLTA; 
    //verificar casas invalidas por nao terem a cor oposta em volta.
    for (int i = 0; i < getLinhas()

}
int Reversi::ler_jogada(int linha, int coluna, int jogador) {

}

bool Reversi::verificar_jogada(int linha, int coluna, int jogador){
    
}


direcoes{
    {-1, -1}, {0, -1}, {1, -1},
    {-1,  1},          {1,  0}
    {-1,  1}, {1,  0}, {1,  1}
}
