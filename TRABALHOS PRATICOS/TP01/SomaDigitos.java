//Mesma questão do SomaDigitos.c, porém agora usando recursão e em java.

import java.util.Scanner; 

class SomaDigitos {
    //isFim. A string precisa ser diferente de FIM. 
    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'); 
    }

    //Converter numero para inteiro. 
    public static int converte (String str) {
        //Inicializar posição. 
        int num = 0; 

        //Loop para percorrer até o tamanho da string. 
        for (int i = 0; i < str.length(); i++) {
            num = num * 10 + str.charAt(i) - '0'; 
        }

        //Retornar o número como inteiro. 
        return num; 
    }

    //Recursão. 
    public static int SomaDigitos (int num) {
        //Caso base
        if (num == 0) return 0; 

        //Recursão. 
        return (num % 10) + SomaDigitos(num / 10); 
    }

    //Main. 
    public static void main (String[] args) {
        //Inicializar uma variável como string para leitura e outra como inteiro para receber a conversão. 
        String str;
        int n; 
        
        Scanner sc = new Scanner(System.in); 

        //Leitura da primeira string. 
        str = sc.nextLine(); 

        while (!isFim(str)) {
            //Chamar o método de conversão de string para inteiro. 
            n = converte(str); 

            //Chamar a soma dos dígitos, 
            int resultado = SomaDigitos(n); 

            //Imprimir resultado da soma. 
            System.out.println(resultado);

            //Leitura da proxima string. 
            str = sc.nextLine(); 
        }

        //Fechar scanner. 
        sc.close();
    }
}