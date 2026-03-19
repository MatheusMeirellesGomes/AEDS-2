/*Crie um método recursivo que recebe um número inteiro como parâmetro e retorna a soma de seus dígitos. Na saída padrão, para cada linha
de entrada, escreva uma linha de saída com o resultado da soma dos dígitos. Se a entrada for 12345 a saída deve ser 15.*/

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//Verificar se a string não é FIM. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

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
    //Inicializar Variáveis. 
    char str[100]; 
    int n; 

    //Ler a string. 
    scanf (" %[^\n]", str);

    //Loop. 
    while (!isFim(str)) {
        //Converter a string para inteiro. 
        n = atoi(str); //atoi é uma função da biblioteca stdlib.h que converte uma string para um inteiro.

        //Chamar a função recursiva 
        int resultado = somaDigitos(n);

        //Imprimir o resultado. 
        printf("%d\n", resultado);  

        //Ler a próxima string. 
        scanf (" %[^\n]", str);
    }

    return 0; 
}