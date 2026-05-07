/*Exercício de pilha flexível na linguagem C. 
A pilha flexível é uma estrutura de dados que permite armazenar elementos de forma dinâmica, sem a necessidade de tamanho fixo. 
Diferente da lista, que possui várias posições tanto para inserir quanto para remover, a pilha possui apenas uma posição de inserir e remover
que se refere ao topo da pilha. Ela é uma estrutura LIFO (Last In, First Out), onde o último elemento inserido é o primeiro a ser removido. 
As operações básicas da pilha são: empilhar (push) - desempilhar (pop). */

#include <stdio.h> 
#include <stdlib.h> 

//Struct para Célula
typedef struct Celula {
    //Atributos que cada Célula vai possuir => Celula: [elemento | prox]
    int elemento; 
    struct Celula *prox; 
} Celula;

//Struct para Pilha. 
typedef struct {
    //Atributo único da pilha. 
    Celula *topo; 
} Pilha; 

//Construtor pra inicializar a pilha. 
void inicializa (Pilha *pilha) {
    //Estou me referindo que o topo da pilha aponta para NULL. 
    pilha->topo = NULL; 
}

//Função para empilhar um elemento. (Push)
void empilhar (Pilha *pilha, int x) {
    //Criar e alocar na memória uma nova célula. 
    Celula *novo = (Celula *)malloc(sizeof(Celula)); 

    //Atribuir o elemento a noa célula. 
    novo->elemento = x; 

    //Novo da pilha, vai apontar para o antigo topo. 
    novo->prox = pilha->topo; 

    //O topo passa a ser o novo elemento. 
    pilha->topo = novo; 
}

//Função para desempilhar um elemento (Pop)
int desempilhar (Pilha *pilha) {
    //Guardar o elemento removido. 
    int elementoRemovido = 0; 

    //Verificar se a pilha não está vazia. 
    if (pilha->topo != NULL) {
        //Guardar o elemento removido. 
        elementoRemovido = pilha->topo->elemento; 

        //Criar uma célula auxiliar para guardar o topo antigo.
        Celula *aux = pilha->topo; 

        //O topo passa a ser o próximo elemento do antigo topo. 
        pilha->topo = aux->prox; 

        //Liberar mémoria (apagar a célula antiga).
        free(aux); 
    }

    //Retornar o elemento removido.
    return elementoRemovido;
}

//Função para mostrar os elementos da pilha. (Mostrar)
void mostrar (Pilha *pilha) {
    //Loop para percorrer a pilha.
    for (Celula *i = pilha->topo; i != NULL; i = i->prox) {
        printf("%d ", i->elemento);
    }
    printf("\n");
}

//Main
int main() {
    //Criar uma pilha do tipo Pilha. 
    Pilha pilha; 

    //Inicializar a pilha. 
    inicializa(&pilha); 

    //Empilhar alguns elementos.
    empilhar(&pilha, 50);
    empilhar(&pilha, 40); 
    empilhar(&pilha, 30);
    empilhar(&pilha, 20);
    empilhar(&pilha, 10);

    //Mostrar os elementos da pilha.
    printf("Pilha antes de desempilhar:\n");
    mostrar(&pilha);

    //Desempilhar alguns elementos.
    desempilhar(&pilha);
    desempilhar(&pilha);
    desempilhar(&pilha);

    //Mostrar os elementos da pilha.
    printf("\nPilha após desempilhar:\n");
    mostrar(&pilha);

    return 0; 
}