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


const std::vector<std::pair<int, int>> Reversi::direcoes = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

Reversi::Reversi(int linhas, int colunas) : JogosDeTabuleiro(linhas, colunas) {
    JogadasValidas_.resize(linhas, std::vector<bool>(colunas, false));
    
    // Configuração inicial padrão do Reversi
    // Coloca as 4 peças iniciais no centro do tabuleiro
    int meio_linha = linhas / 2;
    int meio_coluna = colunas / 2;
    
    Tabuleiro_[meio_linha-1][meio_coluna-1] = 2;   // O
    Tabuleiro_[meio_linha-1][meio_coluna] = 1;     // X
    Tabuleiro_[meio_linha][meio_coluna-1] = 1;     // X
    Tabuleiro_[meio_linha][meio_coluna] = 2;       // O
}

bool Reversi::verificar_direcao(int linha, int coluna, int dLinha, int dColuna, int jogador) const {
    int oponente = (jogador == 1) ? 2 : 1;
    int novaLinha = linha + dLinha;
    int novaColuna = coluna + dColuna;
    bool encontrou_oponente = false;
    
    if (get_casa(linha + dLinha, coluna + dColuna) != 0) return false; //se a primeira casa nessa direcao for zero, entao é invalida
    
    while (novaLinha >= 0 && novaLinha < getLinhas() &&  //enquanto estiver no tabuleiro 
           novaColuna >= 0 && novaColuna < getColunas()) {
        
        int casa_atual = get_casa(novaLinha, novaColuna);
        
        if (casa_atual == 0) return false; 
        if (casa_atual == oponente) {
            encontrou_oponente = true;
        }
        if (casa_atual == jogador) {
            return encontrou_oponente;  // se encontrar uma casa do oponente e dps (sem encotnrar zeros) encontrar uma casa propria do jogador, entao a direcao é valida!
        }
        
        novaLinha += dLinha;
        novaColuna += dColuna;
    }
    
    return false;
}

bool Reversi::verificar_jogada(int linha, int coluna, int jogador) const {
    int oponente = (jogador == 1) ? 2 : 1;
    if (linha < 0 || linha >= getLinhas() || coluna < 0 || coluna >= getColunas()) {
        return false;
    }
    
    if (get_casa(linha, coluna) != 0) { //Verifica se tentou jogar em uma casa vazia
        return false;
    }
    
    for (const auto& dir : direcoes) { //verifica todas direcoes
        if (verificar_direcao(linha, coluna, dir.first, dir.second, jogador)) {
            return true;
        }
    }
    
    return false;
}

int Reversi::ler_jogada(int linha, int coluna, int jogador) {
    if (!verificar_jogada(linha, coluna, jogador)) { //verifica se a jogada é valida
        return 0;
    }
    
    Tabuleiro_[linha][coluna] = jogador;
    
    int oponente = (jogador == 1) ? 2 : 1;
    int pecas_capturadas = 0;
    
    for (const auto& dir : direcoes) {
        if (verificar_direcao(linha, coluna, dir.first, dir.second, jogador)) {
            int novaLinha = linha + dir.first;
            int novaColuna = coluna + dir.second;
            
            while (get_casa(novaLinha, novaColuna) == oponente) {
                Tabuleiro_[novaLinha][novaColuna] = jogador;
                pecas_capturadas++;
                novaLinha += dir.first;
                novaColuna += dir.second;
            }
        }
    }
    
    return pecas_capturadas;
}

std::vector<std::vector<bool>> Reversi::atualizar_jogadas_validas(int jogador) const {
    std::vector<std::vector<bool>> jogadas_validas(getLinhas(), 
                                                  std::vector<bool>(getColunas(), false));
    
    for (int i = 0; i < getLinhas(); i++) {
        for (int j = 0; j < getColunas(); j++) {
            jogadas_validas[i][j] = verificar_jogada(i, j, jogador);
        }
    }
    
    return jogadas_validas;
}

bool Reversi::testar_condicao_de_vitoria() const {
    std::vector<std::vector<bool>> jogadas_validas_1 = atualizar_jogadas_validas(1);
    std::vector<std::vector<bool>> jogadas_validas_2 = atualizar_jogadas_validas(2);

    bool ha_jogadas_1 = false;
    bool ha_jogadas_2 = false;

    for (const auto& linha : jogadas_validas_1) {
        for (bool jogada : linha) {
            if (jogada) ha_jogadas_1 = true;
        }
    }

    for (const auto& linha : jogadas_validas_2) {
        for (bool jogada : linha) {
            if (jogada) ha_jogadas_2 = true;
        }
    }

    return !ha_jogadas_1 && !ha_jogadas_2;
}
