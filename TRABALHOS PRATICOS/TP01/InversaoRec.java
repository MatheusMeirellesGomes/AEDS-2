//Refazer a questão de Inversao.c porém agora usando recursão e em java. 

import java.util.Scanner; 

class InversaoRec {
    //IsFim
    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' &&  str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    //Recursão. 
    public static String inversao (String str, int i) {
        //Caso base. 
        if (i == 0) return ""; //Tamanho zero, string vazia. 

        //Chamada da função. 
        return str.charAt(i - 1) + inversao(str, i - 1); //Pega o último caractere e chama a função com o restante da string.
    }

    //main. 
    public static void main (String[] args) {
        //Inicializar variável e scanner. 
        String str = "";
        Scanner sc = new Scanner(System.in); 

        //Leitura da primeira string.
        str = sc.nextLine(); 

        //Enquanto não for FIM. 
        while (!isFim(str)) {
            //Chamada da função. 
            str = inversao(str, str.length());

            //Imprimir resultado. 
            System.out.println(str);

            //Ler a próxima string. 
            str = sc.nextLine();
        }

        //Fechar scanner. 
        sc.close();
    }
}