/*Crie um método recursivo que recebe um número inteiro como parâmetro e retorna a soma de seus dígitos. Na saída padrão, para cada linha
de entrada, escreva uma linha de saída com o resultado da soma dos dígitos. Se a entrada for 12345 a saída deve ser 15.*/

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//Funcão recursiva. 
int somaDigitos (int n) {
    //caso base. 
    if (n == 0) {
        return 0; 
    }
    else {
        //Chama recursiva
        return (n % 10) + somaDigitos(n / 10); //Resto da divisão por 10 + chamada recursiva com o número dividido por 10, até chegar no caso base. 
    }
}

int main() {
    //Inicializar Variável. 
    int num; 

    //Loop. 
    while (scanf("%d", &num) == 1) { //Enquanto conseguir ler um número inteiro, continua o loop. 
        //Chamar a função. 
        int resultado = somaDigitos(num); 

        //Printar.
        printf("%d\n", resultado);
    }
    return 0; 
}