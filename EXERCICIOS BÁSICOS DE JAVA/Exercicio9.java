//Mesmo exercício do ciframento de césar, porém agora recebendo entrada do teclado. 
import java.util.Scanner; 

class Ciframento{
    public static String ciframento (String str) {
        String cifrada = ""; 

        for (int i = 0; i < str.length(); i++) {
            char caracter = str.charAt(i); 
            char novoCaracter = (char) (caracter + 3); 
            cifrada += novoCaracter; 
        }

        return cifrada; 
    }

    public static void main(String[] args) {
        //Inicializar variável para receber a string do usuário
        String str; 

        //Criar objeto Scanner para ler a entrada do usuário
        Scanner sc = new Scanner(System.in);

        //Ler a string digitalizada pelo usuário
        str = sc.nextLine();

        //Chamar o método de ciframento e imprimir o resultado
        String resultado = ciframento(str);

        System.out.println(resultado);

        sc.close(); 
    }
}
