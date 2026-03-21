/*Crie um método iterativo que receba uma string como parâmetro e retorne true se a string é uma senha válida, ou false caso contrário.
Uma senha é considerada válida quando tem pelo menos 8 caracteres, incluindo pelo menos uma letra maiuscula, uma letra minuscula, um número
e um caractere especial. Na saída padrão, para cada linha  de entrada, escreva uma linha de saida com SIM/NAO, incluindo se a senha é válida
Ex: Se a entrada for "Senha123!", a saída deve ser "SIM" */

import java.util.Scanner; 

//Casse principal. 
class ValidacaoSenha {
    //Método para verificar se é FIM. 
    public static boolean isFim(String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    //Método para ver se tem letra maiúscula.
    public static boolean temMaiuscula(String str) {
        //Loop. 
        for (int i = 0; i < str.length(); i++) {
            char caractere = str.charAt(i); //Pega o caractere da posição i.

            //Verificar se o caractere é maiúsculo.
            if (caractere >= 'A' && caractere <= 'Z') {
                return true; //Retorna true se tiver letra maiúscula.
            }
        }
        return false; //Retorna false se não tiver letra maiúscula.
    }

    //Verificar letra minúscula. 
    public static boolean temMinuscula(String str) {
        //Loop. 
        for (int i = 0; i < str.length(); i++) {
            //Caractere da posição i.
            char caractere = str.charAt(i); 

            //Verificar se o caractere é minusculo.
            if (caractere >= 'a' && caractere <= 'z') {
                return true; //Retorna true se tiver letra minúscula.   
            }
        }
        
        return false; //Retorna false se não tiver letra minúscula.
    }

    //Verificar se têm número. 
    public static boolean temNumero (String str) {
        //Loop. 
        for (int i = 0; i < str.length(); i++) {
            //Caractere da posição i. 
            char caractere = str.charAt(i); 

            //Verificar se o caractere é um número. 
            if (caractere >= '0' && caractere <= '9') {
                return true; //Retorna true se tiver número. 
            }
        }
        
        return false; //Retorna false se não tiver número.
    }

    //Verificar se têm caractere especial.
    public static boolean temEspecial (String str) {
        //Loop. 
        for (int i = 0; i < str.length(); i++) {
            //Caractere da posição i. 
            char caractere = str.charAt(i); 

            //Verificar se o caractere é um caractere especial. 
            if ((caractere >= '!' && caractere <= '/') || (caractere >= ':' && caractere <= '@') || (caractere >= '[' && caractere <= '`') || (caractere >= '{' && caractere <= '~')) {
                return true; //Retorna true se tiver caractere especial. 
            }
        }
        
        return false; //Retorna false se não tiver caractere especial.
    }

    //Verificar se a senha é valida. 
    public static boolean isValida (String str) {
        //Verificar se é válida a senha com todas as condições. 
        if (str.length() >= 8 && temMaiuscula(str) && temMinuscula(str) && temNumero(str) && temEspecial(str)) {
            return true; //Retorna true se a senha for válida. 
        }
        
        return false; //Retorna false se a senha não for válida.
    }

    //Main. 
    public static void main (String [] args) {
        //Objeto Scanner. 
        Scanner sc = new Scanner (System.in); 

        //Ler a primeira entrada. 
        String linha = sc.nextLine(); 

        //Loop. 
        while (!isFim(linha)) {
            //Verificar se a senha é válida. 
            if (isValida(linha)) {
                System.out.println("SIM"); //Imprime 'SIM' conforme o enunciado. 
            }
            else {
                System.out.println("NAO"); //Imprime 'NAO' conforme o enunciado.
            }

            //Ler a próxima entrada. 
            linha = sc.nextLine(); 
        }

        //Fechar o Scanner. 
        sc.close();
    }
}