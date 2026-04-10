//Mesma questão do SomaDigitos.c, porém agora usando recursão e em java.

import java.util.Scanner; 

class SomaDigitos {
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
        int n; 
        
        Scanner sc = new Scanner(System.in); 

        //Loop. 
        while (sc.hasNext()) {
            //Chamar a soma dos dígitos, 
            int resultado = SomaDigitos(n); 

            //Imprimir resultado da soma. 
            System.out.println(resultado);

            //Leitura da proxima string. 
            n = sc.nextInt(); 
        }

        //Fechar scanner. 
        sc.close();
    }
}