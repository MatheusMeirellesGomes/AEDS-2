//Mesmo exercício do Ciframento de César, porém em C e iterativo. 

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//IsFim. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

//Função para cifrar a palavra. 
void Ciframento (char str[], char resultado[]) {
    //Inicializa contador. 
    int i = 0; 

    //Ver cada caractere. 
    while (str[i] != '\0') {
        //Adicionar +3 no caractere. 
        resultado[i] = str[i] + 3; 
        i++; 
    }

    //Adiciona o '\0' no final da string depois de cifrada.
    resultado[i] = '\0'; 
}

//Main. 
int main() {
    //Inicializar variável. 
    char str[100];  //Variável para string de entrada. 
    char strCifrada[100]; //variável para string de saída depois de cifrada. 

    //Ler primeira string. 
    scanf(" %[^\n]", str); 

    //Loop. Enquanto estiver diferente de FIM
    while (!isFim(str)) {
        //Vou chamar o procedimento.
        Ciframento(str, strCifrada); //Passando a inicial e a final.  

        //Vou imprimir a nova String depois de cifrada. 
        printf("%s\n", strCifrada);
        
        //Depois vou ler a próxima string e fazer tudo denovo. 
        scanf(" %[^\n]", str);
    }

    return 0; 
}