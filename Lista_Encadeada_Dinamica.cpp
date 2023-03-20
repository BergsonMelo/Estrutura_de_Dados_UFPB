#include <iostream>
#include "Lista_Encadeada_Dinamica.h"
using namespace std;


        No::No(int elem){
            elemento = elem;
            proximo = NULL;
        }

        int No::get_elemento(){
            return elemento;
        }

        No* No::get_proximo(){
            return proximo;
        }

        void No::set_proximo(No* prox){
            proximo = prox;
        }

        void No::set_elemento(int elem){
            elemento = elem;
        }



        Lista::Lista(){
            cabeca = NULL;
            tamanho_lista = 0;
        }

        Lista::Lista(int elemento, int tam){
            tamanho_lista = tam;
            cabeca = new No(elemento);
        }

        Lista::~Lista(){
            delete cabeca;
        }

        bool Lista::vazia(){
            if(tamanho_lista == 0){
                cout<<"A lista esta vazia."<<endl;
                return true;
            }
            else{
                cout<<"A lista nao esta vazia."<<endl;
                return false;
            }
        }

        int Lista::tamanho(){
            return tamanho_lista;
        }

        int Lista::obter_elemento(int posicao){
            No* auxiliar = cabeca;
            int count = 1;
            if(tamanho_lista == 0 or posicao < 1 or posicao > tamanho_lista){
                cout<<"Posicao invalida.";
                return -1;
            }
            while(count < posicao){
                auxiliar = auxiliar->get_proximo();
                count += 1;
            }
            
            return auxiliar->get_elemento();
        }

        int Lista::obter_posicao(int elemento_procurado){
            int count = 1;
            No* auxiliar = cabeca;
            if(tamanho_lista == 0)
                return 0;
            while(auxiliar != NULL){
                if(auxiliar->get_elemento() == elemento_procurado)
                    return count;
                auxiliar = auxiliar->get_proximo();
                count += 1;
            }
            return -1;
        }

        bool Lista::insere_inicio(int novo_elemento){
            No* novo_no = new No(novo_elemento); 
            novo_no->set_proximo(cabeca);
            cabeca = novo_no;
            tamanho_lista += 1;
            return true;
        }

        bool Lista::insere_meio(int posicao, int novo_elemento){
            No* novo_no = new No(novo_elemento);
            int count = 1;
            No* auxiliar = cabeca;
            while(count < posicao - 1 and auxiliar != NULL){
                auxiliar = auxiliar->get_proximo();
                count += 1;
            }
            if(auxiliar == NULL)
                return false;
            novo_no->set_proximo(auxiliar->get_proximo());
            auxiliar->set_proximo(novo_no);
            tamanho_lista += 1;
            return true;
        }

        bool Lista::insere_final(int novo_elemento){
            No* novo_no = new No(novo_elemento);
            No* auxiliar = cabeca;
            while(auxiliar->get_proximo() != NULL){
                auxiliar = auxiliar->get_proximo();
            }
            novo_no->set_proximo(NULL);
            auxiliar->set_proximo(novo_no);
            tamanho_lista += 1;
            return true;
        }

        bool Lista::insere(int posicao, int novo_elemento){
            if(tamanho_lista == 0 and posicao != 1)
                return false;
            else if(posicao > tamanho_lista + 1)
                return false;
            else if(posicao < 1)
                return false;
            else if(posicao == 1)
                return insere_inicio(novo_elemento);
            else if(posicao == tamanho_lista + 1)
                return insere_final(novo_elemento);
            else
                return insere_meio(posicao, novo_elemento);
        }

        int Lista::remove_inicio(){
            No* auxiliar_r = cabeca;
            int elemento_removido = auxiliar_r->get_elemento();
            cabeca = auxiliar_r->get_proximo();
            tamanho_lista -= 1;
            delete auxiliar_r;
            return elemento_removido;
        }

        int Lista::remove_meio_final(int posicao){
            No* atual = NULL;
            No* antecessor = NULL;
            int count = 1;
            int elemento_removido = -1;
            atual = cabeca;
            while(count < posicao and atual != NULL){
                antecessor = atual;
                atual = atual->get_proximo();
                count += 1;
            }
            if(atual == NULL)
                return -1;
            elemento_removido = atual->get_elemento();
            antecessor->set_proximo(atual->get_proximo());
            tamanho_lista -= 1;
            delete atual;
            return elemento_removido;
        }

        int Lista::remove(int posicao){
            if(tamanho_lista == 0)
                return -1;
            else if(posicao < 1)
                return -1;
            else if(posicao == 1)
                return remove_inicio();
            else 
                return remove_meio_final(posicao); 
        }

        void Lista::print_lista(){
            No* c = cabeca;
            if(tamanho_lista == 0){
                cout<<"A lista nao possui elementos."<<endl;
            }
            for(int i=0; i<tamanho_lista; i++){
                cout<<c->get_elemento()<< " ";
                c = c->get_proximo();
            }
            cout<<"\n";
        }


