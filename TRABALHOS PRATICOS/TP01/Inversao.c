//Crie um método iterativo que recebe uma string como parâmetro e retorna a string invertida. Na saída padrão, para cada linha de entrada
//escreva uma linha com a saída da string invertida. Ex: Entrada = abcde então saída deve ser = edcba. 
//Obs: So pode usar as bibliotecas stdio.h e stdlib.h.

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

//Verificar se não é FIM a string. 
bool isFim (char str[]) { //Passando um vetor de char como parâmetro. 
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); //Verificando se a string é igual a FIM.
}

//Método para verificar o tamanho da string. 
int tamanho (char str[]) {
    //Inicializar variável com o valor da posição inicial do vetor. 
    int i = 0; 

    //Loop
    while (str[i] != '\0') { //Enquanto não chegar no final da string
        i++; //Incrementar o valor da variável para a próxima posição do vetor.
    }

    //Retornar o tamanho da string. 
    return i; 
}

//Função para inverter a string. 
void inverte (int tam, char str[]) { //Procedimento passando o tamanho da string e a string como parâmetros. 
    //Criar um vetor de char para armazenar a string invertida. 
    char invertida[tam + 1]; //Somar um, porque a string invertida precisa do caractere de fim de string.

    //Loop para inverter. 
    for (int i = tam - 1; i >= 0; i--) {
        invertida[tam - 1 - i] = str[i]; //Atribuir o valor da posição do vetor original para a posição do vetor invertido. 
    }

    //Adicionar o caractere de fim de string no final do vetor invertido. 
    invertida[tam] = '\0';

    //Copiar a string invertida para a string original.
    for (int i = 0; i <= tam; i++) {
        str[i] = invertida[i]; //Atribuir o valor da posição do vetor invertido para a posição do vetor original. 
    }
}

//Main. 
int main() {
    //Criar um vetor de char para armazenar a string. 
    char str[1000]; 

    //Ler a primeira string. 
    scanf(" %[^\n]", str); //Ler a string até encontrar o \n, ou seja, ler a linha inteira.

    //Loop para ler as strings até encontrar a string FIM. 
    while (!isFim(str)) { //Enquanto a string não for FIM e diferente de uma linha em branco.
        //Chamar o método para verificar o tamanho da string.
        int tam = tamanho(str);

        //Chamar o método para inverter a string.
        inverte(tam, str);

        //Imprimir a string invertida. 
        printf("%s\n", str);

        //Continuar lendo as próximas strings.
        scanf(" %[^\n]", str );
    }

    return 0; 
}