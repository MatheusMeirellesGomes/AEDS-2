/*Implemente a função void insertionSort(), para ordenar uma lista duplamente encandeada circular. A lista é globalmente representada apenas
pelo ponteiro primeiro, que aponta para a célula cabeça da lista. O ponteiro prox da última célula aponta para a célula cabeça. 
Código Fornecido: */

#include <stdio.h>
#include <stdlib.h> 

typedef struct Celula {
    int elemento; 
    struct Celula *prox; 
    struct Celula *ant;
} Celula;

Celula *novaCelula(int elemento) {
    Celula *novo = (Celula *)malloc(sizeof(Celula)); 
    novo->elemento = elemento; 
    novo->ant = novo->prox = NULL; 
    return novo; 
}

Celula *primeiro;

//Implementação do método de ordenação da lista. 
void insertionSort() {
    //Verificar se a lista não está vazia
    if (primeiro != NULL) {
        //Percorrer a lista a partir do segundo elemento. 
        for (Celula *atual = primeiro->prox; atual != primeiro; atual = atual->prox) {
            //Variável chave, que vai ser o segundo elemento da lista.
            int chave = atual->elemento; 

            //Célula j, que vai ser o elemento anterior do atual.
            Celula *j = atual->ant; //então j, é o primeiro elemento da lista.

            //Enquanto j for diferente do último elemento da lista e j for maior que o elemento guardado em chave
            while (j != primeiro->ant && j->elemento > chave) {
                //Se as duas condições derem verdadeiras
                j->prox->elemento = j->elemento; //O próximo elemento do j, recebe o j (o primeiro elemento vai para a segunda pos)
                j = j->ant; //j agora é o anterior dele, voltando pro while até a condição dar falsa
            }

            //O próximo elemento de j, recebe o valor que esta guardado em chave, ordenando as duas posições e avançando para o próximo.
            j->prox->elemento = chave; 
        }
    }
}