/*Mesmo exercício 2 de java, porém em C.*/

//Struct para a Lista. 
typedef struct Lista {
    //Estrutura da Lista. 
    struct CelulaLista *inicio; 
    struct CelulaLista *fim; 
} Lista; 

//Struct para a Célula da Lista, cada nó. 
typedef struct CelulaLista {
    //Estrutura que cada nó da lista possui. 
    struct CelulaPilha *topo; 
    struct CelulaLista *prox; 
} CelulaLista; 

//Struct para a Célula da Pilha, cada nó 
typedef struct CelulaPilha {
    //Estrutura que cada nó da pilha possui. 
    int elemento; 
    struct CelulaPilha *prox; 
} CelulaPilha; 

CelulaLista *menorPilha(Lista *lista) {
    //Variável para armazenar a lista 
    CelulaLista *menor = lista->inicio; 
    int menorQntd = 0; 

    //Percorrer a primeira pilha para ter o contador como referência. 
    for (CelulaPilha *k = lista->inicio->topo; k != NULL; k = k->prox) {
        menorQntd++; //Saber quantidade de elementos da primeira pilha. 
    }

    //Percorrer a lista a partir da segunda pilha. 
    for (CelulaLista *i = lista->inicio->prox; i != NULL; i = i->prox) {
        //Contador atual para saber a quantidade de elementos de cada pilha. 
        int qntdAtual = 0; 

        //Percorrer a segunda pilha. 
        for (CelulaPilha *j = i->topo; j != NULL; j = j->prox) {
            qntdAtual++; 
        }

        //Verificar
        if (qntdAtual < menorQntd) {
            menorQntd = qntdAtual; 
            menor = i; 
        }
    }

    //Retornar o ponteiro da lista com a menor pilha. 
    return menor; 
}