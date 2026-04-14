//Mesmo exercício do Ciframento de César porém agora em C e utilzando o método recursivo. 

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

//Ver se a string é FIM.
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0');
}

//Função recursiva para cifrar a string. 
void cifrada (char str[], int i) {
    //Caso base. 
    if (str[i] == '\0') {
        return; 
    }
    
    //Processar o caractere atual.
    str[i] = (char)(str[i] + 3); //Cifra o caractere atual, somando 3 ao seu valor ASCII.

    //Chamada recursiva para o próximo caractere.
    cifrada(str, i + 1); //Chama a função recursiva para o próximo caractere, incrementando o índice i.
}

//Remover o \n. 
void removeEnter (char str[]) {
    //Inicializar contador. 
    int i = 0; 

    //loop. 
    while (str[i] != '\0' && str[i] != '\n') {
        i++; //Enquanto nao tiver chegado no final da string ou no \n, incrementa o contador. 
    }

    //Substituir o \n 
    if (str[i] == '\n') {
        str[i] = '\0'; //Quando chegar no \n, trocar por \0. 
    }
}

//Main
int main() {
    //Inicializar variável para a string.
    char str[1300]; 

    //Ler a string. 
    fgets(str, 1300, stdin);

    //Remover \n
    removeEnter(str); //Chamada da função. 

    //Loop
    while (!isFim(str)) {
        //Chamar a função recursiva para cifrar a string.
        cifrada(str, 0); //Chama a função recursiva para cifrar a string, começando pelo índice 0.

        //Imprimir a string cifrada.
        printf("%s\n", str); 

        //Ler a próxima string.
        fgets(str, 1300, stdin);

        //Remover \n
        removeEnter(str); 
    }

    return 0; 
}