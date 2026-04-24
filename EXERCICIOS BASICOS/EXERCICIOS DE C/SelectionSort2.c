//Código mais limpo e facilitado do Selection Sort. 
//Selection Sort é um algoritmo de ordenação que funciona selecionando o menor elemento de uma lista e trocando-o com o primeiro elemento, 
//depois selecionando o segundo menor elemento e trocando-o com o segundo elemento, e assim por diante, até que a lista esteja ordenada.

#include <stdio.h> 
#include <stdlib.h> 

//Criar um procedimento para realizar as trocas dos elementos do vetor.
void troca (int *a, int *b) {
    //Variável auxiliar. 
    int aux; 

    //Fazer trocas. 
    aux = *a; 
    *a = *b;    
    *b = aux; 
}

//Procedimento para realizar o Selection Sort. 
void SelectionSort (int vetor[], int n) { //Recebendo o vetor preenchido e o tamanho de vetor. 
    //Loop. 
    for (int i = 0; i < (n - 1); i++) {
        //Inicializar menor índice
        int menor = i; 

        //Segundo loop, comparando os elementos do vetor. 
        for (int j = (i + 1); j < n; j++) {
            //Comparação. 
            if (vetor[menor] > vetor[j]) menor = j; //Atualiza o menor. 
        }

        //Chamar o procedimento de troca, trocando o i com o menor. 
        troca(&vetor[i], &vetor[menor]); 
    }
}

int main() {
    //Inicializar variável. 
    int n; 

    //Receber tamanho. 
    scanf("%d", &n);

    //Criar vetor dinâmico.
    int *vetor = (int *)malloc(n * sizeof(int)); 

    //Loop 
    for (int i = 0; i < n; i++) {
        //Receber os elementos do vetor. 
        scanf("%d", &vetor[i]); 
    }

    //Chamar o procedimento de ordenação. 
    SelectionSort(vetor, n); //Passando o vetor preenchido e o tamanho do vetor. 

    printf("\nVetor Ordenado: \n");
    //Loop. 
    for (int i = 0; i < n; i++) {
        //Imprimir o vetor ordenado. 
        printf("%d ", vetor[i]);
    }

    return 0; 
}