int main(){
    cout<<"::Criacao da lista::"<<endl;
    Lista lista;
    lista.vazia();

    ///Inserção dos elementos na lista///
    cout<<"\n::Inserindo elementos na lista::"<<endl;
    cout<<"::Elemento 25 na posicao 1::"<<endl;
    lista.insere(1, 25);                        ///Parâmetros : Posição e elemento a ser inserido, respectivamente.
    cout<<"::Elemento 6 na posicao 1::"<<endl;
    lista.insere(1,6); 
    cout<<"::Elemento 8 na posicao 1::"<<endl;
    lista.insere(1,8);
    cout<<"::Elemento 76 na posicao -1(posicao invalida)::"<<endl;
    lista.insere(-1,76);
    cout<<"::Elemento 12 na posicao 2::"<<endl;
    lista.insere(2,12);
    cout<<"::Elemento 81 na posicao 4::"<<endl;
    lista.insere(4,81);
    cout<<"::Elemento 50 na posicao 9(posicao invalida)::"<<endl;
    lista.insere(9,50);
    cout<<"::Elemento 100 na posicao 6::"<<endl;
    lista.insere(6,100);

    ///Exibindo a lista///
    cout<<"::Visualizando a lista apos a insercao dos elementos::"<<endl;
    lista.print_lista();

    cout<<"\n::Checando se a lista esta vazia mais uma vez::"<<endl;
    lista.vazia();

    ///Obtendo elementos a partir de uma posição///
    cout<<"\n::Obtendo o elemento da posicao 4:: ";
    cout<<lista.obter_elemento(4)<<endl;
    cout<<"\n::Obtendo o elemento da posicao 11(invalida):: ";
    cout<<lista.obter_elemento(11)<<endl;

    ///Obtendo a posição a partir do elemento dado///
    cout<<"\n::Obtendo a posicao do elemento 12:: ";
    cout<<lista.obter_posicao(12)<<endl;
    cout<<"\n::Obtendo a posicao do elemento 0(invalido):: ";
    cout<<lista.obter_posicao(0)<<endl;

    ///Remoção dos elementos da lista///
    cout<<"\n::Removendo elementos da lista::"<<endl;

    cout<<"::Removendo o elemento da posicao 2::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(2)<<endl;
    cout<<"::Removendo o elemento da posicao 5::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(5)<<endl;
    cout<<"::Removendo o elemento da posicao 3::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(3)<<endl;
    cout<<"::Removendo o elemento da posicao 2::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(2)<<endl;
    cout<<"::Removendo o elemento da posicao 1::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(1)<<endl;
    cout<<"::Removendo o elemento da posicao 7(posicao invalida)::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(7)<<endl;
    cout<<"::Removendo o elemento da posicao 0(posicao invalida)::"<<endl;
    cout<<"Elemento removido::"<<lista.remove(0)<<endl;

    ///Exibindo a lista novamente///
    cout<<"\n::Visualizando a lista apos a remocao dos elementos::"<<endl;
    lista.print_lista();
   
   ///Obtendo o tamanho da lista///
    cout<<"Tamanho da lista::"<<lista.tamanho()<<endl;
}