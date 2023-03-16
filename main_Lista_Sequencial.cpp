#include<iostream>
#include "Lista_Sequencial.h"
using namespace std;


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