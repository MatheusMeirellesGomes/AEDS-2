import java.util.Scanner; 

class Exercicio6 {
    public static void main (String[] args) {
        String nome; 
        int idade; 
        float altura; 
        
        Scanner sc = new Scanner(System.in); 

        System.out.print("Informe seu nome: "); 
        nome = sc.nextLine(); 
        System.out.print("Informe sua idade: "); 
        idade = sc.nextInt(); 
        System.out.print("Informe sua altura: "); 
        altura = sc.nextFloat(); 

        System.out.println(nome+"tem "+idade+" anos e mede "+altura+" metros de altura."); 
        
        sc.close(); 
    }
}