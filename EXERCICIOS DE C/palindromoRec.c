//Mesmo exercicio do palíndromo, mas utilizando recursão. 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Primeiro fazer uma função recursiva para verificar se a string é um palíndromo. 
bool ehPalindromo (char texto[], int inicio, int fim) {
    //Verificar caso base da recursão, se o início for maior ou igual ao fim, significa que a string é um palíndromo, porque todos os caracteres foram comparados e são iguais.
    if (inicio >= fim) {
        return true; //Retorna true, indicando que a string é um palíndromo. 
    }

    //Verificar se os caracteres em cada posição de início e fim são diferentes. 
    if (texto[inicio] != texto[fim]) {
        return false;
    }

    //Chamar a função recursivamente, comparando os próximos caracteres da string, incrementando o índice de início e decrementando o índice de fim.
    return ehPalindromo(texto, inicio + 1, fim - 1); //início é incrementado (vai da pos 0 para a direita) e fim é decrementado (vai da pos final para a esquerda).
}

int main() {
    //Inicializar variável. 
    char texto[1000]; //Array estático. Se fosse dinâmico, seria char *texto = malloc(1000 * sizeof(char)); 

    //Loop para ler as linhas de entrada até que seja lida a palavra "FIM". 
    while (fgets(texto, 1000, stdin)) { //Enquanto tiver lendo as linhas de entrada (função do fgets = ler tudo até o \n). 
        //Inicializar tamanho como 0 para calcular o tamanho da string de entrada. 
        int tam = 0; 

        //Loop para calcular o tamanho da string de entrada, contando os caracteres até encontrar o caractere de nova linha '\n' ou o caractere nulo '\0'.
        while (texto[tam] != '\n' && texto[tam] != '\0') {
            tam++;
        }
        //Chamar a função recursiva para verificar se a substring é um palíndromo.
        if (ehPalindromo(texto, 0, tam - 1)) { //Mandar a string, índice de início (0), índice de fim (tamanho - 1). 
            printf("SIM\n"); 
        } 
        else {
            printf("NAO\n"); 
        }
    }

    return 0; 
}