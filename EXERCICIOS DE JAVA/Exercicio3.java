import java.util.Scanner; //Biblioteca para ler a entrada do usuário.

//Este exercício é para ler dois números inteiros do usuário, somá-los e imprimir o resultado.
public class Exercicio3 { //Inicializar a classe com o mesmo nome que foi salvo no arquivo.
    public static void main(String[] args) { //Método principal onde o programa começa a execução.
        Scanner sc = new Scanner(System.in); //Criar um objeto Scanner para ler a entrada do usuário. (como se fosse um scanf em C).

        //Ler dois números inteiros do usuário e armazená-los nas variáveis x e y.
        int x = sc.nextInt(); //O próximo inteiro informado pelo usuário será armazenado em x.
        int y = sc.nextInt(); //O próximo inteiro informado pelo usuário será armazenado em y.

        //Imprimir a soma de x e y.
        System.out.println(x + y); //A soma já é calculada dentro do println, como se fosse um printf em C.

        //Fechar o scanner para evitar vazamento de memória.
        sc.close();
    }
}
