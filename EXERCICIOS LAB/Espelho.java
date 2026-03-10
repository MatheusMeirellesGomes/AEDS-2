//Faça um programa em Java, que dados dois números inteiros, imprima a respectiva sequência do espelho. 
//Biblioteca para ler o teclado. (Receber dados do usuário)
import java.util.Scanner;

//Criar um classe espelho com o mesmo nome do arquivo. 
public class Espelho {
    //Criar um método principal onde o programa começa a execução. 
    public static void main(String[] args) {
        //Inicializar variáveis. 
        int num1, num2; 

        //Criar um objeto Scanner para ler a entrada do usuário. 
        Scanner sc = new Scanner (System.in); //Como um scanf em C.

        //Usar um loop para ler os números enquanto tiver número no arquivo de entrada.
        while (sc.hasNext()) { //hasNext() é um método da classe Scanner que retorna true se houver outro token (número, palavra, etc.) disponível para leitura. O loop continuará enquanto houver mais tokens para ler.
            //Ler números inteiros do usuário e armazená-los nas variáveis num1 e num2.
            num1 = sc.nextInt(); 
            num2 = sc.nextInt(); 
            
            //Criar uma variável String para armazenar o resultado do espelho dos números. 
            String sequencia = ""; //Inicializar a variável sequência como uma string vazia, para depois armazenar a sequência de números em ordem inversa.

            //Primeiro for para criar a sequência de números de num1 até num2.
            for (int i = num1; i <= num2; i++) { //O loop começa com o primeiro número, vai até o segundo inteiro, e incrementa i a cada iteração. 
                sequencia += i; //A cada iteração, i passa a ser uma string, e é concatenada com a variável sequência, que vai acumulando os números em ordem crescente.
            }

            //Imprimir a sequência de números de num1 até num2. 
            System.out.print(sequencia); //Imprime a sequência de números de num1 até num2, sem pular linha, para depois imprimir a sequência espelho na mesma linha.

            //Segundo for para criar a sequência de números de num2 até num1, ou seja, a sequência espelho (ordem inversa). 
            for (int i = sequencia.length() - 1; i >= 0; i--) { //i começa no último índice da string sequência (como começa em 0, o último índice é o comprimento da string menos 1), e vai até o primeiro índice (0), decrementando i a cada iteração.
                System.out.print(sequencia.charAt(i)); //A cada iteração, o caractere na posição i da string sequência é impresso, criando a sequência espelho (ordem inversa) dos números de num2 até num1.
            }

            //Pular linha após imprimir a sequência e a sequência espelho. 
            System.out.println(); //Pula linha para separar a saída de cada par de números lidos do usuário.
        }

        //Fechar o scanner para evitar vazamento de memória.
        sc.close(); 
    }
}
