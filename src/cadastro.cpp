#include "cadastro.hpp"

void Cadastro::adicionarJogador(const Jogador& alvo) { 
    _jogadores.push_back(std::make_unique<Jogador>(alvo));
    std::cout << "Jogador " << alvo.getApelido() << " cadastrado com sucesso" << std::endl;
}

void Cadastro::mostrarJogadores() const {
    if (_jogadores.empty()) {
        std::cout << "Nenhum jogador cadastrado." << std::endl;
        return;
    }
    
    for (const auto& jogador : _jogadores) {
            std::cout << "Nome: " << jogador->getNome()
                      << ", Apelido: " << jogador->getApelido()
                      << ", Vitórias Lig4: " << jogador->getVitorias(jogador->getLig4())
                      << ", Derrotas Lig4: " << jogador->getDerrotas(jogador->getLig4())
                      << ", Vitórias Velha: " << jogador->getVitorias(jogador->getVelha())
                      << ", Derrotas Velha: " << jogador->getDerrotas(jogador->getVelha())
                      << ", Vitórias Reversi: " << jogador->getVitorias(jogador->getReversi())
                      << ", Derrotas Reversi: " << jogador->getDerrotas(jogador->getReversi())
                      << std::endl;
        }
}

void Cadastro::import(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminho << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (!linha.empty()) {
            _jogadores.push_back(std::make_unique<Jogador>(Jogador::deserializar(linha)));
        }
    }
    arquivo.close();
    std::cout << "jogadores importados com sucesso." << std::endl;
}

void save(const std::string& caminho) {

}

void Cadastro::removeJogador(const Jogador& alvo) {
    auto it = std::remove_if(_jogadores.begin(), _jogadores.end(),
        [&alvo](const std::unique_ptr<Jogador>& jogador) {
            return jogador->getApelido() == alvo.getApelido();
        }
    );

    if (it != _jogadores.end()) {
        _jogadores.erase(it, _jogadores.end()); 
        std::cout << "jogador removido com sucesso" << std::endl;
    } else {
        std::cout << "jogador não encontrado." << std::endl;
    }
}

bool Cadastro::check(const Jogador& alvo) const {
        for (const auto& jogador : _jogadores) {
            if (jogador->getApelido() == alvo.getApelido()) {
                return true;
            }
        }
        return false;
    }

