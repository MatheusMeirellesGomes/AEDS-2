//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

import java.util.Scanner; 

//Classe Principal. 
class Palindromo {
   //Verifica FIM. 
   public static boolean isFim (String str) {
    return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
   }

   //Verifica se é palíndromo. 
   public static boolean isPalindromo (String str) {
    //Inicializar o tamanho.
    int n = str.length();
    //Loop. 
    for (int i = 0; i < n / 2; i++) {
        //Verificar o caractere atual com o caractere correspondente do final da string.
        if (str.charAt(i) != str.charAt(n - i - 1)) {
            return false;
        }
    }
    return true;
   }

   //Função principal.
   public static void main (String[] args) {
    //Incializar variável. 
    String str; 

    Scanner sc = new Scanner(System.in); //Leitura. 

    //Ler a primeira entrada. 
    str = sc.nextLine(); 

    //Loop. 
    while (!isFim(str)) {
        //Verificar se é palíndromo. 
        if (isPalindromo(str)) {
            System.out.println("SIM"); //Imprime SIM se for palíndromo. 
        } else {
            System.out.println("NAO"); //Imprime NAO se não for palíndromo. 
        }

        //Continua lendo. 
        str = sc.nextLine(); 
    }

    sc.close(); //Fechar scanner.
   }
}
