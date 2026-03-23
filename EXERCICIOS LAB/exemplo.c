//Mesmo código de prova 1, porém agora usando o switch case, para trocar os caracteres de posição. 

#include <stdio.h> 
#include <stdlib.h> 

//Função para verificar o tamanho da string.
int tamanho (char str[]) {
    int i = 0; //Contador para o tamanho da string. 

    //Se não for fim da string. 
    while (str[i] != '\0') {
        i++; 
    }
    return i; //Retorna o tamanho da string.
}

//Função para decifrar a mensagem. 
void decifrar (char str[]) {
    //Loop
    for (int i = 0; i < tamanho(str); i++) {
        //Verificar o caractere atual e trocar pelo correspondente.
        switch (str[i]) {
            case '@':
                printf("a");
                break;
            case '&':
                printf("e");
                break;
            case '!':
                printf("i");
                break;
            case '*':
                printf("o");
                break;
            case '#':
                printf("u");
                break;
            default:
                printf("%c", str[i]);
        }
    }
}

//Main
int main() {
    char str[255]; 

    //Ler a primeira string. 
    while (fgets(str, 255, stdin) != NULL) { //Enquanto não chegar no fim do arquivo. 
        //Chamar a função para decifrar a mensagem.
        decifrar(str);
    }

    return 0;
}