//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

//Biblioteca para ler a entrada do usuário. 
import java.util.Scanner; 

//Classe para verificar se uma string é um palíndromo. 
class palindromo {
    //Método para verificar se uma string é um palíndromo, que recebe a string como parâmetro e retorna um booleano.
    public static void main (String[] args) {
        //Criar um objeto Scanner para ler a entrada do usuário. 
        Scanner sc = new Scanner (System.in); 

        //Variável para armazenar a string de entrada do usuário.
        String texto = sc.nextLine();
        
        //Loop para ler as linhas de entrada do usuário até que a palavra "FIM" seja digitada. 
        do {
            int ehPalindromo = 1; //1 = sim, 0 = não
            
            for (int i = 0; i < texto.length() / 2 && ehPalindromo == 1; i++) {
                //Verificar cada caractere da string. 
                if (texto.charAt(i) != texto.charAt(texto.length() - 1 - i)) { //Comparar o caractere na posição i com o caractere na posição oposta (texto.length() - 1 - i).
                    ehPalindromo = 0; //Não é palíndromo
                }
            }
            
            if (ehPalindromo == 1) {
                System.out.println("SIM"); //Se os caracteres forem iguais, imprimir "SIM" indicando que a string é um palíndromo.
            } else {
                System.out.println("NAO"); //Se os caracteres forem diferentes, imprimir "NAO" indicando que a string não é um palíndromo.
            }
            
            texto = sc.nextLine(); //Ler próxima linha
        } while (!texto.equals("FIM"));

        //Fechhar o scanner para evitar vazamento de memória.
        sc.close(); //Fechar o scanner para evitar vazamento de memória.}
    }
}
