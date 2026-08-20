/*Exercício de árvore simples, em C, para treinamento da linguagem*/

#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>

//Struct para cada nó da árvore
typedef struct No{
    //atributos de cada nó
    int elemento; 
    struct No *esq; 
    struct No *dir; 
} No; 

//Construtor para o nó 
No *novoNo (int x) {
    //Alocar dinamicamente um espaço pro novo nó que vai ser criado.
    No *novo = (No *)malloc(sizeof(No)); 

    //Atribuir
    novo->elemento = x;
    novo->esq = NULL; 
    novo->dir = NULL; 
    
    //Retornar o novo nó
    return novo; 
}

//Struct para árvore
typedef struct Arvore {
    No *raiz; 
} Arvore; 

//Construtor para árvore
void construtor(Arvore *arvore) {
    //Atribuir raiz como nulla. 
    arvore->raiz = NULL; 
}

//Método para inserir um elemento.
No *inserir(No *i, int x) {
    //Se a árvore estiver vazia
    if (i == NULL) {
        i = novoNo(x); 
    } 

    //Se for menor
    else if (x < i->elemento) {
        i->esq = inserir(i->esq, x); //Inserir a esquerda da raiz
    }

    //Se for maior
    else if (x > i->elemento) {
        i->dir = inserir(i->dir, x); 
    }

    return i; 
}

//Método para pesquisar um elemento 
bool pesquisar(No *i, int x) {
    //Se estiver vazia
    if (i == NULL) {
        return false; //retorna falso
    } 

    //Se a raiz for o elemento
    else if (x == i->elemento) {
        return true; //retornar verdadeiro
    }

    //Se for menor que a raiz
    else if (x < i->elemento) {
        return pesquisar(i->esq, x); //pesquisar elemento na esquerda da raiz
    }

    //Se for maior que a raiz
    else {
        return pesquisar(i->dir, x); //pesquisar elemento na direita da raiz
    }
}

//Método para imprimir pré-Ordem
void preOrdem (No *i) {
    //Se a árvore nao estiver vazia
    if (i != NULL) {
        printf("%d ", i->elemento); //imprimir a raiz
        preOrdem(i->esq); //imprimir os da esquerda
        preOrdem(i->dir);
    }
}

//Método para imprimir em-Ordem
void emOrdem (No *i) {
    //Se não estiver vazia
    if (i != NULL) {
        emOrdem(i->esq); //imprimir os da esquerda
        printf("%d ", i->elemento); //imprimir a raiz
        emOrdem(i->dir); //imprimir os da direita
    }
}

void posOrdem (No *i) {
    if (i != NULL) {
        posOrdem(i->esq); //imprimir os da esquerda
        posOrdem(i->dir); //imprimir os da direita
        printf("%d ", i->elemento); //imprimir a raiz
    }
}

//Main
int main() {
    //Criar árvore. (Como é struct normal, usa-se '.', se fosse Arvore *arvore, usaria '->')
    Arvore arvore; 

    //Inicializar árvore mandando o endereço para o construtor
    construtor(&arvore); 

    //Inserir elementos.
    arvore.raiz = inserir(arvore.raiz, 50);
    arvore.raiz = inserir(arvore.raiz, 30);
    arvore.raiz = inserir(arvore.raiz, 70);
    arvore.raiz = inserir(arvore.raiz, 20);
    arvore.raiz = inserir(arvore.raiz, 40);
    arvore.raiz = inserir(arvore.raiz, 60);
    arvore.raiz = inserir(arvore.raiz, 80);

    //Imprimir pré ordem
    arvore.preOrdem(arvore.raiz); 
    printf("\n"); 

    //Imprimir em ordem
    arvore.emOrdem(arvore.raiz);
    printf("\n"); 

    //imprimir pós ordem
    arvore.posOrdem(arvore.raiz); 
    printf("\n"); 

    //pesquisar elemento na árvore
    if (pesquisar(arvore.raiz, 40)) {
        printf("Elemento 40 encontrado\n"); //se tiver
    } else {
        printf("Elemento 40 nao encontrado\n"); //se não tiver
    }

    //pesquisar elemento
    if (pesquisar(arvore.raiz, 100)) {
        printf("Elemento 100 encontrado\n");
    } else {
        printf("Elemento 100 nao encontrado\n");
    }

    return 0; 
}