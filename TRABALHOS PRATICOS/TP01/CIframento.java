//Questão sobre o ciframento de césar. A ideia básica é um simples deslocamento de caracteres. Assim, por exemplo, se a chave utilizada para criptografar as mensagens 
// for 3, todas as ocorrencias do caractere ’a’ sao substituıdas pelo caractere ’d’, as do ’b’ por ’e’, e assim sucessivamente. 
// Crie um metodo iterativo que recebe uma string como parˆametro e retorna outra contendo a entrada de forma cifrada. Neste exercıcio, suponha a chave de 
// ciframento tres. Na saıda padrao, para cada linha de entrada, escreva uma linha com a mensagem criptografada.
//Obs: As entradas vem de um arquivo de texto pub.in e as saídas devem ser escritas em um arquivo de texto pub.out. 

import java.util.Scanner; 

//Criar a classe Ciframento. 
class Ciframento{
    //Criar primeiramente um método iterativo que receba uma string como parâmetro e retorne outra contendo a entrada de forma cifrada. 
    public static String ciframento (String str) {
        //Criar uma string vazia para armazenar a mensagem cifrada. 
        String cifrada = ""; //Dentro dela vamos iterar sobre cada caracterer da string de entrada. 

        //Loop para percorrer cada caracter da string de entrada. 
        for (int i = 0; i < str.length(); i++) {
            //Obter o caracter atual, ou seja, o caracter na posição i da string de entrada.
            char caracter = str.charAt(i); //Vai primeiro analisar o caracter na posição inicial dele.
            char novoCaracter = (char) (caracter + 3); //O novo caracter é o resultado da soma do caracter atual com a chave de ciframento, que é 3.
            cifrada += novoCaracter; //Adicionar o novo caracter à string cifrada.
        }

        //Retornar a string cifrada. 
        return cifrada; 
    }

    //Método principal. 
    public static void main (String [] args) {
        //Criar um objeto Scanner para ler a entrada do arquivo de texto pub.in. 
        Scanner sc = new Scanner(System.in); 

        //Ler cada linha do arquivo pub.in e aplicar o método de ciframento a cada linha. 
        while (sc.hasNextLine()) {
            //Ler a linha atual do arquivo de texto. 
            String linha = sc.nextLine(); 

            //Aplicar o método de ciframento a linha lida. 
            String linhaCifrada = ciframento(linha); 

            //Escrever a linha cifrada no arquivo de texto pub.out. 
            System.out.println(linhaCifrada); //Imprimir a linha cifrada na saída padrão.
        }

        //Fechar o objeto Scanner. 
        sc.close(); 
    }
}



