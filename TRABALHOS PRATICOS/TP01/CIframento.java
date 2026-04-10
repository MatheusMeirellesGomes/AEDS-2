//Questão sobre o ciframento de césar. A ideia básica é um simples deslocamento de caracteres. Assim, por exemplo, se a chave utilizada para criptografar as mensagens 
// for 3, todas as ocorrencias do caractere ’a’ sao substituıdas pelo caractere ’d’, as do ’b’ por ’e’, e assim sucessivamente. 
// Crie um metodo iterativo que recebe uma string como parˆametro e retorna outra contendo a entrada de forma cifrada. Neste exercıcio, suponha a chave de 
// ciframento tres. Na saıda padrao, para cada linha de entrada, escreva uma linha com a mensagem criptografada.
//Obs: As entradas vem de um arquivo de texto pub.in e as saídas devem ser escritas em um arquivo de texto pub.out. 

import java.util.Scanner; 

//Criar a classe Ciframento. 
public class Ciframento{
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

    //Criar um método para verificar se aultima string é FIM, ou seja, se a string lida é igual a "FIM".
    public static boolean isFIM (String str) {
        //Verificar se a string lida é igual a "FIM". Lembrando que nao pode usar equals, e nem break no if, e apenas um return em cada procedimento. 
        return str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M';
    }

    //Método principal. 
    public static void main (String [] args) {
        //Criar um objeto Scanner para ler a entrada do arquivo de texto pub.in. 
        Scanner sc = new Scanner(System.in); 

        //Ler a primeira linha do arquivo de texto pu.in. 
        String linha = sc.nextLine();

        //Continuar lend cada linha do arquivo, enquanto a linha lida nao for "FIM". 
        while (!isFIM(linha)) { 
            //Chamar o método de ciframento para cifrar a linha lida.
            String linhaCifrada = ciframento(linha); 

            //Imprimir a linha cifrada. 
            System.out.println(linhaCifrada); //Imprimir a linha cifrada usando o método println da classe MyIO.

            //Ler a proxima linha para a proxima iteracao do loop.
            linha = sc.nextLine();
        }

        //Fechar o objeto Scanner. 
        sc.close(); 
    }
}



