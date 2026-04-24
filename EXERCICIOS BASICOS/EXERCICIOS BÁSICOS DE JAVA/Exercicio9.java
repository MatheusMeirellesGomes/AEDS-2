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

    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //Inicializar variável para receber a string do usuário
        String linha = sc.nextLine(); 

        //Loop para ler as strings até que seja digitada a string "FIM"
        while (!isFim(linha)) {
            //Chamar o método de ciframento e imprimir o resultado
            String resultado = ciframento(linha);
            System.out.println(resultado);

            //Ler a próxima string
            linha = sc.nextLine();
        }

        sc.close(); 
    }
}
