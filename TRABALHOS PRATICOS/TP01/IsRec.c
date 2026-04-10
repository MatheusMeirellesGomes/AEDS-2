//Mesma questão do Is.java, porém agora em C e utilizando recursão. 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

//Verificar FIM. 
bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'); 
}

//Verifica Vogal. 
bool isVogal (char str[], int i) {
    //Caso base. 
    if (str[i] == '\0') //Se for igual ao fim da String. 
        return true;

    //Verificar se é vogal. 
    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') { //Se tiver algo diferente de vogal, retorna falso. 
        return false;
    } 
        
    //Chama a função e avança.
    return isVogal(str, i + 1); 

    
}

//Verifica Consoante. . 
bool isConsoante (char str[], int i) {
    //Caso base. 
    if (str[i] == '\0') {
        return true; 
    }

    //Verificar se não é número. 
    if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) { //Se tiver algo diferente de letra, retorna falso. 
        return false;
    }

    //Verificar se têm vogal. 
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') { //Se tiver algo diferente de consoante, retorna falso. 
        return false;
    }

    //Chama a função e avança. 
    return isConsoante(str, i + 1); 

}

//Verifica Inteiro. 
bool isInteiro (char str[], int i) {
    //Caso base. 
    if (str[i] == '\0') //Se for igual ao fim da String. 
        return true; 

    //Verificar se é número
    if (!(str[i] >= '0' && str[i] <= '9')) { //Se tiver algo diferente de número, retorna falso. 
        return false;
    } 

    //Chama a função e avança.
    return isInteiro(str, i + 1); //Chama a função recursivamente, e avança para o próximo caractere.
}

//Verifica Real. 
bool isReal (char str[], int i) {
    //Caso base. 
    if (str[i] == '\0') 
        return true; 

    //Verificar se é número e se tem ponto ou vírgula. 
    if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' && str[i] != ',') //Se  tiver diferente de número, ponto
        return false; 

    //Chama a função e avança.
    return isReal(str, i + 1); //Chama a função recursivamente, e avança para o próximo caractere.
}

//Função Principal.
int main() {
    char str[1000]; 

    //Ler a primeira string. 
    scanf(" %[^\n]", str);

    while (!isFim(str)) {
        //Saida. 
        printf("%s %s %s %s\n",
               isVogal(str, 0) ? "SIM" : "NAO",
               isConsoante(str, 0) ? "SIM" : "NAO",
               isInteiro(str, 0) ? "SIM" : "NAO",
               isReal(str, 0) ? "SIM" : "NAO");

        //Ler a próxima string. 
        scanf(" %[^\n]", str);
    }

    return 0; 
}