//Implemente um programa que receba duas strings e combine-as, alternando as letras de cada string, começando com a primeira letra da primeira string, seguido 
//pela letra da segunda string, em seguida pela segunda letra da primeira string, seguido pela letra da segunda string, e assim por diante. 
//As letras restante da string mais longa devem ser adicionadas ao final da string resultante e retornada. 

#include <stdio.h> 
#include <string.h> 

//Criar um procedimento para combinar as strings
void combinaString(char *str1, char *str2, char *resultado) {
    //Inicializar variáveis para armazenar os índices de cada string e o índice do resultado. 
    int i = 0, j = 0, k = 0; 

    //Loop para combinar as strings, alternando as letras de cada string enquanto ambos os índices i e j forem menores que o comprimento dos respectivos strings.
    while (i < strlen(str1) && j < strlen(str2)) { //enquanto i for menor que o comprimento da primeira string e j for menor que o comprimento da segunda string, ou seja, enquanto ambos os índices estiverem dentro dos limites das strings.
        //Adicionar a letra da primeira e segunda string ao resultado e incrementar o índice i e j.. 
        resultado[k++] = str1[i++]; 
        resultado[k++] = str2[j++]; 
    }

    //Loop para adicionar as letras restantes da string mais longa ao resultado, caso a primeira string seja mais longa. 
    while (i < strlen(str1)) { //Enquanto i for menor que o comprimento da primeira string, ou seja, enquanto o índice i estiver dentro dos limites da primeira string.
        resultado[k++] = str1[i++]; 
    }

    //Loop para adicionar as letras restantes da string mais longa ao resultado, caso a segunda string seja mais longa. 
    while (j < strlen(str2)) { //Enquanto j for menor que o comprimento da segunda string, ou seja, enquanto o índice j estiver dentro dos limites da segunda string.
        resultado[k++] = str2[j++]; 
    }

    //Adicionar o caractere nulo ao final da string resultante para indicar o fim da string. 
    resultado[k] = '\0';
}

//Criar a função principal
int main() {
    //Inicializar variáveis para armazenar as strings de entrada e a string resultante. 
    char str1[100], str2[100], resultado[200]; 

    //Loop para ler as entradas vindas de um arquivo. 
    while (scanf("%s %s", str1, str2) != EOF) { //Enquanto tiver lendo as linhas de entrada. 
        //Combinar as strings
        combinaString(str1, str2, resultado); //Como eu coloquei como ponteiro na função de combinação, eu nao preciso passar usando &, passa apenas as variáveis str1, str2 e resultado, que já são arrays (strings) e são passados como ponteiros para a função de combinação.

        //Imprimir a string resultante da combinação das duas strings. 
        printf("%s\n", resultado); 
    }

    return 0; 
}