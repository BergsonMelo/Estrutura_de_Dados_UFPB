#ifndef LISTA_H
#define LISTA_H
#include <iostream>

class Lista{
    private:
        int *lista;
        int tamanho_lista;
        int tamanho_vetor;
    public:
        Lista(int tam_vet = 100, int tam_list = 0);
        bool vazia();
        bool cheia();
        int obter_elemento(int posicao);
        void alterar_elemento(int posicao, int novo_elemento);
        void inserir_elemento(int posicao, int novo_elemento);
        void remover_elemento(int posicao);
        void exibir();
        ~Lista();
};
#endif