//Este exercício é para ler um número inteiro do usuário e imprimi-lo. 

//Biblioteca para ler a entrada do usuário.  
import java.util.Scanner;

//Inicializar a classe com o mesmo nome que foi salvo no arquivo. 
public class Exercicio2 {
//Método principal onde o programa começa a execução.     
    public static void main(String[] args) {
        //Criar um objeto Scanner para ler a entrada do usuário. (como se fosse um scanf em C). 
        Scanner sc = new Scanner(System.in); 
        //Ler um número inteiro do usuário e armazená-lo na variável x. 
        int x = sc.nextInt(); //X vai receber o valor informado pelo usuário. 
        //Imprimir o valor de x. 
        System.out.println(x); //Como se fosse um printf em C. 
        sc.close(); //Fechar o scanner para evitar vazamento de memória. 
    }
}