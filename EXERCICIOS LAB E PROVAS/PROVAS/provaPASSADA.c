/*Mesma questao da prova 2 teórica, porém agora em vez de fazer o insertion sort, vai adicionar o inserirFim, para inserir um elemento 
no fim da lista.*/

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

void inserirFim(int x) {
    //Criar nova célula para o novo elemento que vai ser inserido.
    Celula *novo = novaCelula(x); //Chama o procedimento novaCelula

    //Criar célula para indicar o último elemento da lista, para ligar ele ao novo elemento
    Celula *ultimo = primeiro->ant; //Ultimo é o elemento final da lista

    //Verificar se a lista não está vazia
    if (primeiro != NULL) {
        //Fazer ligações. 
        ultimo->prox = novo; 
        novo->ant = ultimo; 
        novo->prox = primeiro; 
        primeiro->ant = novo; 
    }
}