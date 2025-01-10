#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include <memory>
#include <algorithm>

class Jogador {
private:
    std::string _nome;
    std::string _apelido;
    int _vitorias;
    int _derrotas;

public:
    // construtor
    Jogador(const std::string& nome = "", const std::string& apelido = "", int vitorias = 0, int derrotas = 0)
        : _nome(nome), _apelido(apelido), _vitorias(vitorias), _derrotas(derrotas) {}

    //destrutor
    ~Jogador() {}

    // métodos de acesso
    std::string getNome() const { return _nome; }
    std::string getApelido() const { return _apelido; }
    int getVitorias() const { return _vitorias; }
    int getDerrotas() const { return _derrotas; }

    void setNome(const std::string& nome) { _nome = nome; }
    void setApelido(const std::string& apelido) { _apelido = apelido; }
    void setVitorias(int vitorias) { _vitorias = vitorias; }
    void setDerrotas(int derrotas) { _derrotas = derrotas; }

    // serializar o jogador como string para salvar em arquivo
    std::string serializar() const {
        return _nome + "," + _apelido + "," + std::to_string(_vitorias) + "," + std::to_string(_derrotas);
    }

    // deserializar uma string para criar um jogador
    static Jogador deserializar(const std::string& linha) {
        size_t pos1 = linha.find(',');
        size_t pos2 = linha.find(',', pos1 + 1);
        size_t pos3 = linha.find(',', pos2 + 1);

        std::string nome = linha.substr(0, pos1);
        std::string apelido = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        int vitorias = std::stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));
        int derrotas = std::stoi(linha.substr(pos3 + 1));

        return Jogador(nome, apelido, vitorias, derrotas);
    }
};


class Cadastro {
private:
    std::vector<std::unique_ptr<Jogador>> _jogadores;

public:
    // adicionar jogador ao vetor de cadastros
    void adicionarJogador(const Jogador& alvo) {
        _jogadores.push_back(std::make_unique<Jogador>(alvo.getNome(), alvo.getApelido(), alvo.getVitorias(), alvo.getDerrotas()));
        std::cout << "Jogador adicionado com sucesso!" << std::endl;
    }

    // mostra o vetor de cadastros
    void mostrarJogadores() const {
        if (_jogadores.empty()) {
            std::cout << "Nenhum jogador cadastrado." << std::endl;
            return;
        }

        for (const auto& jogador : _jogadores) {
            std::cout << "Nome: " << jogador->getNome() << ", Apelido: " << jogador->getApelido()
                      << ", Vitórias: " << jogador->getVitorias() << ", Derrotas: " << jogador->getDerrotas() << std::endl;
        }
    }

    // importa cadastros de um arquivo .txt alvo.
    void import(const std::string& caminho) {
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
        std::cout << "Jogadores importados com sucesso!" << std::endl;
    }

    // remove o jogador do vetor de cadastros por apelido
    void removeJogador(const std::string& apelido) {
    auto it = std::remove_if(
        _jogadores.begin(), 
        _jogadores.end(),
        [&apelido](const std::unique_ptr<Jogador>& jogador) {
            return jogador->getApelido() == apelido;
        }
    );

    if (it != _jogadores.end()) {
        _jogadores.erase(it, _jogadores.end());
        std::cout << "Jogador com apelido \"" << apelido << "\" removido com sucesso." << std::endl;
    } else {
        std::cout << "Jogador com apelido \"" << apelido << "\" não encontrado." << std::endl;
    }
}


    // verifica se um jogador está dentro do cadastro e retorna verdadeiro ou falso
    bool check(const Jogador& alvo) const {
        for (const auto& jogador : _jogadores) {
            if (jogador->getApelido() == alvo.getApelido()) {
                return true;
            }
        }
        return false;
    }
};

#endif
