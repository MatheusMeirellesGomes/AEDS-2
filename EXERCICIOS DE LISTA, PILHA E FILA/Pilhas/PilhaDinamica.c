/*Mesmo código de pilha, porém usando alocação dinâmica*/

#include <stdio.h> 
#include <stdlib.h>

//Strcut para pilha. 
typedef struct {
    int *array; //Vetor
    int topo; //Contador
    int capacidade; 
} Pilha;

//Inicializar o topo e a capacidade da pilha.
void inicializa (Pilha *pilha, int capacidade) {
    //Topo começa vazio. 
    pilha->topo = -1; 

    //Atribuir a capacidade da pilha.
    pilha->capacidade = capacidade;

    //Alocar dinamicamente para a capacidade n.
    pilha->array = (int *)malloc(capacidade * sizeof(int));
}

//Empilhar elemento (Push)
void empilhar (Pilha *pilha, int elemento) {
    //Verificar se ta cheia
    if (pilha->topo < pilha->capacidade - 1) {
        //Incrementa o topo e insere o elemento. 
        pilha->topo++; 
        pilha->array[pilha->topo] = elemento; //Insere o elemento no topo da pilha. 
    } else {
        printf("Pilha Cheia!\n");
    }
}

//Desempilhar elemento (Pop)
int desempilhar (Pilha *pilha) {
    //Elemento removido.
    int elementoRemovido;

    //Verificar se não ta vazia
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

//Mostrar os elementos da pilha. (Mostrar)
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

//Principal
int main() {
    //Criar uma pilha dinâmica alocada dinamicamente. 
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha)); 

    //Capacidade da pilha. 
    int n; 

    //Informar a capacidade da pilha.
    printf("Capacidade da Pilha: ");
    scanf("%d", &n);


    //Chamar inicializa
    inicializa(pilha, n);

    //Empilhar alguns elementos
    empilhar(pilha, 50);
    empilhar(pilha, 40);
    empilhar(pilha, 30);
    empilhar(pilha, 20);
    empilhar(pilha, 10);
    desempilhar(pilha);
    desempilhar(pilha);

    //Pilha depois de empilhar e desempilhar alguns elementos.
    printf("Elementos da Pilha:\n");
    mostrar(pilha);

    //Liberar a memória alocada para a pilha.
    free(pilha->array); //Liberar o array de elementos.
    free(pilha); //Liberar a estrutura da pilha.

    return 0;
}