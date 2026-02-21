//Exercicio para verificar se um número é positivo ou negativo. (Uso do If-ELse em java).
import java.util.Scanner; //Biblioteca para ler a entrada do usuário.

//Inicializar a classe com o mesmo nome que foi salvo no arquivo.
 class Exercicio8 {
    public static void main (String[] args) { //Método principal onde o programa começa a execução.
        //Inicializar variáveis.
        int num; 
        Scanner sc = new Scanner(System.in); //Criar um objeto Scanner para ler a entrada do usuário. (como se fosse um scanf em C).

        //Ler um número inteiro do usuário e armazená-lo na variável num.
        System.out.print("Digite um numero: "); 
        num = sc.nextInt(); //O próximo inteiro informado pelo usuário será armazenado em num.

        //Verificar se o número é positivo ou negativo usando uma estrutura de controle if-else e imprimir o resultado.
        if (num < 0) {
            System.out.println("O numero "+num+" e negativo.");
        }
        else {
            System.out.println("O numero "+num+" e positivo.");
        }

        //Fechar o scanner para evitar vazamento de memória.
        sc.close();
    }
}
