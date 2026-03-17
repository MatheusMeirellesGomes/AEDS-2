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
        Scanner sc = new Scanner(System.in); 

        while (sc.hasNextLine()) {
            String linha = sc.nextLine(); 
            String LinhaCifrada = ciframento(linha); 

            System.out.println(LinhaCifrada);
        }

        sc.close(); 
    }
}
