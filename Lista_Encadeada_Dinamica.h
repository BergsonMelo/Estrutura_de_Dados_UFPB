#ifndef LISTA_H
#define LISTA_H

class No{
    int elemento;
    No* proximo;
    public:
        No(int elem = 0);
        int get_elemento();
        No* get_proximo();
        void set_proximo(No* prox);
        void set_elemento(int elem);
};

class Lista{
    int tamanho_lista;
    No* cabeca;
    public:
        Lista();
        Lista(int elemento, int tam = 1);
        bool vazia();
        int tamanho();
        int obter_elemento(int posicao);
        int obter_posicao(int elemento_procurado);
        bool insere_inicio(int novo_elemento);
        bool insere_meio(int posicao, int novo_elemento);
        bool insere_final(int novo_elemento);
        bool insere(int posicao, int novo_elemento);
        int remove_inicio();
        int remove_meio_final(int posicao);
        int remove(int posicao);
        void print_lista();
        ~Lista();
};

#endif