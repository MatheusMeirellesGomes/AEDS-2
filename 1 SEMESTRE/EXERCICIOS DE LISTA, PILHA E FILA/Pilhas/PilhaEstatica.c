/*Código para mostrar a implementação de uma pilha estática em C
As pilhas, diferentes das listas, possuem apenas 2 componentes. Sendo eles o topo e o fundo da pilha. 
Entao os métodos da pilha são: empilhar, desempilhar e mostrar.*/ 
#include <stdio.h> 
#include <stdlib.h>

//Struct para a pilha. 
typedef struct {
    int array[6]; //Vetor de elementos. 
    int topo; //Contador. 
} Pilha; 

//Inicializar o topo
void inicializa (Pilha *pilha) {
    pilha->topo = -1; //Diferente da lista, o topo começa em -1, indicando que a pilha está vazia.
}

//Função para empilhar um elemento. (Colocar um elemento no topo da pilha: Push)
void empilhar (Pilha *pilha, int elemento) {
    //Verificar se ta vazia.
    if (pilha->topo < 5) {
        //Incrementa o topo e insere o elemento. 
        pilha->topo++; 
        pilha->array[pilha->topo] = elemento; //Insere o elemento no topo da pilha. 
    } else {
        printf("Pilha Cheia!\n");
    }
}

//Função para desempilhar um elemento. (Remover o elemento do topo da pilha: Pop)
int desempilhar (Pilha *pilha) {
    //Guardar o elemento removido.
    int elementoRemovido; 

    //Verificar se a pilha não está vazia.
    if (pilha->topo >= 0) {
        //Guardar o elemento removido. 
        elementoRemovido = pilha->array[pilha->topo]; 

         //Decrementar o topo. 
        pilha->topo--;
    } else {
        //Exibir mensagem de erro. 
        printf("Pilha Vazia!\n"); 
    }

    //Retornar o elemento removido. 
    return elementoRemovido;
}

//Função para mostrar os elementos da pilha. (Mostrar)
void mostrar (Pilha *pilha) {
    //Verificar se nao esta vazia
    if (pilha->topo >= 0) {
        for (int i = pilha->topo; i >= 0; i--) {
            printf("%d ", pilha->array[i]);
        }
        printf("\n");
    } else {
        printf("Pilha Vazia!\n");
    }
}

//Principal. 
int main() {
    //Criar a pilha. 
    Pilha pilha; 

    //Chamar o inicializar
    inicializa(&pilha); 

    //Empilhar alguns elementos
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    //desempilhar(&pilha); 
    //desempilhar(&pilha); 

    //Pilha depois de empilhar e desempilhar alguns elementos.
    printf("Elementos da Pilha:\n");
    mostrar(&pilha); 

    return 0; 
}