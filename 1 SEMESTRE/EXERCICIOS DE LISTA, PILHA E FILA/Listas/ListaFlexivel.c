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

//Inserir elemento em uma posição específica da lista.
void inserirPos (Lista *lista, int x, int pos) {
    //Se posição for 0, chamar método de inserir no início da lista.
    if (pos == 0) {
        inserirInicio(lista, x); //Passando a lista e o elemento a ser inserido.
    } else {
        //Criar nova célula.
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->elemento = x; //atribuição do elemento.

        //Criar célula auxiliar para percorrer a lista.
        Celula *aux = lista->inicio; 

        //Percorrer a lista até a posição desejada ou até o final da lista.
        for (int i = 0; i < pos - 1 && aux != NULL; i++) {
            aux = aux->prox; //Avançar para a próxima célula.
        }

        //Verificar se chegou na posição desejada e não chegou ao final da lista.
        if (aux != NULL) {
            //Inserir o novo elemento na posição desejada. 
            novo->prox = aux->prox; //O próximo do novo elemento aponta para o próximo da célula auxiliar.
            aux->prox = novo; //O próximo da célula auxiliar aponta para o novo elemento
        
            //Se a célula auxiliar for igual ao fim da lista
            if (aux == lista->fim) {
            lista->fim = novo; //O novo elemento passa a ser o fim da lista.
            }
        } else {
            printf("Posição inválida\n"); 
            free(novo); 
        }
    }
}

/*Quando o inserir na posição é chamado, um novo elemento é criado: novo->[elemento | prox] -> NULL
Cria-se uma célula auxiliar para percorrer a lista, com o elemento inicial apontando para o início da lista.
Percorre-se a lista até a posição desejada ou até o final da lista, avançando a célula auxiliar para a próxima célula.
Se a célula auxiliar não for NULL, ou seja, se chegou na posição desejada, o próximo do novo elemento aponta para o próximo da célula
auxiliar, e o próximo da célula auxiliar aponta para o novo elemento, inserindo o novo elemento na posição desejada.
Se a célula auxiliar for igual ao fim da lista, ou seja, se a posição desejada for o final da lista, o novo elemento passa a ser o fim da lista.
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
    //Variável para armazenar o elemento removido. 
    int elementoRemovido = 0; 

    //Se o início da lista tiver algum elemento. 
    if (lista->inicio != NULL) {
        elementoRemovido = lista->inicio->elemento; //Esse elemento vai ser removido. 

        //Criar célula auxiliar para armazenar o início da lista. 
        Celula *aux = lista->inicio; 
        
        //O início agora é o próximo elemento que o antigo início apontava, ou seja, o próximo elemento da lista.
        lista->inicio = lista->inicio->prox; 

        //Vou liberar a memória com a célula auxiliar, que tem o antigo início da lista. 
        free(aux);

        //Se após a remoção a lista ficou vazia.
        if (lista->inicio == NULL) {
            lista->fim = NULL; //O fim da lista também vai ser NULL. 
        }
    }
    
    //Retornar o elemento removido.
    return elementoRemovido;
}

//Remover de uma posição específica da lista.
int removerPos (Lista *lista, int pos) {
    //Variável para armazenar o elemento removido.
    int elementoRemovido = 0;
    
    //Se a posição for 0, chamar o método de remover do início da lista.
    if (pos == 0) {
        return removerInicio(lista); 
    } else {
        //Criar célula auxiliar para percorrer a lista.
        Celula *aux = lista->inicio;

        //Percorrer a lista até a posição desejada ou até o final da lista.
        for (int i = 0; i < pos - 1 && aux != NULL; i++) {
            aux = aux->prox; //Avançar para a próxima célula.
        }

        //Se a célula auxiliar não for NULL e o próximo da célula auxiliar também não for NULL, ou seja, se chegou na posição desejada e não chegou ao final da lista.
        if (aux != NULL && aux->prox != NULL) {
            //Criar célula auxiliar para armazenar a célula a ser removida, que é o próximo da célula auxiliar.
            Celula *tmp = aux->prox;
            int elementoRemovido = tmp->elemento; //O elemento a ser removido é o elemento da célula a ser removida.

            //O próximo da célula auxiliar passa a apontar para o próximo da célula a ser removida, ou seja, o próximo do próximo da célula auxiliar.
            aux->prox = tmp->prox;

            //Se a célula a ser removida for o fim da lista, ou seja, se o próximo da célula a ser removida for NULL, o novo fim da lista passa a ser a célula auxiliar.
            if (tmp->prox == NULL) {
                lista->fim = aux; 
            }

            //Liberar a memória da célula a ser removida.
            free(tmp);
        } else {
            printf("Posição inválida ou lista vazia!\n"); 
        }
    }

    //Retornar o elemento removido.
    return elementoRemovido;
}

//Remover do fim da lista.
int removerFim (Lista *lista) {
    int elementoRemovido; //Guardar o elemento removido. 

    //Se a lista não estiver vazia. 
    if (lista->inicio != NULL) {
        elementoRemovido = lista->fim->elemento; //O elemento a ser removido é o elemento do fim da lista.

        //Criar célula auxiliar para guardar o início da lista. inicio [elemento | prox] -> ... -> [elemento | NULL] <- fim.
        Celula *aux = lista->inicio; 

        //Percorrer até o penúltimo elemento da lista, o que aponta para o fim da lista.
        while (aux->prox != lista->fim) {
            aux = aux->prox; //Avançar para a próxima célula.
        }

        //Criar célula auxiliar para guardar o fim da lista, que é o elemento a ser removido.
        Celula *tmp = lista->fim; 
        lista->fim = aux; //O novo fim da lista, passa a ser a célula auxiliar, que é o penúltimo elemento da lista.
        lista->fim->prox = NULL; //O próximo do novo fim da lista é NULL. 

        //Liberar a memória da célula com o elemento removido, que é o antigo fim da lista.
        free(tmp);
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
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 10);
    inserirFim(&lista, 30);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 40);
    inserirFim(&lista, 50);
    inserirPos(&lista, 25, 3); 
    inserirPos(&lista, 15, 2);

    
    //Mostrar elementos depois de inserir
    printf("Elementos da Lista:\n");
    mostrar(&lista);

    //Remover elementos. 
    removerInicio(&lista);
    removerFim(&lista);
    removerPos(&lista, 2);
    removerPos(&lista, 0);

    //Mostrar elementos completos após as remoções.
    printf("Elementos da Lista após remoções:\n");
    mostrar(&lista);

    return 0;
}