//Crie um método que receba uma string como parâmetro e retorne true se ela for um palíndromo. Na saída padrão, para cada linha de entrada, escreva
//uma linha com SIM/NÃO indicando se a linha é um palíndromo ou não. Destaca-se que uma linha de entrada pode ter caracteres e não letras. 
//A entrada termina quando for lida uma linha contendo apenas a palavra FIM.

//Biblioteca para ler a entrada do usuário. 
import java.util.Scanner; 

//Classe para verificar se uma string é um palíndromo. 
class Palindromo {
    //Método para verificar se uma string é um palíndromo, que recebe a string como parâmetro e retorna um booleano.
    public static void main (String[] args) {
        //Criar um objeto Scanner para ler a entrada do usuário. 
        Scanner sc = new Scanner (System.in); 

        //Variável para armazenar a string de entrada do usuário.
        String texto = sc.nextLine();
        
        //Loop para ler as linhas de entrada do usuário até que a palavra "FIM" seja digitada. 
        do { //O loop irá fazer até que a string de entrada seja igual a "FIM".
            //Variável para indicar se a string é um palíndromo ou não.    
            int ehPalindromo = 1; //1 = sim, 0 = não
            
            //Loop para verificar se a string é um palíndromo, comparando os caracteres da string. O loop percorre a string até a metade, comparando o caractere na posição i com o caractere na posição oposta (texto.length() - 1 - i). Se os caracteres forem diferentes, a variável ehPalindromo é setada para 0, indicando que a string não é um palíndromo.
            for (int i = 0; i < texto.length() / 2 && ehPalindromo == 1; i++) { //Divive o comprimento da string por 2 para comparar apenas até a metade da string, e o loop continua enquanto ehPalindromo for igual a 1 (ou seja, enquanto a string ainda pode ser um palíndromo).
                //Verificar cada caractere da string. 
                if (texto.charAt(i) != texto.charAt(texto.length() - 1 - i)) { //Se o caractere na posição i for diferente do caractere na posição oposta (texto.length() - 1 - i), então a string não é um palíndromo.
                    ehPalindromo = 0; //Não é palíndromo
                }
            }
            
            //Verificar se a string é um palíndromo ou não, se for um palíndromo, imprimir "SIM", caso contrário, imprimir "NAO".
            if (ehPalindromo == 1) {
                System.out.println("SIM"); //Se os caracteres forem iguais, imprimir "SIM" indicando que a string é um palíndromo.
            } else {
                System.out.println("NAO"); //Se os caracteres forem diferentes, imprimir "NAO" indicando que a string não é um palíndromo.
            }
            
            //Ler a próxima linha de entrada do usuário para verificar se é um palíndromo ou se é a palavra "FIM" para encerrar o loop.
            texto = sc.nextLine(); //Ler próxima linha
            //Enquanto o texto de entrada for diferente de "FIM", o loop continuará rodando o que está dentro do do... 
        } while (!texto.equals("FIM")); //Usar o método equals para comparar a string de entrada com a palavra "FIM". O loop continua enquanto as strings forem diferentes.

        //Fechhar o scanner para evitar vazamento de memória.
        sc.close(); //Fechar o scanner para evitar vazamento de memória.}
    }
}
