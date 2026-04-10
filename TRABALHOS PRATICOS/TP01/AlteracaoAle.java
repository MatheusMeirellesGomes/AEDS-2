//Método iterativo que recebe uma string, sorteia duas letras minúsculas aleatórias, substitui todas as ocorrências da primeira letra 
//pela segunda e retorna a string com as alterações efetuadas. Na saída padrão, para cada linha de entrada, execute o método desenvolvido 
//e mostre a string retornada como uma linha de saída. 
//Obs: Usar classe Random, destacando seed como semente para a geração de números aleatórios, nesta questão, por causa da correção automática 
//o seed será 4. As entradas vem do arquivo de texto pub.in e termina quando a string lida for igual a "FIM". As saídas devem ser escritas em um arquivo de texto pub.out.

import java.util.Scanner; 
import java.util.Random; 

//Classe principal do programa. 
class AlteracaoAle {
    //Primeiro criar a função para verificar se a string lida é igual a "FIM".
    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    //Criar o método para realizar a alteração aleatória. 
    public static String alteracaoAle (String str, Random rand) { // Criar um função que retorna uma string e receba uma string como parâmetro. 
        //Criar uma string vazia para armazenar a string depois de alterada.
        String alterada = ""; 

        //Gerar duas letras minúsculas aleatórias. 
        char letra1 = (char)('a' + (Math.abs(rand.nextInt()) % 26)); //Gerar a primeira letra aleatória, usando o método nextInt da classe Random para gerar um número entre 0 e 25, e somando com o valor ASCII da letra 'a' para obter uma letra minúscula.
        char letra2 = (char)('a' + (Math.abs(rand.nextInt()) % 26)); //Gerar a segunda letra aleatória da mesma forma.

        //Loop para percorrer cada caracter da string de entrada. 
        for (int i = 0; i < str.length(); i++) {
            //Indicar que o caracter atual é o caracter na posição i da string de entrada.
            char caracter = str.charAt(i); 

            //Verificar se o caracter atual é igual à primeira letra aleatória.
            if (caracter == letra1) {
                //Se for igual, adicionar a segunda letra aleatória à string alterada.
                alterada += letra2;
            } else {
                //Se não for igual, adicionar o caracter atual à string alterada.
                alterada += caracter;
            }
        }

        return alterada;
    }

    //Método principal do programa.
    public static void main (String [] args) {
        //Criar um objeto Random para gerar números aleatórios, usando o seed 4.
        Random rand = new Random();
        rand.setSeed(4);


        //Criar um objeto Scanner para ler a entrada do arquivo de texto pub.in
        Scanner sc = new Scanner (System.in); 

        //Ler a primeira linha do arquivo de texto pub.in
        String linha = sc.nextLine(); 

        //Continuar lendo cada linha do arquivo, enquanto a linha lida nao for "FIM".
        while (!isFim(linha)) {
            //Chamar o método de alteração aleatória para alterar a linha lida. 
            String linhaAlterada = alteracaoAle(linha, rand);

            //Imprimir a linha alterada.
            System.out.println(linhaAlterada); 

            //Ler a próxima linha para a próxima iteração do loop.
            linha = sc.nextLine();
        }

        //Fechar o objeto Scanner. 
        sc.close();
    }
}