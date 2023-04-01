#ifndef PILHA_H
#define PILHA_H

class Pilha_Seq{
    int *pilha;
    int topo;
    int tamanho_maximo = 20;
    public:
        Pilha_Seq();
        bool vazia();
        bool cheia();
        int tamanho_pilha();
        int elemento_topo();
        bool push(int elemento);
        int pop();
        ~Pilha_Seq();
};

class No{
    No* proximo;
    int elemento;
    public:
        No(int elem);
        No* get_proximo();
        int get_elemento();
        void set_proximo(No* prox);
        void set_elemento(int elem);
};

class Pilha_Encadeada{
    No* topo;
    int tamanho_pilha;
    public:
        Pilha_Encadeada();
        bool vazia();
        int tamanho_da_pilha();
        int elemento_topo();
        bool push(int elemento);
        int pop();
        ~Pilha_Encadeada();
};

#endif