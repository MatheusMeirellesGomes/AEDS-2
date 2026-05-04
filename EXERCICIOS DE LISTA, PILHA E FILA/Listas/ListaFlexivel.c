/*Exercicio de Lista Flexível em C. 
Diferença da lista flexível para a estática, é que a flexível não possui deslocamento, ou seja, os elementos não precisam estar em posições
contíguas na memória. A lista flexível é implementada usando ponteiros, onde cada elemento (célula) aponta para o próximo elemento da lista.
*/

#include <stdio.h> 
#include <stdlib.h> 

//Struct para Célula (Nó da lista)
typedef struct Celula {
    int elemento; //Valor da célula.
    struct Celula *prox; //Ponteiro que aponta para a próxima célula. 
} Celula; 

/*
Struct para a Celula => Quando é criado o struct, está desse jeito: [elemento | prox] -> NULL. 
*/

//Struct para a Lista Flexível.
typedef struct {
    Celula *inicio; //Início da lista.
    Celula *fim; //Fim da lista.
} Lista;

/*
Struct para a Lista => Quando é criado o struct, fica desta forma: [inicio] e [fim]. 
*/

//Função para inicializar a lista. 
void inicializa (Lista *lista) {
    //Lista começa vazia, então ambos apontam para Null. 
    lista->inicio = NULL; 
    lista->fim = NULL;
}

/*
Depois do inicializar => [inicio] -> NULL e [fim] -> NULL. Início aponta para null e fim aponta para null, ou seja, lista vazia. 
*/

//Inserir elemento no início da lista. 
void inserirInicio (Lista *lista, int x) {
    //Nova célula. (novo elemento)
    Celula *novo = (Celula *)malloc(sizeof(Celula)); 

    //Atribuição do elemento.
    novo->elemento = x; 

    //O prox da nova celula aponta para o início da lista
    novo->prox = lista->inicio;

    //Atualizar o início da lista para a nova célula.
    lista->inicio = novo;

    //Se a lista estiver vazia, na hora de inserir o elemento. 
    if (lista->fim == NULL) { 
        lista->fim = novo; //Esse novo elemento, também vai apontar para o fim da lista, se tornando tanto o início quanto o fim da lista.
    }
}

/*
Quando o inserirInicio é chamado, é criado um novo elemento: novo->[elemento | prox] -> NULL. 
O novo->prox vai apontar pro início da lista, ou seja, o próximo do novo elemento é o antigo início da lista. 
Atualiza o início da lista para o novo elemento, ou seja, o início da lista agora aponta para o novo elemento.
Ex: Antes do inserirInicio => [inicio] -> NULL e [fim] -> NULL. Depois do inserirInicio(10) => [inicio] -> [10 | NULL] e [fim] -> [10 | NULL].
Se for chamado novamente o inserirInicio(20) => [inicio] -> [20] -> [10] -> NULL. => Início passa a ser 20 e o fim permanece 10. 
*/

//Inserir no fim da lista. 
void inserirFim (Lista *lista, int x) {
    //Nova célula. 
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    novo->elemento = x; //Atribuição do elemento.
    novo->prox = NULL; //O próximo da nova célula é NULL, pois será o último elemento.

    //Se a lista estiver vazia. 
    if (lista->inicio == NULL) {
        lista->inicio = novo; //O novo elemento também vai ser o início da lista. 
    } else {
        lista->fim->prox = novo; //Se não estiver vazia, o próximo do fim da lista (antigo último elemento) vai apontar para o novo elemento.
    }

    //Atualizar para que o novo elemento seja o fim da lista. 
    lista->fim = novo;
}

/*
Quando o inserirFim é chamado, é criado um novo elemento: novo->[elemento | prox] -> NULL.
O próximo elemento da fim da lista (novo->prox), vai ser NULL, pois é o último elemento da lista.
Verificar se a lista está vazia, e entrar, de acordo com a condição, na parte do if ou do else.
Se estiver vazia, o novo elemento vai ser tanto o início quanto o fim da lista. 
Se não estiver vazia, o antigo último elemento da lista, vai apontar pro novo, que vai passar a ser o novo fim da lista.
*/

/*
[inicio] -> NULL e [fim] -> NULL. => Lista vazia.
Exemplo com Lista vazia do inserir fim: Antes => inserirFim(10) => [inicio] -> [10 | NULL] <- [fim]. 
InserirFim(20) => [inicio] -> [10 | NULL] -> [20 | NULL] -> [fim].
*/

//Remover do início da lista.
int removerInicio (Lista *lista) {
    //Inicializar variável. 
    int elementoRemovido; 

    //Se a lista não estiver vazia, ou seja, se tiver algum elemento apontado pelo início da lista. 
    if (lista->inicio != NULL) {
        elementoRemovido = lista->inicio->elemento; //o elemento removido vai ser o elemento do início da lista. 

        //Necessário criar uma célula auxiliar armazenar o elemento que será removido. 
        Celula *aux = lista->inicio; 
        
        //Como foi o removido o antigo início da lista. O próximo elemento que o antigo da lista apontava, passa a ser o novo início da lista.
        lista->inicio = lista->inicio->prox; 

        //Liberar a memória da célula removida.
        free(aux);

        //Se após a remoção a lista ficou vazia.
        if (lista->inicio == NULL) {
            lista->fim = NULL; //O fim da lista também é atualizado para NULL. Concluindo que a lista está vazia. 
        }
    }
    
    //Retornar o elemento removido.
    return elementoRemovido;
}

//Remover do fim da lista.
int removerFim (Lista *lista) {
    int elementoRemovido; //Inicializar variável.

    //Ver se ta vazia
    if (lista->inicio != NULL) {
        //Guardar
        elementoRemovido = lista->fim->elemento; 

        //Criar célula auxiliar para percorrer a lista.
        Celula *aux = lista->inicio; 

        //Percorrer a lista até chegar na penúltima célula (antes do fim).
        while (aux->prox != lista->fim) {
            aux = aux->prox; //Avançar para a próxima célula.
        }

        //Atualizar o fim da lista para a célula auxiliar (penúltima).
        lista->fim = aux;
        lista->fim->prox = NULL; //O próximo do novo fim é NULL, pois é o último elemento.

        //Liberar a memória da célula removida.
        free(aux);
    }

    //Retornar o elemento removido.
    return elementoRemovido;
}

//Mostrar os elementos da lista. (Mostrar)
void mostrar (Lista *lista) {
    //Loop
    for (Celula *i = lista->inicio; i != NULL; i = i->prox) {
        printf("%d ", i->elemento); //Imprimir o elemento da célula atual.
    }
    printf("\n");
}

//Main
int main() {
    //Criar lista
    Lista lista; 

    //Chamar o inicializar
    inicializa(&lista); 

    //Inserir elementos
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFim(&lista, 30);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 40);
    inserirFim(&lista, 50);
    
    //Mostrar elementos depois de inserir
    printf("Elementos da Lista:\n");
    mostrar(&lista);

    //Remover elementos. 
    removerInicio(&lista);
    removerFim(&lista);

    //Mostrar elementos completos após as remoções.
    printf("Elementos da Lista após remoções:\n");
    mostrar(&lista);

    return 0;
}