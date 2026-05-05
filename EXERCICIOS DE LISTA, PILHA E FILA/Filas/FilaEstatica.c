/*Mesmo exercício de fila, porém em linguagem C*/

#include <stdio.h>
#include <stdlib.h>

//Struct para a Fila Estática. 
typedef struct {
    //Inicializar atributos. 
    int array[5]; //Vetor para armazenar 5 elementos. 
    int inicio; 
    int fim; 
} Fila; 

//Função para inicializar a fila. 
void inicializa (Fila *fila) {
    //Fila começa vazia. 
    fila->inicio = 0; 
    fila->fim = 0;
}

//Método para inserir (Enfileirar)
void inserir (Fila *fila, int elemento) {
    //Se a fila não estiver cheia. 
    if (fila->fim < 5) {
        //Inserir o elemento no final 
        fila->array[fila->fim] = elemento; 
        fila->fim++; //Incrementar o fim da fila. 
    } else {
        printf("Erro: Fila Cheia!\n");
    }
}

//Método para remover (Desenfileirar)
int remover (Fila *fila) {
    //Variável para guardar o elemento removido. 
    int elementoRemovido; 

    //Se a fila não estiver vazia.
    if (fila->inicio < fila->fim) {
        //Guardar o elemento removido. 
        elementoRemovido = fila->array[fila->inicio]; //Elemento removido é o do início da fila. 

        //Deslocar os elementos para a esquerda
        for (int i = fila->inicio; i < fila->fim - 1; i++) {
            fila->array[i] = fila->array[i + 1]; //O elemento da posição i, recebe o elemento da posição i + 1 (próximo dele), e desloca-se para a esquerda.
        }

        //Decrementar o fim da fila.
        fila->fim--;
    } else {
        printf("Erro: Fila Vazia!\n");
    }

    //Retornar o elemento removido.
    return elementoRemovido;
}

//Método para mostrar os elementos da fila.
void mostrar (Fila *fila) {
    //Se a fila não estiver vazia. 
    if (fila->inicio < fila->fim) {
        printf("Elementos da Fila:\n"); 
        for (int i = fila->inicio; i < fila->fim; i++) {
            printf("%d ", fila->array[i]);
        }
        printf("\n");
    }
}

//Função Principal.
int main() {
    //Criar a fila.
    Fila fila; 

    //Chamar o inicializar
    inicializa(&fila); 

    //Testar as funções.
    inserir(&fila, 5);
    inserir(&fila, 10);
    inserir(&fila, 15); 
    inserir(&fila, 20);
    inserir(&fila, 25);

    //Mostrar a fila após as inserções.
    printf("Fila após inserções:\n");
    mostrar(&fila);

    //Remover elementos da fila.
    remover(&fila); 
    remover(&fila); 

    //Mostrar a fila após as remoções.
    printf("\nFila após remoções:\n");
    mostrar(&fila);

    return 0; 
}