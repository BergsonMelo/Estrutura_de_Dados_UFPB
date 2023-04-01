#include <iostream>
#include "Pilha.h"
using namespace std;

///Pilha como vetor(sequencial)

        Pilha_Seq::Pilha_Seq(){
            pilha = new int[tamanho_maximo];
            topo = -1;
        }

        Pilha_Seq::~Pilha_Seq(){
            delete[] pilha;
        }

        bool Pilha_Seq::vazia(){
            if(topo == -1){
                cout<<"\nPilha vazia."<<endl;
                return true;
            }
            else
                return false;
        }

        bool Pilha_Seq::cheia(){
            if(topo == tamanho_maximo - 1){
                cout<<"Pilha cheia."<<endl;
                return true;
            }
            else
                return false;
        }

        int Pilha_Seq::tamanho_pilha(){
            return topo + 1;
        }

        int Pilha_Seq::elemento_topo(){
            if(vazia())
                return -1;
            return pilha[topo];
        }

        bool Pilha_Seq::push(int elemento){
            if(cheia())
                return false;
            topo += 1;
            pilha[topo] = elemento;
            return true;
        }

        int Pilha_Seq::pop(){
            int elemento_removido;
            if(vazia())
                return -1;
            elemento_removido = pilha[topo];
            topo -= 1;
            return elemento_removido;
        }


        ///No para a pilha encadeada///

        No::No(int elem){
            proximo = NULL;
            elemento = elem;
        }
        
        No* No::get_proximo(){
            return proximo;
        }

        int No::get_elemento(){
            return elemento;
        }

        void No::set_proximo(No* prox){
            proximo = prox;
        }

        void No::set_elemento(int elem){
            elemento = elem;
        }


        ///Pilha encadeada///

        Pilha_Encadeada::Pilha_Encadeada(){
            tamanho_pilha  = 0;
            topo = NULL;
        }

        Pilha_Encadeada::~Pilha_Encadeada(){
            delete topo;
        }

        bool Pilha_Encadeada::vazia(){
            if(tamanho_pilha == 0){
                cout<<"\nPilha vazia."<<endl;
                return true;
            }
            else
                return false;
        }

        int Pilha_Encadeada::tamanho_da_pilha(){
            return tamanho_pilha;
        }

        int Pilha_Encadeada::elemento_topo(){
            if(vazia())
                return -1;
            return topo->get_elemento();
        }

        bool Pilha_Encadeada::push(int elemento){
            No* novo_no = new No(elemento);
            novo_no->set_proximo(topo);
            topo = novo_no;
            tamanho_pilha +=1;
            return true;
        }

        int Pilha_Encadeada::pop(){
            if(vazia())
                return -1;
            No* auxiliar = topo;
            int elemento_removido = auxiliar->get_elemento();
            topo = auxiliar->get_proximo();
            tamanho_pilha -= 1;
            delete auxiliar;
            return elemento_removido;
        }



int main(){
    /*Testes da pilha sequencial
      Testes da pilha sequencial
      Testes da pilha sequencial*/

    Pilha_Seq pilha;
    cout<<":::TESTES DA PILHA SEQUENCIAL:::"<<endl;
    pilha.vazia();
    pilha.push(2);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(3);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(10);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(25);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(8);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(13);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(11);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    pilha.push(81);
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;

    cout<<"Elemento removido::"<<pilha.pop()<<endl;
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    cout<<"Elemento removido::"<<pilha.pop()<<endl;
    cout<<"\nElemento do topo da pilha::"<<pilha.elemento_topo()<<endl;
    cout<<"\nTamanho da pilha::"<<pilha.tamanho_pilha()<<endl;

    cout<<"\n:::Testando a inversao de um vetor [1,2,3,4,5]:::"<<endl;
    Pilha_Seq pilha2;
    int vet[5] = {1,2,3,4,5};
    int vet_invertido[5];
    for(int i=0; i<5; i++){
        pilha2.push(vet[i]);
    }
    for(int i=0; i<5; i++){
        vet_invertido[i] = pilha2.pop();
    }
    for(int i=0; i<5; i++){
        cout<<vet_invertido[i];
        cout<<" ";
    }

    cout<<"\n\n:::FIM DOS TESTES DA PILHA SEQUENCIAL:::"<<endl;
    cout<<":::FIM DOS TESTES DA PILHA SEQUENCIAL:::"<<endl;

    /*Testes da pilha sequencial
      Testes da pilha sequencial
      Testes da pilha sequencial*/

    ///----------------------------------------------------------------------------///

    /*Testes da pilha encadeada
      Testes da pilha encadeada
      Testes da pilha encadeada*/

    Pilha_Encadeada pilha_encadeada;
    cout<<"\n\n:::TESTES DA PILHA ENCADEADA:::"<<endl;
    pilha_encadeada.vazia();
    pilha_encadeada.push(2);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(3);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(10);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(25);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(8);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(13);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(11);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    pilha_encadeada.push(81);
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;

    cout<<"Elemento removido::"<<pilha_encadeada.pop()<<endl;
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    cout<<"Elemento removido::"<<pilha_encadeada.pop()<<endl;
    cout<<"\nElemento do topo da pilha::"<<pilha_encadeada.elemento_topo()<<endl;
    cout<<"\nTamanho da pilha::"<<pilha_encadeada.tamanho_da_pilha()<<endl;

    cout<<"\n:::Testando a inversao de um vetor [1,2,3,4,5]:::"<<endl;
    Pilha_Encadeada pilha_encadeada2;
    int vet2[5] = {1,2,3,4,5};
    int vet_invertido2[5];
    for(int i=0; i<5; i++){
        pilha_encadeada2.push(vet2[i]);
    }
    for(int i=0; i<5; i++){
        vet_invertido2[i] = pilha_encadeada2.pop();
    }
    for(int i=0; i<5; i++){
        cout<<vet_invertido2[i];
        cout<<" ";
    }

    cout<<"\n\n:::FIM DOS TESTES DA PILHA ENCADEADA:::"<<endl;
    cout<<":::FIM DOS TESTES DA PILHA ENCADEADA:::"<<endl;

    /*Testes da pilha encadeada
      Testes da pilha encadeada
      Testes da pilha encadeada*/
}
