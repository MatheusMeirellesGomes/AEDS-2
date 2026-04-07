//Código do soma dígitos porém em C e iterativo. 

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//IsFim. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

//Procedimento de somar os dígitos. 
int somaDigitos (int n) {
    //Variável de soma, para ter a resposta.
    int soma = 0; 

    //Loop para somar os dígitos. 
    while (n > 0) {
        soma += n % 10; //Resto da divisão por 10, que é o último dígito do número. 
        n /= 10; //Divisão inteira por 10, para remover o último dígito do número. 
    }
    return soma;
}

//Main
int main() {
    //Inicializar variáveis. 
    char str[100]; 
    int num; 

    //Ler a primeira string. 
    scanf(" %[^\n]", str);

    //Ler enquanto não for FIM. 
    while (!isFim(str)) {
        //Converte a string para número inteiro. 
        num = atoi(str); //atoi é uma função da biblioteca stdlib.h que converte uma string para um inteiro.

        //Chama a função. 
        int resultado = somaDigitos(num); 

        //Printa
        printf("%d\n", resultado);
        
        //Ler a próxima string. 
        scanf(" %[^\n]", str);
    }

    return 0; 
}