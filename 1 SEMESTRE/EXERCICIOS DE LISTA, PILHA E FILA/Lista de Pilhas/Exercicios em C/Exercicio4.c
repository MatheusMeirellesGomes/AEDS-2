/*Considere uma lista de pilhas, implemente o método CelulaLista primeiraPilhaPar(), que deve retornar a primeira célula da lista
que possui uma quantidade par de elementos.
Exercício em C*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct Lista {
    CelulaLista *inicio; 
    CelulaLista *fim; 
} Lista; 

typedef struct CelulaLista {
    CelulaPilha *topo; 
    CelulaLista *prox; 
} CelulaLista; 

typedef struct CelulaPilha {
    int elemento; 
    CelulaLista *prox; 
} CelulaPilha; 

CelulaLista *primeiraPilhaPar(Lista *lista) {
    //Percorrer a lista. 
    for (CelulaLista *i = lista->inicio; i != NULL; i = i->prox) {
        //Criar variável para contar a quantidade de elementos da pilha. 
        int qntdElementos = 0; 

        //Percorrer os elementos da pilha. 
        for (CelulaPilha *j = i->topo; j != NULL; j = j->prox) {
            qntdElementos++; 
        }

        //Verificar se a qntd de elementos da pilha é par
        if (qntdElementos % 2 == 0) {
            return i; //Retornar a primeira pilha par que aparecer. 
        }
    }

    //Se não houver, retornar nulo. 
    return NULL; 
} 