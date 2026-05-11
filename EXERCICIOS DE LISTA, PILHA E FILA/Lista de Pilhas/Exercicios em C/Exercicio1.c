/*Considere uma estrutura de Lista de Pilhas. Crie o método CelulaLista maiorPilha() na classe ListaPilha, que retorna a célula da Lista
que aponta para a pilha com o maior número de elementos. Caso tenham pilhas do mesmo tamanho, retornar a primeira que aparece
Agora na linguagem C. */

#include <stdio.h> 
#include <stdlib.h> 

//Strcut para Lista
typedef struct Lista {
    //Atributos da classe Lista. 
    struct CelulaLista *inicio; 
    struct CelulaLista *fim; 
} Lista; 

//Struct para Célula da lista. 
typedef struct CelulaLista {
    //Atributos de cada célula da Lista. 
    struct CelulaPilha *topo; 
    struct CelulaLista *prox; 
} CelulaLista;

//Struct para Célula da Pilha. 
typedef struct CelulaPilha {
    //Atributos de cada célula da Pilha. 
    int elemento; 
    struct CelulaPilha *prox; 
} CelulaPilha;

//Função para criar a CelulaLista maiorPilha()
CelulaLista maiorPilha(Lista *lista) {
    //Criar variáveis para armazenar a maior pilha e o número de elementos. 
    CelulaLista *maior = NULL; 
    int maiorQntd = 0; 

    //Percorrer primeira a lista
    for (CelulaLista *i = lista->inicio; i != NULL; i = i->prox) {
        //Variável para a quantidade atual de elementos de cada PILHA. 
        int qntdAtual = 0; 

        //Percorrer cada posição da Pilha para saber quantos elementos a pilha tem
        for (CelulaPilha *j = i->topo; j != NULL; j = j->prox) {
            //Atualizar contador enquanto o próximo do elemento atual for diferente de null
            qntdAtual++; 
        }

        //Verificar se a quantidade atual da pilha é maior que a maior quantidade salva até agora
        if (qntdAtual > maiorQntd) {
            maiorQntd = qntdAtual; 
            maior = i; 
        }
    }

    return *maior; 
}