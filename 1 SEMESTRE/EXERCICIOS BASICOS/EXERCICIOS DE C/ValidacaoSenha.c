//Mesmo exercicio do tp de validação de senha porém agora fazendo em C. 

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

//Método isFim. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

//Verificar o tamanho da string. 
int tamanho (char str[]) {
    int i = 0; 

    //Enquanto i for diferente do fim da string. 
    while (str[i] != '\0') {
        i++; 
    }

    //Retorna o tamanho da string. 
    return i; 
}

//Verificar se têm letra maiúscula. 
bool temMaiuscula (char str[]) {
    //Inicializar tamanho como uma variável. 
    int n = tamanho(str); 

    //Loop para perorrer o tamanho da string. 
    for (int i = 0; i < n; i++) {
        //Verificar se é letra maiúscula. 
        if (str[i] >= 'A' && str[i] <= 'Z') { //Se tiver alguma letra maiúscula. 
            return true; 
        }
    }
    return false; 
}

//Verifica se tem minúscula. 
bool temMinuscula (char str[]) {
    //n recebe tamanho. 
    int n = tamanho(str); 

    //Loop. 
    for (int i = 0; i < n; i++) {
        //Verifica se têm minúscula. 
        if (str[i] >= 'a' && str[i] <= 'z') {//Se tiver alguma letra minúscula. 
            return true; 
        } 
    }
    return false; 
} 

//Verificar se tem número. 
bool temNumero (char str[]) {
    //Inicializa tamanho. 
    int n = tamanho(str); 

    //Loop
    for (int i = 0; i < n; i++) {
        //Verifica se têm número. 
        if (str[i] >= '0' && str[i] <= '9') {
            return true; 
        }
    }
    return false; 
}

//Verifica se tem caracter especial. 
bool temCaracter (char str[]) {
    //Inicializa 
    int n = tamanho(str); 

    //loop 
    for (int i = 0; i < n; i++) {
        //Verifica. 
        if ((str[i] >= '!' && str[i] <= '/') || (str[i] >= ':' && str[i] <= '@') || (str[i] >= '[' && str[i] <= '`') || (str[i] >= '{' && str[i] <= '~')) {
            return true; 
        }
    }
    return false;
}

//Verifica se a senha é válida: Ter min 8 digitos, letra maiúscula, minúscula, e caracter especial. 
bool isValida (char str[]) {
    //Inicializa. 
    int n = tamanho(str); 

    //Verifica se têm todos os requisitos. 
    if (n >= 8 && temMaiuscula(str) && temMinuscula(str) && temCaracter(str) && temNumero(str)){
        return true; 
    }
    return false;
}

//Main
int main () {
    //Inicializar variável. 
    char str[100]; 

    //Leitura da primeira variável. 
    scanf(" %[^\n]", str); 

    //Enquanto for diferente de isFim. 
    while (!isFim(str)) {
        //Chamar isValida e imprimir a resposta. 
        if (isValida(str)) {
            printf("SIM\n"); 
        }
        else {
            printf("NAO\n");
        }

        //Ler próxima string. 
        scanf(" %[^\n]", str); 
    }

    return 0; 
}