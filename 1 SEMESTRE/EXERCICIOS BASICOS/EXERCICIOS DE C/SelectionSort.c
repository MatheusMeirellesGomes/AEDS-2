//Mesmo código do Selection Sort, mas na linguagem c. 

//Inicializar Bibliotecas.
#include <stdio.h>
#include <stdlib.h>

//Primeiro criar um procedimento para realizar as trocas dos elementos do vetor. 
void troca(int *a, int *b) {
    //Inicializar variável auxiliar. 
    int temp; 

    //Realizar a troca dos valores apontados por a e b utilizando a variável temp como auxiliar.
    temp = *a; 
    *a = *b; 
    *b = temp; 
}

//Criar um procedimento para realizar o Selection Sort. 
void selectionSort(int vetor[], int n) {
    //Primeiro Loop para percorrer o vetor do ínicio até o penúltimo elemento, pois o último elemento já estará ordenado após o processo de ordenação.
    for (int i = 0; i < (n - 1); i++) {
        //Inicializar variável para armazenar o índice de menor elemento encontrado, começando com o índice atual i.
        int menor = i; 

        //Segundo Loop para percorrer os elementos do vetor a partir do próximo elemento (i + 1) até o final do vetor, comparando cada elemento com o elemento no índice de menor.
        for (int j = (i + 1); j < n; j++) {
            //Verificar se o menor elemento encontrado é maior do que o elemento atual do segundo loop.
            if (vetor[menor] > vetor[j]) {
                menor = j; //Atualizar o índice de menor elemento encontrado para o índice j, se o elemento no índice j for menor do que o elemento no índice de menor.
            }
        }
        
        //Realizar a troca dos elementos no índice i e no índice de menor.
        troca(&vetor[i], &vetor[menor]); //Chamar a função de troca passando os endereços dos elementos no índice i e no índice de menor para realizar a troca dos valores.
    }
}

//Criar a função principal para testar o procedimento de ordenação.
int main() {
    //Inicializar variável para armazenar o tamanho do vetor. 
    int n; 

    //Receber dados. 
    printf("Digite quantos elementos tem o vetor: "); 
    scanf("%d", &n); 

    //Criar um vetor dinâmico para armazenar os elementos do vetor, alocando memória suficiente para n inteiros.
    int *vetor = (int *)malloc(n * sizeof(int)); 

    //Loop para ler os elementos do vetor a partir da entrada do usuário, armazenando cada elemento no vetor. 
    for (int i = 0; i < n; i++) {
        //Informar os elementos do vetor. 
        printf("Informe o elemento %d do vetor: ", i + 1); 
        scanf("%d", &vetor[i]);
    }

    //Chamar o procedimento de ordenaçã para ordenar o vetor utilizando o Selection Sort. 
    selectionSort(vetor, n);

    //Loop para imprimir os elementos do vetor ordenado, percorrendo o vetor do início ao fim e imprimindo cada elemento.
    printf("Vetor Ordenado: "); 
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]); 
    }

    //Liberar a memória alocada para o vetor dinâmico, evitando vazamentos de memória.
    free(vetor);

    return 0; 
}

