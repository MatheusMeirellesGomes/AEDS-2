//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

//Incluir bibliotecas necessárias. 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Função para verificar se a string é um palíndromo. 
bool palidromo(char texto[]) { //Passando como parâmetro a string a ser verificada. 
    //Inicializar os índices para comparar os caracteres da string, sendo i o índice do início da string e j o índice do final da string.
    int i = 0, j = strlen(texto) - 1; //Usar o strlen para obter o tamanho da string e subtrair 1 para obter o índice do último caractere. 
    //Enquanto o índice i for menor que o índice j, compara os caracteres da string. 
    while (i < j) {
        //Se a string tiver um caractere diferente, retorna false, indicando que não é um palíndromo. 
        if  (texto[i] != texto[j]) {
            return false; 
        }
        i++; //Incrementar o índice i para comparar o próximo caractere da string.
        j--; //Decrementar o índice j para comparar o próximo caractere da string.
    }
    return true; //Retorna verdadeiro se for palíndromo. 
}

//Função principal do programa.
int main() {
    //Inicializar variáveis. 
    char texto[1000]; //Array estático para armazenar a string de entrada. 

    //Loop para ler as linhas de entrada até que seja lida a palavra "FIM". 
    do {
        //Usar fgets para ler a linha de entrada e armazenar na variável str. Fgets é para ler string com espaços(frases). 
        fgets(texto, 1000, stdin); //Ler a string de entrada, salvando na variável texto, com tamanho máximo de 1000 caracteres e lendo da entrada padrão (stdin).
        texto[strcspn(texto, "\n")] = '\0'; //Remover o caractere de nova linha (\n) do final da string.

        //Verificar se é um palíndromo usando a função palidromo, mas não processar se for "FIM".
        if (strcmp(texto, "FIM") != 0) { //Se a string não for "FIM", verificar se é palíndromo.
            if (palidromo(texto)) { //Chamar a função palidromo para verificar se a string é um palíndromo. 
                printf("SIM\n"); //Se for um palíndromo, imprimir "SIM" na saída padrão. 
            } else {
                printf("NAO\n"); //Se não for um palíndromo, imprimir "NAO" na saída padrão. 
            }
        }
    } while (strcmp(texto, "FIM") != 0); //Usar a função strcmp para comparar a string de entrada com a palavra "FIM". O loop continua enquanto as strings forem diferentes.
}