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
        //Scanner. 
        Scanner sc = new Scanner(System.in); 

        //Loop. 
        while (sc.hasNext()) {
            //Ler o próximo número da entrada.
            int n = sc.nextInt();

            //Chamar a soma dos dígitos, 
            int resultado = SomaDigitos(n); 

            //Imprimir resultado da soma. 
            System.out.println(resultado);
        }

        //Fechar scanner. 
        sc.close();
    }
}