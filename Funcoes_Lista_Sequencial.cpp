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