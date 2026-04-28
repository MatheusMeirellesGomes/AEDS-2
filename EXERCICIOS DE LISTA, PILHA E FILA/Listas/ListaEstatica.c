/*Esse é um exercício de implementação de Lista Linear, um exercício básico de estrutra de dados, para a matéria de Lista de Aeds-2. 
usando os métodos inserirInicio, inserirFim, inserir, mostrar(), removerInicio, RemoverFim, remover.
As listas possuem elementos para inserção e remoção, sendo no inicio, qualquer posição e fim*/ 

#include <stdio.h> 
#include <stdlib.h> 

//Strucut de Lista estática. 
typedef struct {
    int array[6]; //Vetor de elementos. 
    int n; //Contador. (posição da lista)
}Lista; 

//Inicializar a Lista para indicar que está vazia.
void inicializa (Lista *lista) {
    lista->n = 0;
}

//Função Inserir no início da Lista. (InserirInicio)
void InserirInicio (Lista *lista, int elemento) {
    //Verificar se está cheia. 
    if (lista->n < 6) {
        //Se não estiver, deslocar os elementos para a direita. 
        for (int i = lista->n; i > 0; i--) {
            lista->array[i] = lista->array[i - 1]; //O elemento da posição i, recebe o elemento da posição i - 1 (anterior dele), e desloca-se para a direita.
        }

        //Inserir o elemento no início da lista e incrementar o contador.
        lista->array[0] = elemento; 
        lista->n++;
    }  else {
        //Exibir mensagem de erro. 
        printf("Erro: Lista Cheia!\n"); 
    }
}

//Função Inserir em uma posição específica da Lista. (Inserir)
void Inserir (Lista *lista, int elemento, int posicao) {
    //Verificar se é válida a posição e se a lista não está cheia.
    if (posicao >= 0 && posicao <= lista->n && lista->n < 6) {
        //Se tudo for válido, deslocar os elementos para a direita a partir da posição. 
        for (int i = lista->n; i > posicao; i--) {
            lista->array[i] = lista->array[i - 1]; 
        }

        //Inserir o elemento na posição desejada e incrementar o contador.
        lista->array[posicao] = elemento; //Inseiro o elemento na posição desejada do array.
        lista->n++;
    } else {
        //Exibir mensagem de erro. 
        printf("Erro: Posição Inválida ou Lista Cheia!\n");
    }
}

//Função Inserir no fim da Lista. (InserirFim)
void InserirFim (Lista *lista, int elemento) {
    //Verificar se a lista não está cheia. 
    if (lista->n < 6) {
        //Se não estiver, inserir o elemento no final da lista e incrementar o contador.
        lista->array[lista->n] = elemento; 
        lista->n++;
    } else {
        //Exibir mensagem de erro. 
        printf("Erro: Lista Cheia!\n"); 
    }
}

//Função para Remover do início da Lista. (RemoverInicio)
int RemoverInicio (Lista *lista) {
    //Variável para guardar o elemento removido.
    int elementoRemovido;

    //Verificar se a lista não está vazia. 
    if (lista->n > 0) {
        //Guardar o elemento a ser removido. 
        elementoRemovido = lista->array[0];

        //Se não estiver, deslocar os elementos para a esquerda. 
        for (int i = 0; i < lista->n - 1; i++) {
            lista->array[i] = lista->array[i + 1]; //O elemento da posição i, recebe o elemento da posição i + 1 (próximo dele), e desloca-se para a esquerda.
        }

        //Decrementar o contador. 
        lista->n--;
    } else {
        //Exibir mensagem de erro. 
        printf("Erro: Lista Vazia!\n"); 
    }
    
    //Retornar o elemento removido.
    return elementoRemovido;
}

//Função para Remover de uma posição específica da Lista. (Remover)
int Remover (Lista *lista, int posicao) {
    //Variável para guardar o elemento removido.
    int elementoRemovido; 
    //Verificar se a posição é válida e se a lista não está vazia. 
    if (posicao >= 0 && posicao < lista->n && lista->n > 0) {
        //Guardar o elemento removido. 
        elementoRemovido = lista->array[posicao];

        //Se tudo for válido. 
        for (int i = posicao; i < lista->n - 1; i++) {
            lista->array[i] = lista->array[i + 1];
        }

        //Decrementar o contador.
        lista->n--; 
    } else {
        //Exibir mensagem de erro. 
        printf("Erro: Posição Inválida ou Lista Vazia!\n"); 
    }

    return elementoRemovido;
}

//Função para Remover do fim da Lista. (RemoverFim)
int RemoverFim (Lista *lista) {
    //Variável para guardar o elemento removido.
    int elementoRemovido;

    //Verificar se a lista não está vazia. 
    if (lista->n > 0) {
        //Guardar o removido. 
        elementoRemovido = lista->array[lista->n - 1];

        //Decrementar o contador.
        lista->n--; 
    } else {
        //Exibir mensagem de erro. 
        printf("Erro: Lista Vazia!\n"); 
    }

    //Retornar o elemento removido.
    return elementoRemovido;
}
    
//Função para mostrar os elementos da Lista. (Mostrar)
void Mostrar (Lista *lista) {
    //Verificar se a lista não está vazia. 
    if (lista->n > 0) {
        //Se não estiver, exibir os elementos da lista. 
        printf("Elementos da Lista:\n"); 
        for (int i = 0; i < lista->n; i++) {
            printf("%d ", lista->array[i]);
        }
        printf("\n");
    }
}

//Função Principal. 
int main() {
    Lista lista; 

    //Chamar o inicializar. 
    inicializa(&lista); //Como lista é um ponteiro, passa apenas o endereço. 

    //testar as funções. 
    InserirInicio(&lista, 5); 
    InserirFim(&lista, 10); 
    InserirFim(&lista, 15);
    Inserir(&lista, 12, 1); //Inserir o 12 na posição 1.
    InserirInicio(&lista, 3); 

    printf("Lista após inserções:\n"); 
    Mostrar(&lista); 

    //Inicializar varáiveis para guardar os elementos removidos.
    int x1 = RemoverInicio(&lista);
    int x2 = Remover(&lista, 1); //Remover o elemento da posição 1.
    int x3 = RemoverFim(&lista);

    //Exibir os elementos removidos. 
    printf("Elementos removidos: \n%d, %d, %d\n", x1, x2, x3);

    Mostrar(&lista);

    return 0;
}