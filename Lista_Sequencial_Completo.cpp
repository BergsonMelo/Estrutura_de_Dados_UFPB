#include <iostream>
#include "Lista_Sequencial.h"
using namespace std;


     Lista::Lista(int tam_vet, int tam_list){
        tamanho_lista = tam_list;
        tamanho_vetor = tam_vet;
        lista = new int[tam_vet];
        cout<<"Lista criada."<<endl;
        for(int i=0; i < 6; i++){
            lista[i] = i * 5;
            tamanho_lista += 1;
        }
        cout<<"Lista preenchida os seguintes valores:";

     }
     Lista::~Lista(){
        delete[] lista;
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

     bool Lista::cheia(){
        if(tamanho_lista == tamanho_vetor){
            cout<<"A lista esta cheia."<<endl;
            return true;
        }
        else
            return false;
     }

     int Lista::obter_elemento(int posicao){
        if(posicao <= 0 or posicao > tamanho_lista){
            cout<<"A posicao inserida e invalida."<<endl;
            return -1;
        }
        else
            return lista[posicao - 1];
     }

     void Lista::alterar_elemento(int posicao, int novo_elemento){
        if(posicao <= 0 or posicao > tamanho_lista)
            cout<<"\nA posicao inserida e invalida."<<endl;
        else
            lista[posicao - 1] = novo_elemento;  
     }

     void Lista::inserir_elemento(int posicao, int novo_elemento){
        if(cheia() or posicao> tamanho_lista or posicao <=0)
            cout<<"\nA posicao inserida e invalida."<<endl;
        else{
            for(int i=tamanho_lista; i>= posicao; i--)
                lista[i] = lista[i-1];
            lista[posicao - 1] = novo_elemento;
            tamanho_lista += 1;
        }
     }

     void Lista::remover_elemento(int posicao){
        int elemento_removido;
        if(posicao > tamanho_lista or posicao < 1)
            cout<<"\nA posicao inserida e invalida."<<endl;
        else{
            elemento_removido = lista[posicao - 1];
            for(int i = posicao - 1; i < tamanho_lista; i++)
                lista[i] = lista[i + 1];
            tamanho_lista -= 1;
            cout<<"\nO elemento removido foi o numero "<< elemento_removido<<endl;
        }
     }

     void Lista::exibir(){
        cout<<endl;
        for(int i=0; i < (tamanho_lista); i++)
            cout<< " " <<lista[i] << " ";
     }



int main(){
    Lista lista;
    lista.exibir(); ///Exibição inicial da lista.
    cout<<"\n";
    
    cout<<"\nInserindo elementos na lista."<<endl;
    lista.inserir_elemento(1,3); ///O primeiro parâmetro refere-se a posição, e o segundo refere-se ao elemento inserido.
    lista.inserir_elemento(5,65);
    lista.inserir_elemento(9, 12); ///A posição inserida é inválida, para testar a condição da função.
    lista.inserir_elemento(3, 81);
    cout<<"\nLista apos todas as insercoes:";
    lista.exibir();
    cout<<"\n";

    cout<<"\nRemovendo elementos da lista."<<endl;
    lista.remover_elemento(1); ///O parâmetro refere-se a posição do elemento removido na lista.
    lista.remover_elemento(4);
    lista.remover_elemento(2);
    lista.remover_elemento(10); ///A posição inserida é inválida, para testar a condição da função.
    cout<<"\nLista apos todas as remocoes:";
    lista.exibir();
    cout<<"\n";

    cout<<"\nElemento da posicao 4: "<<lista.obter_elemento(4)<<endl;
    cout<<"\nTentando obter um elemento de uma posicao invalida(12): ";
    cout<<lista.obter_elemento(12)<<endl;
    cout<<"\nLista atual:";
    lista.exibir();

    cout<<"\nAlterando elementos ja existentes na lista.";
    lista.alterar_elemento(2, 98);
    lista.alterar_elemento(-3, 22); ///Tentando alterar um elemento com uma posição inválida.
    cout<<"Lista final:";
    lista.exibir();

    
}