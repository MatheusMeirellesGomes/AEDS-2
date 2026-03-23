//Troca os caracteres da mensagem criptograda para decifrada.
//@ = a, & = e, ! = i, * = o, # = u. As entradas vem de um arquivo e termina com EOF. 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//Função para verificar o tamanho da string. 
int tamanho (char str[]) {
    int i = 0; //Contador para o tamanho da string.
    while (str[i] != '\0') { //Enquanto não chegar no final da string
        i++; //Incrementa o contador.
    }
    return i; //Retorna o tamanho da string.
}

//Função para decifrar a mensagem.
void decifrar (char str[]) {
    //Loop para trocar os caracteres. 
    for (int i = 0; i < tamanho(str); i++) {
        //Verificar qual é o caractere e trocar pelo correspondente.
        if (str[i] == '@') printf("a");
        else if (str[i] == '&') printf("e");
        else if (str[i] == '!') printf("i");
        else if (str[i] == '*') printf("o");
        else if (str[i] == '#') printf("u");
        else printf("%c", str[i]); 
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
