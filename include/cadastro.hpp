#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>

class Cadastro {
    
    private:
        std::string nome;
        std::string apelido;
        int vitorias;
        int derrotas;
    
    public:
        //construtor
        //destrutor

        //gets
        std::string Cadastro::getNome() {return nome;}
        std::string Cadastro::getApelido() {return apelido;}
        int Cadastro::getVitorias() {return vitorias;}
        int Cadastro::getDerrotas() {return derrotas;}

        //sets
        void setNome(std::string novoNome) {nome = novoNome;}
        void setApelido(std::string novoApelido) {apelido = novoApelido;}
        void setVitorias(int novoVitorias) {vitorias = novoVitorias;}
        void setDerrotas(int novoDerrotas) {derrotas = novoDerrotas;}


};


#endif