#include "cadastro.hpp"

std::string Jogador::serializar() const {
        return _nome + "," + _apelido + "," + 
        std::to_string(Velha._vitorias) + "," + std::to_string(Velha._derrotas) + "," + 
        std::to_string(Lig4._vitorias) + "," + std::to_string(Lig4._derrotas) + "," + 
        std::to_string(Reversi._vitorias) + "," + std::to_string(Reversi._derrotas);
        //é possível adicionar novos jogos a partir daqui.
    }

Jogador Jogador::deserializar(const std::string& linha) {

    std::vector<std::string> campos;
    size_t inicio = 0;
    size_t pos = 0;

    while ((pos = linha.find(',', inicio)) != std::string::npos) {
        campos.push_back(linha.substr(inicio, pos - inicio));
        inicio = pos + 1;
    }
    campos.push_back(linha.substr(inicio)); 

    if (campos.size() != 8) {
        throw std::invalid_argument("Formato inválido na string de entrada para deserialização.");
    }

    std::string nome = campos[0];
    std::string apelido = campos[1];
    int lig4Vitorias = std::stoi(campos[2]);
    int lig4Derrotas = std::stoi(campos[3]);
    int velhaVitorias = std::stoi(campos[4]);
    int velhaDerrotas = std::stoi(campos[5]);
    int reversiVitorias = std::stoi(campos[6]);
    int reversiDerrotas = std::stoi(campos[7]);

    return Jogador(nome, apelido, velhaVitorias, velhaDerrotas, lig4Vitorias, lig4Derrotas, reversiVitorias, reversiDerrotas);
}

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

void save(const std::string& caminho) {}


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

