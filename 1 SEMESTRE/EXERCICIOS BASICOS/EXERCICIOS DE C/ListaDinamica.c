/*Mesmo exercicio de lista, porém agora dinamicamente, e usando apenas ponteiros*/

#include <stdio.h>
#include <stdlib.h>

//Struct para lsta dinâmica.
typedef struct {
    //Inicializar variáveis. 
    int *array; //Array com os elementos. 
    int n; //Contador na pos da lista. 
    int tam; //Tamanho da lista.
} Lista; 

//Função Inicializar
void inicializa (Lista *lista, int tamanho) {
    //Inicializar o contador. 
    lista->n = 0; 

    //Inicializar o tamanho da lista.
    lista->tam = tamanho;

    //Alocar dinamicamente para tamanho n. 
    lista->array = (int *)malloc(tamanho * sizeof(int));
}

//Função para Inserir no início da Lista. (InserirInicio)
void inserirInicio (Lista *lista, int elemento) {
    //Verificar se a lista ta cheia
    if (lista->n < lista->tam) {
        //Se não tiver, andar os elementos para a direita. 
        for (int i = lista->n; i > 0; i--) {
            lista->array[i] = lista->array[i - 1]; //o elemento[i] recebe o elemento[i - 1], e desloca-se para a direita.
        }

        //Atribuir e incrementar
        lista->array[0] = elemento;
        lista->n++;
    } else {
        //Mensagem de erro. 
        printf("Lista Cheia!\n");
    }
}

//Função para Inserir em uma posição específica da Lista. (Inserir)
void inserir (Lista *lista, int elemento, int pos) {
    //Verificar a posição e se a lista ta cheia.
    if (pos >= 0 && pos <= lista->n && lista->n < lista->tam) {
        //Se tudo for válido. 
        for (int i = lista->n; i > pos; i--) {
            lista->array[i] = lista->array[i - 1]; //o elemento[i] recebe o elemento[i - 1], e desloca-se para a direita.
        }

        //Atribuir e incrementar
        lista->array[pos] = elemento;
        lista->n++;
    } else {
        printf("Posição inválida ou Lista Cheia!\n");
    }
}

//Função para Inserir no fim da Lista. (InserirFim)
void inserirFim (Lista *lista, int elemento) {
    //verificar se ta cheia
    if (lista->n < lista->tam) {
        //Se não tiver, inserir o elemento no final da lista. 
        lista->array[lista->n] = elemento; 
        lista->n++; //Incrementa o contador. 
    } else {
        //Mensagem de erro. 
        printf("Lista Cheia!\n");
    }
}

//Função para mostrar os elementos da Lista. (Mostrar)
void mostrar (Lista *lista) {
    //Percorrer a lista e mostrar os elementos. 
    for (int i = 0; i < lista->n; i++) {
        printf("%d ", lista->array[i]);
    }
    printf("\n");   
}

//Função para Remover do início da Lista. (RemoverInicio)
int removerInicio (Lista *lista) {
    //Inicializar variável
    int elementoRemovido; //Para guardar dps o elem rem. 

    //Verificar se ta vazia, pq nao adianta ta vazia 
    if (lista->n > 0) {
        //Guardar o elemento removido. 
        elementoRemovido = lista->array[0]; 

        //Andar com o resto para esquerda
        for (int i = 0; i < lista->n - 1; i++) {
            //O elemento da posição i, recebe o elemento da posição i + 1 (próximo dele), e desloca-se para a esquerda.
            lista->array[i] = lista->array[i + 1]; 
        }
        lista->n--; //Decrementar o contador.
    }

    //Retorna o removido. 
    return elementoRemovido; 
}

//Função para Remover de uma posição específica da Lista. (Remover)
int remover (Lista *lista, int pos) {
    //Inicializar variável
    int elementoRemovido; 

    //Verificar a pos e se ta vazia
    if (pos >= 0 && pos < lista->n && lista->n > 0) {
        //Guardar o elemento removido. 
        elementoRemovido = lista->array[pos]; 

        //Andar com o resto para esquerda
        for (int i = pos; i < lista->n - 1; i++) {
            //O elemento da posição i, recebe o elemento da posição i + 1 (próximo dele), e desloca-se para a esquerda.
            lista->array[i] = lista->array[i + 1]; 
        }
        lista->n--; //Decrementar o contador.
    }

    return elementoRemovido;
}

//Função para Remover do fim da Lista. (RemoverFim)
int removerFim (Lista *lista) {
    //Inicializar variável
    int elementoRemovido;

    //Verificar se ta vazia
    if (lista->n > 0) {
        //Guardar o elemento removido. 
        elementoRemovido = lista->array[lista->n - 1]; 

        //Decrementar o contador.
        lista->n--;
    }

    return elementoRemovido;
}

 

//Main
int main() {
    //Tamanho da lista. 
    int tam; 

    //Informar tamanho da lista.
    printf("Tamanho da Lista: ");
    scanf("%d", &tam);

    //Criar uma lista dinâmica alocada para tamanho n.
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    //Inicializar a lista
    inicializa(lista, tam); 

    //Testar as funções.
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserir(lista, 15, 1); 
    inserirFim(lista, 5);
    inserirFim(lista, 25);
    inserirInicio(lista, 30);
    inserir(lista, 12, 2);
    inserirFim(lista, 35);

    //Mostrar a lista até o momento.
    printf("\nLista após inserções: \n");
    mostrar(lista);

    //Remover elementos
    int x1 = removerInicio(lista);
    int x2 = remover(lista, 1);
    int x3 = removerFim(lista);
    int x4 = remover(lista, 0); //Remover o elemento da posição 0.

    //Mostrar os elementos removidos.
    printf("\nElementos removidos: %d, %d, %d, %d\n", x1, x2, x3, x4);

    //Mostrar a lista após as remoções.
    printf("\nLista após remoções: \n");
    mostrar(lista);

    //Liberar a memória alocada para a lista.
    free(lista->array); //Liberar o array de elementos.
    free(lista); //Liberar a estrutura da lista.

    return 0; 
}