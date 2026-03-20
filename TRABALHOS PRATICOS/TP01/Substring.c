/*Crie um método iterativo que receba uma string como parâmetro e retorna o comprimeiro da substring mais longa sem caracteres repetidos.
 Na saída padrão, para cada linha de entrada, escreva uma linha de saída com o comprimento da substring mais longa sem repetição. 
 Ex: "abcabcbb" => 3 (substring "abc")*/

 #include <stdio.h> 
 #include <stdlib.h> 
 #include <stdbool.h> 

 //Verificar se não é FIM. 
 bool isFim (char str[]) {
    return (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0');
 }

 //Função para ver o tamanho da string.
 int tamanho (char str[]) {
    int i = 0; //Contador para o tamanho da string.
    while (str[i] != '\0') { //Enquanto não chegar no final da string
        i++; //Incrementa o contador.
    }
    return i; //Retorna o tamanho da string.
 }

 //Função para ver se tem algum caractere repetido na substring.
 bool temRepetido (char str[], int tam) {
    //Loop. 
    for (int i = 0; i < tam; i++) { //Percorre a substring como um todo. 
        for (int j = i + 1; j < tam; j++) { //Percorre a substring a partir do próximo caractere, para comparar com o caractere atual.
            if (str[i] == str[j]) { //Se tiver algum caractere repetido
                return true; //Retorna true.
            }
        }
        
    }
    return false; //Retorna false.
 }

 //Função para ver o comprimento da substring sem caracteres repetidos.
 int Substring (char str[]) {
    //Inicializar variável para guardar o tamanho da substring sem caracteres repetidos.
    int comprimento = 0; 

    //Loop para percorrer a string.
    for (int i = 0; i < tamanho(str); i++) { //Percorre a string como um todo.
        for (int j = i + 1; j <= tamanho(str); j++) { //Percorre a string a partir do próximo caractere, para comparar com o caractere atual.
            if (!temRepetido(str + i, j - i)) { //Se a substring não tiver caracteres repetidos
                if (j - i > comprimento) { //Se o comprimento da substring for maior que o comprimento atual
                    comprimento = j - i; //Atualiza o comprimento.
                }
            }
        }
    }
    return comprimento; //Retorna o comprimento da substring sem caracteres repetidos.
}

//Função principal.
int main() {
    //Inicializar variável para guardar a string. 
    char str[100]; 

    //Ler a string. 
    scanf (" %[^\n]", str);

    //Loop. 
    while (!isFim(str)) {
        //Chamar a funcão para ver o comprimento da substring sem caracteres repetidos e imprimir o resultado.
        int resultado = Substring(str);

        //Imprimir o resultado. 
        printf("%d\n", resultado);

        //Ler a próxima string. 
        scanf (" %[^\n]", str);
    }

    return 0;
}