/*Mesmo exercício de Lista Circular, porém agora na linguagem de java
Lista Circular = nem o início, nem o fim aponta pra null*/

#include <stdio.h> 
#include <stdlib.h> 

//Struct para Celula da lista
typedef struct Celula {
    //Atributos da célula
    int elemento; 
    struct Celula *ant; 
    struct Celula *prox; 
} Celula; 

//Struct para lista.
typedef struct Lista {
    //Atributos da lista
    Celula *inicio; 
    Celula *fim; 
} Lista; 

//Inicializar a lista
void inicializa(Lista *lista) {
    //Antes de inserir tanto o início, quanto o fim apontam para null 
    lista->inicio = NULL; 
    lista->fim = NULL; 
}

//Método para inserir no início da lista
void inserirInicio(Lista *lista, int x){
    //Criar nova célula pro novo elemento. 
    Celula *novo = (Celula *)malloc(sizeof(Celula)); 
    
    //Atribuir
    novo->elemento = x; 

    //Ver se a lista não está 
    if (lista->inicio == NULL) {
        //Atribuir ponteiros. Inicio e fim apontam para novo. 
        lista->inicio = novo;
        lista->fim = novo;
        
        //O próximo e o anterior apontam pro fim 
        novo->prox = lista->fim; 
        novo->ant = lista->inicio; 
    } else {
        //Atribuir
        novo->prox = lista->inicio; //O próximo do novo elemento aponta pro antigo início.  
        novo->ant = lista->fim; //O anterior do novo elemento aponta pro fim da lista
        lista->inicio->ant = novo; //O anterior do antigo fim aponta para o novo elemento.  
        lista->fim->prox = novo; //O próximo do fim aponta pro novo elemento. 
        lista->inicio = novo; //Início da lista é o novo elemento inserido. 
    }
}

//Método para inserir na posição desejada
void inserirPos(Lista *lista, int x, int pos) {
    //Se for na pos 0, chamar o inserir início. 
    if (pos == 0) {
        inserirInicio(lista, x); 
    } else { 
        //Criar nova célula pro novo elemento. 
        Celula *novo = (Celula *)malloc(sizeof(Celula)); 
        novo->elemento = x; 

        //Criar célula aux para percorrer a lista. 
        Celula *aux = lista->inicio; 
        for (int i = 0; i < pos - 1; i++) { //Percorre até o elemento anterior da pos informada. 
            aux = aux->prox; 
        }

        //Atribuir. 
        novo->prox = aux->prox; //O próximo elemento do novo aponta pro próximo que aux apontava
        aux->prox->ant = novo;  //O anterior do que aux apontava, aponta pro novo elemento 
        novo->ant = aux; 
        aux->prox = novo; 

        //Se o elemento inserido for no final do lista
        if (novo->prox == lista->inicio) {
            lista->fim = novo; //O fim é o novo elemento. 
            lista->inicio->ant = lista->fim; //Anterior do inicio aponta pro fim da lista
        }
    }
}

//Método para inserir no fim da lista
void inserirFim(Lista *lista, int x) {
    //Criar célula
    Celula *novo = (Celula *)malloc(sizeof(Celula)); 
    novo->elemento = x; 

    //Se o início da lista apontar para null, não tiver nada
    if (lista->inicio == NULL) {
        //Inicio e fim apontam pro novo elemento. 
        lista->inicio = novo; 
        lista->fim = novo; 

        //Anterior do novo aponta pro fim, próximo do novo aponta pro inicio. 
        novo->ant = lista->fim; 
        novo->prox = lista->inicio; 
    } else {
        lista->fim->prox = novo; //próximo do fim aponta pro novo elemento. 
        novo->ant = lista->fim; 
        novo->prox = lista->inicio; 
        lista->inicio->ant = novo; 
        lista->fim = novo; 
    }
}

//Método para remover do início da lista
int removerInicio(Lista *lista) {
    //Variável para guardar o elemento removido. 
    int elementoRemovido = 0; 

    //Se a lista não estiver vazia. 
    if (lista->inicio != NULL) {
        //Guardar o elemento removido
        Celula *tmp = lista->inicio; 

        //Elemento removido é o elemento inicial.
        elementoRemovido = lista->inicio->elemento; 
        //Se o elemento da lista for tanto o início quanto o fim. 
        if (lista->inicio == lista->fim) {
            lista->inicio = NULL; 
            lista->fim = NULL; 
        } else {
            lista->inicio = lista->inicio->prox; 
            lista->inicio->ant = lista->fim; 
            lista->fim->prox = lista->inicio; 
        }

        free(tmp); 
    }

    //Retornar
    return elementoRemovido; 
}

//Método para remover da pos desejada da lista
int removerPos(Lista *lista, int pos) {
    //Variável. 
    int elementoRemovido = 0;
    
    //Se for na pos 0, chamar o remover no início 
    if (pos == 0) {
        elementoRemovido = removerInicio(lista); 
    } else {
        //Célula para percorrer a lista
        Celula *aux = lista->inicio; 
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->prox; 
        }

        //Criar célula auxiliar para remover elemento
        Celula *tmp = aux->prox;
        elementoRemovido = tmp->elemento; 
        
        //Atribuir
        aux->prox = tmp->prox; 
        tmp->prox->ant = aux; 

        //Se o elemento removido for o último da lista
        if (tmp == lista->fim) {
            lista->fim = aux; 
            lista->fim->prox = lista->inicio; 
            lista->inicio->ant = lista->fim; 
        }

        //Liberar o elemento removido. 
        free(tmp); 
    }

    //Retornar
    return elementoRemovido; 
}

//Método para remover do fim da lista
int removerFim(Lista *lista) {
    //Variável
    int elementoRemovido = 0; 
    
    //Se a lista não estiver vazia
    if (lista->fim != NULL) {
        //Guardar elemento removido
        Celula *tmp = lista->fim; 
        elementoRemovido = lista->fim->elemento; 

        //Se so tiver um elemento. 
        if (lista->inicio == lista->fim) {
            //Ambas apontam pra null
            lista->inicio = NULL; 
            lista->fim = NULL; 
        } else {
            //Atribuir
            lista->fim = lista->fim->ant; 
            lista->fim->prox = lista->inicio; 
            lista->inicio->ant = lista->fim; 
        }

        free(tmp); 
    }

    return elementoRemovido; 
}

//Método para mostrar a lista
void mostrar(Lista *lista) {
    //Se a lista não estiver vazia
    if (lista->inicio != NULL) {
        //Célula auxliar para percorrer. 
        Celula *i = lista->inicio; 

        //Loop
        do {
            //Imprimir elementos da lista
            printf("%d ", i->elemento);
            i = i->prox; 
        } while (i != lista->inicio); 
        printf("\n"); 
    }
}

int main() {
    //Criar lista
    Lista lista; 

    //Chamar inicializa
    inicializa(&lista); 

    //Inserir alguns elementos.
    inserirInicio(&lista, 10); 
    inserirInicio(&lista, 5); 
    inserirFim(&lista, 20); 
    inserirPos(&lista, 15, 2); 
    inserirFim(&lista, 30); 
    inserirPos(&lista, 25, 4); 

    //Remover alguns elementos 
    removerInicio(&lista); 
    removerPos(&lista, 3); 
    removerFim(&lista); 

    //Imprimir a lista após remoções
    mostrar(&lista); 
}