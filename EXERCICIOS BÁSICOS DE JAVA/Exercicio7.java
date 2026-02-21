 //Exercicio para realizar operações aritméticas básicas entre dois números inteiros.
 class Exercicio7 {
    //Método principal onde o programa começa a execução.
    public static void main (String[] args) { //Declarar e inicializar as variáveis para os dois números inteiros e para os resultados das operações.
        //Inicializar variáveis.
        int a = 5, b = 3; 
        int soma, subt, mult, div, quoc, resto, inc, dec; 
        float divsao; 

        //Realizar as operações aritméticas básicas entre os dois números inteiros e armazenar os resultados nas variáveis correspondentes.
        soma = a + b; 
        System.out.println(a+ " + "+b+" = "+soma);
        subt = a - b; 
        System.out.println(a+ " - "+b+" = "+subt);
        mult = a * b;
        System.out.println(a+ " * "+b+" = "+mult);
        div = a / b;
        System.out.println(a+ " / "+b+" = "+div);
        divsao = (float) a / b;
        System.out.println(a+ " / "+b+" = "+divsao);
        quoc = a / b;
        System.out.println(a+ " / "+b+" = "+quoc);
        resto = a % b;
        System.out.println(a+ " % "+b+" = "+resto);
        inc = a++;
        System.out.println(a+ " + 1 = "+inc);
        dec = a--;
        System.out.println(a+ " - 1 = "+dec);
    }
}
