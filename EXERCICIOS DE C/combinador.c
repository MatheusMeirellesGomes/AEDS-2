//Mesmo exercício da pasta de laboratório, porém agora alocando dinâmicamente as strings.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criar um procedimento para combinar as strings
void combina (char *str1, char *str2, char *resultado) {
    //inicializar variáveis para armazenar os índices de resultado
    int i = 0, j = 0, k = 0;

    //Loop para combinar as strings, alternando as letras de cada string enquanto ambos os índices i e j forem menores que o comprimento dos respectivos strings
    while (i < strlen(str1) && j < strlen(str2)) {
        //Adicionar a letra da primeira e segunda string ao resultado e incrementar o índice i e j.
        resultado[k++] = str1[i++]; 
        resultado[k++] = str2[j++]; 
    }

    //Loop para adicionar as letras restantes da string mais longa ao resultado, caso a primeira string seja mais longa. 
    while (i < strlen(str1)) {
        resultado[k++] = str1[i++]; 
    }

    //Loop para adicionar as letras restantes da string mais longa ao resultado, caso a segunda string seja mais longa.
    while (j < strlen(str2)) {
        resultado[k++] = str2[j++]; 
    }

    //Adicionar o caractere nulo ao final da string resultante para indicar o fim da string.
    resultado[k] = '\0';
}

//Criar a função principal
int main() {
    //Inicializar dinâmicamente as variáveis para armazenar as strings de entrada e a string resultante. 
    char *str1 = (char *)malloc(100 * sizeof(char));
    char *str2 = (char *)malloc(100 * sizeof(char));
    char *resultado = (char *)malloc(200 * sizeof(char));

    //Loop para ler as entradas vindas de um arquivo.
    while (scanf("%s %s", str1, str2) != EOF) { //Enquanto tiver lendo as linhas de entrada.
        combina(str1, str2, resultado);
        printf("%s\n", resultado);
    }

    //Liberar a memória alocada para as strings. 
    free(str1); 
    free(str2); 
    free(resultado); 

    return 0; 
}
