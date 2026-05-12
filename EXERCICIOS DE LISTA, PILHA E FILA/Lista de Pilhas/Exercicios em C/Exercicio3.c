/*Mesmo exercício de lista de pilhas, referente ao exercício 3, porém agora na linguagem C. */

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

//Função que retorna um inteiro
int somaMaiorPilha (Lista *lista) {
    //Criar variável para guardar a soma. 
    int maiorSoma = 0; 

    //Percorrer a lista 
    for (CelulaLista *i = lista->inicio; i != NULL; i = i->prox) {
        //Variável para a soma dos elementos da pilha. 
        int somaAtual = 0; 

        //Percorrer a pilha e ir somando os elementos. 
        for (CelulaPilha *j = i->topo; j != NULL; j = j->prox) {
            somaAtual += j->elemento; 
        }

        //Verificar a soma
        if (somaAtual > maiorSoma) {
            maiorSoma = somaAtual; 
        }
    }

    //Retornar a maior soma
    return maiorSoma; 
}