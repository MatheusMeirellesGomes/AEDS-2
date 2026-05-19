//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

//Incluir bibliotecas necessárias. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Função para o FIM do código. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

//Função para o tamanho da string. 
int tamanho (char str[]) {
    int i = 0; //Contador para o tamanho da string.
    while (str[i] != '\0') { //Enquanto não chegar no final da string
        i++; //Incrementa o contador.
    }
    return i; //Retorna o tamanho da string.
}

//Função para ver se é palíndromo. 
bool isPalindromo (char str[]) {
    //Inicializar o tamanho. 
    int n = tamanho(str); 

    //Loop. 
    for (int i = 0; i < n / 2; i++) { //Do primeiro caractere até a metade da string, comparando o caractere atual com o correspondente do outro lado da string.
        if (str[i] != str[n - i - 1]) { //Se o caractere atual for diferente do caractere correspondente do outro lado da string
            return false; 
        }
    }
    return true; 
}

//Função Principal. 
int main() {
    //Inicializar variável. 
    char str[100]; 

    //Ler a primeira string. 
    scanf (" %[^\n]", str);

    //Loop. 
    while (!isFim(str)) {
        //Verificar se é palíndromo. 
        if (isPalindromo(str)) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }

        //Ler a próxima string.
        scanf (" %[^\n]", str);
    }
    return 0; 
}