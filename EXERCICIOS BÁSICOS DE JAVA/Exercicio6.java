//Exercicio para ler o nome, idade e altura de uma pessoa e imprimir essas informações formatadas. 
import java.util.Scanner; //Biblioteca para ler a entrada do usuário.

//Inicializar a classe com o mesmo nome que foi salvo no arquivo. 
class Exercicio6 {
    //Método principal onde o programa começa com a execução. 
    public static void main (String[] args) { //Declarar as variáveis para armazenar o nome, idade e altura da pessoa. 
        //Inicializar variáveis. 
        String nome; 
        int idade; 
        float altura; 
        
        //Criar um objeto Scanner para ler a entrada do usuário. (como se fosse um scanf em C). 
        Scanner sc = new Scanner(System.in); 

        //Ler o nome, idade e altura da pessoa do usuário e armazená-los nas variáveis correspondentes. 
        System.out.print("Informe seu nome: "); 
        nome = sc.nextLine(); 
        System.out.print("Informe sua idade: "); 
        idade = sc.nextInt(); 
        System.out.print("Informe sua altura: "); 
        altura = sc.nextFloat(); 

        //Imprimir as informações formatadas usando a forma correta de impressão em java. 
        System.out.println(nome+"tem "+idade+" anos e mede "+altura+" metros de altura."); 
        
        //Fechar o scanner para evitar vazamento de memória.
        sc.close(); 
    }
}