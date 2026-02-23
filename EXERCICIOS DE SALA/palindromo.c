//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

//Incluir bibliotecas necessárias. 
#include <stdio.h>

//Função para verificar se a string é um palíndromo. 
int palidromo(char texto[], int tam) { //Passando como parâmetro a string a ser verificada e seu tamanho. 
    //Inicializar os índices para comparar os caracteres da string, sendo i o índice do início da string e j o índice do final da string.
    int i = 0, j = tam - 1; //j recebe o tamanho - 1 para obter o índice do último caractere. 
    //Enquanto o índice i for menor que o índice j, compara os caracteres da string. 
    while (i < j) {
        //Se a string tiver um caractere diferente, retorna false, indicando que não é um palíndromo. 
        if (texto[i] != texto[j]) {
            return 0; 
        }
        i++; //Incrementar o índice i para comparar o próximo caractere da string.
        j--; //Decrementar o índice j para comparar o próximo caractere da string.
    }
    return 1; //Retorna verdadeiro se for palíndromo. 
}

//Função principal do programa.
int main() {
    //Inicializar variáveis. 
    char texto[1000]; //Array estático para armazenar a string de entrada. 

    //Loop para ler as linhas de entrada até que seja lida a palavra "FIM". 
    while (fgets(texto, 1000, stdin)) {
        //Calcular tamanho e remover \n manualmente (mais rápido que strcspn)
        int tam = 0;
        while (texto[tam] != '\n' && texto[tam] != '\0') {
            tam++;
        }
        texto[tam] = '\0';
        
        //Verificar se é "FIM" manualmente (mais rápido que strcmp)
        if (tam == 3 && texto[0] == 'F' && texto[1] == 'I' && texto[2] == 'M') {
            break;
        }
        
        //Verificar se é palíndromo
        if (palidromo(texto, tam)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    
    return 0;
}